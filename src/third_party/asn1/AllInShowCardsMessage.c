/*
 * Generated by asn1c-0.9.22 (http://lionet.info/asn1c)
 * From ASN.1 module "POKERTH-PROTOCOL"
 * 	found in "../../../docs/pokerth.asn1"
 */

#include <asn_internal.h>

#include "AllInShowCardsMessage.h"

static int
memb_playersAllIn_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	size_t size;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Determine the number of elements */
	size = _A_CSEQUENCE_FROM_VOID(sptr)->count;
	
	if((size >= 1 && size <= 10)) {
		/* Perform validation of the inner elements */
		return td->check_constraints(td, sptr, ctfailcb, app_key);
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_TYPE_member_t asn_MBR_playersAllIn_3[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_PlayerAllIn,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		""
		},
};
static ber_tlv_tag_t asn_DEF_playersAllIn_tags_3[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_playersAllIn_specs_3 = {
	sizeof(struct playersAllIn),
	offsetof(struct playersAllIn, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_playersAllIn_3 = {
	"playersAllIn",
	"playersAllIn",
	SEQUENCE_OF_free,
	SEQUENCE_OF_print,
	SEQUENCE_OF_constraint,
	SEQUENCE_OF_decode_ber,
	SEQUENCE_OF_encode_der,
	SEQUENCE_OF_decode_xer,
	SEQUENCE_OF_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_playersAllIn_tags_3,
	sizeof(asn_DEF_playersAllIn_tags_3)
		/sizeof(asn_DEF_playersAllIn_tags_3[0]), /* 1 */
	asn_DEF_playersAllIn_tags_3,	/* Same as above */
	sizeof(asn_DEF_playersAllIn_tags_3)
		/sizeof(asn_DEF_playersAllIn_tags_3[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_playersAllIn_3,
	1,	/* Single element */
	&asn_SPC_playersAllIn_specs_3	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_AllInShowCardsMessage_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct AllInShowCardsMessage, gameId),
		(ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
		0,
		&asn_DEF_NonZeroId,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"gameId"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct AllInShowCardsMessage, playersAllIn),
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_playersAllIn_3,
		memb_playersAllIn_constraint_1,
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"playersAllIn"
		},
};
static ber_tlv_tag_t asn_DEF_AllInShowCardsMessage_tags_1[] = {
	(ASN_TAG_CLASS_APPLICATION | (24 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_AllInShowCardsMessage_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 0, 0, 0 }, /* gameId at 388 */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 1, 0, 0 } /* playersAllIn at 390 */
};
static asn_SEQUENCE_specifics_t asn_SPC_AllInShowCardsMessage_specs_1 = {
	sizeof(struct AllInShowCardsMessage),
	offsetof(struct AllInShowCardsMessage, _asn_ctx),
	asn_MAP_AllInShowCardsMessage_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	1,	/* Start extensions */
	3	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_AllInShowCardsMessage = {
	"AllInShowCardsMessage",
	"AllInShowCardsMessage",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_AllInShowCardsMessage_tags_1,
	sizeof(asn_DEF_AllInShowCardsMessage_tags_1)
		/sizeof(asn_DEF_AllInShowCardsMessage_tags_1[0]) - 1, /* 1 */
	asn_DEF_AllInShowCardsMessage_tags_1,	/* Same as above */
	sizeof(asn_DEF_AllInShowCardsMessage_tags_1)
		/sizeof(asn_DEF_AllInShowCardsMessage_tags_1[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_AllInShowCardsMessage_1,
	2,	/* Elements count */
	&asn_SPC_AllInShowCardsMessage_specs_1	/* Additional specs */
};

