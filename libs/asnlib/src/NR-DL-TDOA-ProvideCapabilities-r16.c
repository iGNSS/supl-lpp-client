/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LPP-PDU-Definitions"
 * 	found in "/home/martin/repos/LPP-Client/asn/LPP.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#include "NR-DL-TDOA-ProvideCapabilities-r16.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static int
memb_nr_DL_TDOA_MeasSupported_r16_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const BIT_STRING_t *st = (const BIT_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	if(st->size > 0) {
		/* Size in bits */
		size = 8 * st->size - (st->bits_unused & 0x07);
	} else {
		size = 0;
	}
	
	if((size >= 1 && size <= 8)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_type_additionalPathsReport_r16_constr_6 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 0,  0,  0,  0 }	/* (0..0) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_periodicalReporting_r16_constr_8 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 0,  0,  0,  0 }	/* (0..0) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_nr_DL_TDOA_MeasSupported_r16_constr_4 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 3,  3,  1,  8 }	/* (SIZE(1..8)) */,
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_additionalPathsReport_r16_value2enum_6[] = {
	{ 0,	9,	"supported" }
};
static const unsigned int asn_MAP_additionalPathsReport_r16_enum2value_6[] = {
	0	/* supported(0) */
};
static const asn_INTEGER_specifics_t asn_SPC_additionalPathsReport_r16_specs_6 = {
	asn_MAP_additionalPathsReport_r16_value2enum_6,	/* "tag" => N; sorted by tag */
	asn_MAP_additionalPathsReport_r16_enum2value_6,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_additionalPathsReport_r16_tags_6[] = {
	(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_additionalPathsReport_r16_6 = {
	"additionalPathsReport-r16",
	"additionalPathsReport-r16",
	&asn_OP_NativeEnumerated,
	asn_DEF_additionalPathsReport_r16_tags_6,
	sizeof(asn_DEF_additionalPathsReport_r16_tags_6)
		/sizeof(asn_DEF_additionalPathsReport_r16_tags_6[0]) - 1, /* 1 */
	asn_DEF_additionalPathsReport_r16_tags_6,	/* Same as above */
	sizeof(asn_DEF_additionalPathsReport_r16_tags_6)
		/sizeof(asn_DEF_additionalPathsReport_r16_tags_6[0]), /* 2 */
	{ 0, &asn_PER_type_additionalPathsReport_r16_constr_6, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_additionalPathsReport_r16_specs_6	/* Additional specs */
};

static const asn_INTEGER_enum_map_t asn_MAP_periodicalReporting_r16_value2enum_8[] = {
	{ 0,	9,	"supported" }
};
static const unsigned int asn_MAP_periodicalReporting_r16_enum2value_8[] = {
	0	/* supported(0) */
};
static const asn_INTEGER_specifics_t asn_SPC_periodicalReporting_r16_specs_8 = {
	asn_MAP_periodicalReporting_r16_value2enum_8,	/* "tag" => N; sorted by tag */
	asn_MAP_periodicalReporting_r16_enum2value_8,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_periodicalReporting_r16_tags_8[] = {
	(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_periodicalReporting_r16_8 = {
	"periodicalReporting-r16",
	"periodicalReporting-r16",
	&asn_OP_NativeEnumerated,
	asn_DEF_periodicalReporting_r16_tags_8,
	sizeof(asn_DEF_periodicalReporting_r16_tags_8)
		/sizeof(asn_DEF_periodicalReporting_r16_tags_8[0]) - 1, /* 1 */
	asn_DEF_periodicalReporting_r16_tags_8,	/* Same as above */
	sizeof(asn_DEF_periodicalReporting_r16_tags_8)
		/sizeof(asn_DEF_periodicalReporting_r16_tags_8[0]), /* 2 */
	{ 0, &asn_PER_type_periodicalReporting_r16_constr_8, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_periodicalReporting_r16_specs_8	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_NR_DL_TDOA_ProvideCapabilities_r16_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NR_DL_TDOA_ProvideCapabilities_r16, nr_DL_TDOA_Mode_r16),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PositioningModes,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"nr-DL-TDOA-Mode-r16"
		},
	{ ATF_POINTER, 1, offsetof(struct NR_DL_TDOA_ProvideCapabilities_r16, nr_DL_TDOA_MeasCapability_r16),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NR_DL_PRS_MeasCapability_r16,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"nr-DL-TDOA-MeasCapability-r16"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NR_DL_TDOA_ProvideCapabilities_r16, nr_DL_TDOA_MeasSupported_r16),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BIT_STRING,
		0,
		{ 0, &asn_PER_memb_nr_DL_TDOA_MeasSupported_r16_constr_4,  memb_nr_DL_TDOA_MeasSupported_r16_constraint_1 },
		0, 0, /* No default value */
		"nr-DL-TDOA-MeasSupported-r16"
		},
	{ ATF_POINTER, 2, offsetof(struct NR_DL_TDOA_ProvideCapabilities_r16, additionalPathsReport_r16),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_additionalPathsReport_r16_6,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"additionalPathsReport-r16"
		},
	{ ATF_POINTER, 1, offsetof(struct NR_DL_TDOA_ProvideCapabilities_r16, periodicalReporting_r16),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_periodicalReporting_r16_8,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"periodicalReporting-r16"
		},
};
static const int asn_MAP_NR_DL_TDOA_ProvideCapabilities_r16_oms_1[] = { 1, 3, 4 };
static const ber_tlv_tag_t asn_DEF_NR_DL_TDOA_ProvideCapabilities_r16_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NR_DL_TDOA_ProvideCapabilities_r16_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* nr-DL-TDOA-Mode-r16 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* nr-DL-TDOA-MeasCapability-r16 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* nr-DL-TDOA-MeasSupported-r16 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* additionalPathsReport-r16 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 } /* periodicalReporting-r16 */
};
asn_SEQUENCE_specifics_t asn_SPC_NR_DL_TDOA_ProvideCapabilities_r16_specs_1 = {
	sizeof(struct NR_DL_TDOA_ProvideCapabilities_r16),
	offsetof(struct NR_DL_TDOA_ProvideCapabilities_r16, _asn_ctx),
	asn_MAP_NR_DL_TDOA_ProvideCapabilities_r16_tag2el_1,
	5,	/* Count of tags in the map */
	asn_MAP_NR_DL_TDOA_ProvideCapabilities_r16_oms_1,	/* Optional members */
	3, 0,	/* Root/Additions */
	5,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_NR_DL_TDOA_ProvideCapabilities_r16 = {
	"NR-DL-TDOA-ProvideCapabilities-r16",
	"NR-DL-TDOA-ProvideCapabilities-r16",
	&asn_OP_SEQUENCE,
	asn_DEF_NR_DL_TDOA_ProvideCapabilities_r16_tags_1,
	sizeof(asn_DEF_NR_DL_TDOA_ProvideCapabilities_r16_tags_1)
		/sizeof(asn_DEF_NR_DL_TDOA_ProvideCapabilities_r16_tags_1[0]), /* 1 */
	asn_DEF_NR_DL_TDOA_ProvideCapabilities_r16_tags_1,	/* Same as above */
	sizeof(asn_DEF_NR_DL_TDOA_ProvideCapabilities_r16_tags_1)
		/sizeof(asn_DEF_NR_DL_TDOA_ProvideCapabilities_r16_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_NR_DL_TDOA_ProvideCapabilities_r16_1,
	5,	/* Elements count */
	&asn_SPC_NR_DL_TDOA_ProvideCapabilities_r16_specs_1	/* Additional specs */
};

