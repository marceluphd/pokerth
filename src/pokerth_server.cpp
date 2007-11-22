/***************************************************************************
 *   Copyright (C) 2007 by Lothar May                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <iostream>

#include "session.h"
#include "configfile.h"
#include <gui/generic/serverguiwrapper.h>
#include <net/socket_startup.h>
#include <core/loghelper.h>
#include <core/thread.h>

#include <csignal>

#ifdef _MSC_VER
	#ifdef _DEBUG
		#define _CRTDBG_MAP_ALLOC
		#include <crtdbg.h>

		#define ENABLE_LEAK_CHECK() \
			{ \
				int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG); \
				tmpFlag |= _CRTDBG_LEAK_CHECK_DF; \
				_CrtSetDbgFlag(tmpFlag); \
			}
	#endif
#endif

#ifndef ENABLE_LEAK_CHECK
	#define ENABLE_LEAK_CHECK()
#endif

using namespace std;

volatile int g_pokerthTerminate = 0;

void
TerminateHandler(int /*signal*/)
{
	g_pokerthTerminate = 1;
}

// TODO: Hack
#ifndef _WIN32
	#include <unistd.h>
	#ifndef daemon
		int daemon(int, int);
	#endif
#endif

int
main(int argc, char *argv[])
{
	ENABLE_LEAK_CHECK();

//	_CrtSetBreakAlloc(4772);

	//create defaultconfig
	ConfigFile *myConfig = new ConfigFile(argc, argv);
	loghelper_init(myConfig->readConfigString("LogDir"));

	// TODO: Hack
#ifndef _WIN32
	daemon(0, 0);
#endif

	signal(SIGTERM, TerminateHandler);
	signal(SIGINT, TerminateHandler);

	socket_startup();

	LOG_MSG("Starting PokerTH dedicated server. Availability: IPv6 "
		<< socket_has_ipv6() << ", SCTP " << socket_has_sctp() << ", Dual Stack " << socket_has_dual_stack() << ".");

	// Create pseudo Gui Wrapper for the server.
	boost::shared_ptr<GuiInterface> myServerGuiInterface(new ServerGuiWrapper(myConfig, NULL, NULL, NULL));
	boost::shared_ptr<Session> session(new Session(myServerGuiInterface.get(), myConfig));
	if (!session->init())
		LOG_ERROR("Missing files - please check your directory settings!");
	myServerGuiInterface->setSession(session);

	myServerGuiInterface->getSession().startNetworkServer();
	while (!g_pokerthTerminate)
	{
		Thread::Msleep(100);
		if (myServerGuiInterface->getSession().pollNetworkServerTerminated())
			g_pokerthTerminate = true;
	}
	myServerGuiInterface->getSession().terminateNetworkServer();

	LOG_MSG("Terminating PokerTH dedicated server." << endl);
	socket_cleanup();
	return 0;
}

