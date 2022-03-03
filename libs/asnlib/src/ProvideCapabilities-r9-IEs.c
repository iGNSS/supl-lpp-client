/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LPP-PDU-Definitions"
 * 	found in "/home/martin/repos/LPP-Client/asn/LPP.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#include "ProvideCapabilities-r9-IEs.h"

static asn_TYPE_member_t asn_MBR_ext1_8[] = {
	{ ATF_POINTER, 4, offsetof(struct ProvideCapabilities_r9_IEs__ext1, sensor_ProvideCapabilities_r13),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Sensor_ProvideCapabilities_r13,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"sensor-ProvideCapabilities-r13"
		},
	{ ATF_POINTER, 3, offsetof(struct ProvideCapabilities_r9_IEs__ext1, tbs_ProvideCapabilities_r13),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TBS_ProvideCapabilities_r13,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"tbs-ProvideCapabilities-r13"
		},
	{ ATF_POINTER, 2, offsetof(struct ProvideCapabilities_r9_IEs__ext1, wlan_ProvideCapabilities_r13),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_WLAN_ProvideCapabilities_r13,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"wlan-ProvideCapabilities-r13"
		},
	{ ATF_POINTER, 1, offsetof(struct ProvideCapabilities_r9_IEs__ext1, bt_ProvideCapabilities_r13),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BT_ProvideCapabilities_r13,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"bt-ProvideCapabilities-r13"
		},
};
static const int asn_MAP_ext1_oms_8[] = { 0, 1, 2, 3 };
static const ber_tlv_tag_t asn_DEF_ext1_tags_8[] = {
	(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_ext1_tag2el_8[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* sensor-ProvideCapabilities-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* tbs-ProvideCapabilities-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* wlan-ProvideCapabilities-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* bt-ProvideCapabilities-r13 */
};
static asn_SEQUENCE_specifics_t asn_SPC_ext1_specs_8 = {
	sizeof(struct ProvideCapabilities_r9_IEs__ext1),
	offsetof(struct ProvideCapabilities_r9_IEs__ext1, _asn_ctx),
	asn_MAP_ext1_tag2el_8,
	4,	/* Count of tags in the map */
	asn_MAP_ext1_oms_8,	/* Optional members */
	4, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ext1_8 = {
	"ext1",
	"ext1",
	&asn_OP_SEQUENCE,
	asn_DEF_ext1_tags_8,
	sizeof(asn_DEF_ext1_tags_8)
		/sizeof(asn_DEF_ext1_tags_8[0]) - 1, /* 1 */
	asn_DEF_ext1_tags_8,	/* Same as above */
	sizeof(asn_DEF_ext1_tags_8)
		/sizeof(asn_DEF_ext1_tags_8[0]), /* 2 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_ext1_8,
	4,	/* Elements count */
	&asn_SPC_ext1_specs_8	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_ext2_13[] = {
	{ ATF_POINTER, 5, offsetof(struct ProvideCapabilities_r9_IEs__ext2, nr_ECID_ProvideCapabilities_r16),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NR_ECID_ProvideCapabilities_r16,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"nr-ECID-ProvideCapabilities-r16"
		},
	{ ATF_POINTER, 4, offsetof(struct ProvideCapabilities_r9_IEs__ext2, nr_Multi_RTT_ProvideCapabilities_r16),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NR_Multi_RTT_ProvideCapabilities_r16,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"nr-Multi-RTT-ProvideCapabilities-r16"
		},
	{ ATF_POINTER, 3, offsetof(struct ProvideCapabilities_r9_IEs__ext2, nr_DL_AoD_ProvideCapabilities_r16),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NR_DL_AoD_ProvideCapabilities_r16,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"nr-DL-AoD-ProvideCapabilities-r16"
		},
	{ ATF_POINTER, 2, offsetof(struct ProvideCapabilities_r9_IEs__ext2, nr_DL_TDOA_ProvideCapabilities_r16),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NR_DL_TDOA_ProvideCapabilities_r16,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"nr-DL-TDOA-ProvideCapabilities-r16"
		},
	{ ATF_POINTER, 1, offsetof(struct ProvideCapabilities_r9_IEs__ext2, nr_UL_ProvideCapabilities_r16),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NR_UL_ProvideCapabilities_r16,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"nr-UL-ProvideCapabilities-r16"
		},
};
static const int asn_MAP_ext2_oms_13[] = { 0, 1, 2, 3, 4 };
static const ber_tlv_tag_t asn_DEF_ext2_tags_13[] = {
	(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_ext2_tag2el_13[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* nr-ECID-ProvideCapabilities-r16 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* nr-Multi-RTT-ProvideCapabilities-r16 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* nr-DL-AoD-ProvideCapabilities-r16 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* nr-DL-TDOA-ProvideCapabilities-r16 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 } /* nr-UL-ProvideCapabilities-r16 */
};
static asn_SEQUENCE_specifics_t asn_SPC_ext2_specs_13 = {
	sizeof(struct ProvideCapabilities_r9_IEs__ext2),
	offsetof(struct ProvideCapabilities_r9_IEs__ext2, _asn_ctx),
	asn_MAP_ext2_tag2el_13,
	5,	/* Count of tags in the map */
	asn_MAP_ext2_oms_13,	/* Optional members */
	5, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ext2_13 = {
	"ext2",
	"ext2",
	&asn_OP_SEQUENCE,
	asn_DEF_ext2_tags_13,
	sizeof(asn_DEF_ext2_tags_13)
		/sizeof(asn_DEF_ext2_tags_13[0]) - 1, /* 1 */
	asn_DEF_ext2_tags_13,	/* Same as above */
	sizeof(asn_DEF_ext2_tags_13)
		/sizeof(asn_DEF_ext2_tags_13[0]), /* 2 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_ext2_13,
	5,	/* Elements count */
	&asn_SPC_ext2_specs_13	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_ProvideCapabilities_r9_IEs_1[] = {
	{ ATF_POINTER, 7, offsetof(struct ProvideCapabilities_r9_IEs, commonIEsProvideCapabilities),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CommonIEsProvideCapabilities,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"commonIEsProvideCapabilities"
		},
	{ ATF_POINTER, 6, offsetof(struct ProvideCapabilities_r9_IEs, a_gnss_ProvideCapabilities),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_A_GNSS_ProvideCapabilities,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"a-gnss-ProvideCapabilities"
		},
	{ ATF_POINTER, 5, offsetof(struct ProvideCapabilities_r9_IEs, otdoa_ProvideCapabilities),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OTDOA_ProvideCapabilities,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"otdoa-ProvideCapabilities"
		},
	{ ATF_POINTER, 4, offsetof(struct ProvideCapabilities_r9_IEs, ecid_ProvideCapabilities),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ECID_ProvideCapabilities,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ecid-ProvideCapabilities"
		},
	{ ATF_POINTER, 3, offsetof(struct ProvideCapabilities_r9_IEs, epdu_ProvideCapabilities),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_EPDU_Sequence,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"epdu-ProvideCapabilities"
		},
	{ ATF_POINTER, 2, offsetof(struct ProvideCapabilities_r9_IEs, ext1),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		0,
		&asn_DEF_ext1_8,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ext1"
		},
	{ ATF_POINTER, 1, offsetof(struct ProvideCapabilities_r9_IEs, ext2),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		0,
		&asn_DEF_ext2_13,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ext2"
		},
};
static const int asn_MAP_ProvideCapabilities_r9_IEs_oms_1[] = { 0, 1, 2, 3, 4, 5, 6 };
static const ber_tlv_tag_t asn_DEF_ProvideCapabilities_r9_IEs_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_ProvideCapabilities_r9_IEs_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* commonIEsProvideCapabilities */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* a-gnss-ProvideCapabilities */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* otdoa-ProvideCapabilities */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* ecid-ProvideCapabilities */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* epdu-ProvideCapabilities */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* ext1 */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 } /* ext2 */
};
asn_SEQUENCE_specifics_t asn_SPC_ProvideCapabilities_r9_IEs_specs_1 = {
	sizeof(struct ProvideCapabilities_r9_IEs),
	offsetof(struct ProvideCapabilities_r9_IEs, _asn_ctx),
	asn_MAP_ProvideCapabilities_r9_IEs_tag2el_1,
	7,	/* Count of tags in the map */
	asn_MAP_ProvideCapabilities_r9_IEs_oms_1,	/* Optional members */
	5, 2,	/* Root/Additions */
	5,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_ProvideCapabilities_r9_IEs = {
	"ProvideCapabilities-r9-IEs",
	"ProvideCapabilities-r9-IEs",
	&asn_OP_SEQUENCE,
	asn_DEF_ProvideCapabilities_r9_IEs_tags_1,
	sizeof(asn_DEF_ProvideCapabilities_r9_IEs_tags_1)
		/sizeof(asn_DEF_ProvideCapabilities_r9_IEs_tags_1[0]), /* 1 */
	asn_DEF_ProvideCapabilities_r9_IEs_tags_1,	/* Same as above */
	sizeof(asn_DEF_ProvideCapabilities_r9_IEs_tags_1)
		/sizeof(asn_DEF_ProvideCapabilities_r9_IEs_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_ProvideCapabilities_r9_IEs_1,
	7,	/* Elements count */
	&asn_SPC_ProvideCapabilities_r9_IEs_specs_1	/* Additional specs */
};

