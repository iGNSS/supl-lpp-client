/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "SUPL-REPORT"
 * 	found in "/home/martin/repos/LPP-Client/asn/SUPL.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#include "Ver2-SUPLREPORT.h"

asn_TYPE_member_t asn_MBR_Ver2_SUPLREPORT_1[] = {
	{ ATF_POINTER, 5, offsetof(struct Ver2_SUPLREPORT, sessionList),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SessionList,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"sessionList"
		},
	{ ATF_POINTER, 4, offsetof(struct Ver2_SUPLREPORT, sETCapabilities),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SETCapabilities,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"sETCapabilities"
		},
	{ ATF_POINTER, 3, offsetof(struct Ver2_SUPLREPORT, reportDataList),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ReportDataList,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"reportDataList"
		},
	{ ATF_POINTER, 2, offsetof(struct Ver2_SUPLREPORT, ver),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Ver,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ver"
		},
	{ ATF_POINTER, 1, offsetof(struct Ver2_SUPLREPORT, moreComponents),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NULL,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"moreComponents"
		},
};
static const int asn_MAP_Ver2_SUPLREPORT_oms_1[] = { 0, 1, 2, 3, 4 };
static const ber_tlv_tag_t asn_DEF_Ver2_SUPLREPORT_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_Ver2_SUPLREPORT_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* sessionList */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* sETCapabilities */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* reportDataList */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* ver */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 } /* moreComponents */
};
asn_SEQUENCE_specifics_t asn_SPC_Ver2_SUPLREPORT_specs_1 = {
	sizeof(struct Ver2_SUPLREPORT),
	offsetof(struct Ver2_SUPLREPORT, _asn_ctx),
	asn_MAP_Ver2_SUPLREPORT_tag2el_1,
	5,	/* Count of tags in the map */
	asn_MAP_Ver2_SUPLREPORT_oms_1,	/* Optional members */
	5, 0,	/* Root/Additions */
	5,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_Ver2_SUPLREPORT = {
	"Ver2-SUPLREPORT",
	"Ver2-SUPLREPORT",
	&asn_OP_SEQUENCE,
	asn_DEF_Ver2_SUPLREPORT_tags_1,
	sizeof(asn_DEF_Ver2_SUPLREPORT_tags_1)
		/sizeof(asn_DEF_Ver2_SUPLREPORT_tags_1[0]), /* 1 */
	asn_DEF_Ver2_SUPLREPORT_tags_1,	/* Same as above */
	sizeof(asn_DEF_Ver2_SUPLREPORT_tags_1)
		/sizeof(asn_DEF_Ver2_SUPLREPORT_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_Ver2_SUPLREPORT_1,
	5,	/* Elements count */
	&asn_SPC_Ver2_SUPLREPORT_specs_1	/* Additional specs */
};

