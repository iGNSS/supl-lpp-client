/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LPP-PDU-Definitions"
 * 	found in "/home/martin/repos/LPP-Client/asn/LPP.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#include "BDS-ClockModel2-r16.h"

static int
memb_bdsToc_r16_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 2047)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_bdsA0_r16_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= -16777216 && value <= 16777215)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_bdsA1_r16_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= -2097152 && value <= 2097151)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_bdsA2_r16_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= -1024 && value <= 1023)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_bdsTgdB1Cp_r16_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= -2048 && value <= 2047)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_bdsIscB1Cd_r16_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= -2048 && value <= 2047)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_memb_bdsToc_r16_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 11,  11,  0,  2047 }	/* (0..2047) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_bdsA0_r16_constr_3 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 25, -1, -16777216,  16777215 }	/* (-16777216..16777215) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_bdsA1_r16_constr_4 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 22, -1, -2097152,  2097151 }	/* (-2097152..2097151) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_bdsA2_r16_constr_5 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 11,  11, -1024,  1023 }	/* (-1024..1023) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_bdsTgdB1Cp_r16_constr_6 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 12,  12, -2048,  2047 }	/* (-2048..2047) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_bdsIscB1Cd_r16_constr_7 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 12,  12, -2048,  2047 }	/* (-2048..2047) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_BDS_ClockModel2_r16_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct BDS_ClockModel2_r16, bdsToc_r16),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_bdsToc_r16_constr_2,  memb_bdsToc_r16_constraint_1 },
		0, 0, /* No default value */
		"bdsToc-r16"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BDS_ClockModel2_r16, bdsA0_r16),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_bdsA0_r16_constr_3,  memb_bdsA0_r16_constraint_1 },
		0, 0, /* No default value */
		"bdsA0-r16"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BDS_ClockModel2_r16, bdsA1_r16),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_bdsA1_r16_constr_4,  memb_bdsA1_r16_constraint_1 },
		0, 0, /* No default value */
		"bdsA1-r16"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BDS_ClockModel2_r16, bdsA2_r16),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_bdsA2_r16_constr_5,  memb_bdsA2_r16_constraint_1 },
		0, 0, /* No default value */
		"bdsA2-r16"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BDS_ClockModel2_r16, bdsTgdB1Cp_r16),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_bdsTgdB1Cp_r16_constr_6,  memb_bdsTgdB1Cp_r16_constraint_1 },
		0, 0, /* No default value */
		"bdsTgdB1Cp-r16"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BDS_ClockModel2_r16, bdsIscB1Cd_r16),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_bdsIscB1Cd_r16_constr_7,  memb_bdsIscB1Cd_r16_constraint_1 },
		0, 0, /* No default value */
		"bdsIscB1Cd-r16"
		},
};
static const ber_tlv_tag_t asn_DEF_BDS_ClockModel2_r16_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_BDS_ClockModel2_r16_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* bdsToc-r16 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* bdsA0-r16 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* bdsA1-r16 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* bdsA2-r16 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* bdsTgdB1Cp-r16 */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 } /* bdsIscB1Cd-r16 */
};
asn_SEQUENCE_specifics_t asn_SPC_BDS_ClockModel2_r16_specs_1 = {
	sizeof(struct BDS_ClockModel2_r16),
	offsetof(struct BDS_ClockModel2_r16, _asn_ctx),
	asn_MAP_BDS_ClockModel2_r16_tag2el_1,
	6,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	6,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_BDS_ClockModel2_r16 = {
	"BDS-ClockModel2-r16",
	"BDS-ClockModel2-r16",
	&asn_OP_SEQUENCE,
	asn_DEF_BDS_ClockModel2_r16_tags_1,
	sizeof(asn_DEF_BDS_ClockModel2_r16_tags_1)
		/sizeof(asn_DEF_BDS_ClockModel2_r16_tags_1[0]), /* 1 */
	asn_DEF_BDS_ClockModel2_r16_tags_1,	/* Same as above */
	sizeof(asn_DEF_BDS_ClockModel2_r16_tags_1)
		/sizeof(asn_DEF_BDS_ClockModel2_r16_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_BDS_ClockModel2_r16_1,
	6,	/* Elements count */
	&asn_SPC_BDS_ClockModel2_r16_specs_1	/* Additional specs */
};

