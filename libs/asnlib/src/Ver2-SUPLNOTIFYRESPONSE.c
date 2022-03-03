/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "SUPL-NOTIFY-RESPONSE"
 * 	found in "/home/martin/repos/LPP-Client/asn/SUPL.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#include "Ver2-SUPLNOTIFYRESPONSE.h"

asn_TYPE_member_t asn_MBR_Ver2_SUPLNOTIFYRESPONSE_1[] = {
	{ ATF_POINTER, 1, offsetof(struct Ver2_SUPLNOTIFYRESPONSE, notificationResponse),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NotificationResponse,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"notificationResponse"
		},
};
static const int asn_MAP_Ver2_SUPLNOTIFYRESPONSE_oms_1[] = { 0 };
static const ber_tlv_tag_t asn_DEF_Ver2_SUPLNOTIFYRESPONSE_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_Ver2_SUPLNOTIFYRESPONSE_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* notificationResponse */
};
asn_SEQUENCE_specifics_t asn_SPC_Ver2_SUPLNOTIFYRESPONSE_specs_1 = {
	sizeof(struct Ver2_SUPLNOTIFYRESPONSE),
	offsetof(struct Ver2_SUPLNOTIFYRESPONSE, _asn_ctx),
	asn_MAP_Ver2_SUPLNOTIFYRESPONSE_tag2el_1,
	1,	/* Count of tags in the map */
	asn_MAP_Ver2_SUPLNOTIFYRESPONSE_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_Ver2_SUPLNOTIFYRESPONSE = {
	"Ver2-SUPLNOTIFYRESPONSE",
	"Ver2-SUPLNOTIFYRESPONSE",
	&asn_OP_SEQUENCE,
	asn_DEF_Ver2_SUPLNOTIFYRESPONSE_tags_1,
	sizeof(asn_DEF_Ver2_SUPLNOTIFYRESPONSE_tags_1)
		/sizeof(asn_DEF_Ver2_SUPLNOTIFYRESPONSE_tags_1[0]), /* 1 */
	asn_DEF_Ver2_SUPLNOTIFYRESPONSE_tags_1,	/* Same as above */
	sizeof(asn_DEF_Ver2_SUPLNOTIFYRESPONSE_tags_1)
		/sizeof(asn_DEF_Ver2_SUPLNOTIFYRESPONSE_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_Ver2_SUPLNOTIFYRESPONSE_1,
	1,	/* Elements count */
	&asn_SPC_Ver2_SUPLNOTIFYRESPONSE_specs_1	/* Additional specs */
};

