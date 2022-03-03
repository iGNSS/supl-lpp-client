/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LPP-PDU-Definitions"
 * 	found in "/home/martin/repos/LPP-Client/asn/LPP.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#include "Delta-Latitude-r16.h"

static int
memb_delta_Latitude_r16_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
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
memb_coarse_delta_Latitude_r16_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 4095)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_memb_delta_Latitude_r16_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 11,  11, -1024,  1023 }	/* (-1024..1023) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_coarse_delta_Latitude_r16_constr_3 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 12,  12,  0,  4095 }	/* (0..4095) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_Delta_Latitude_r16_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct Delta_Latitude_r16, delta_Latitude_r16),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_delta_Latitude_r16_constr_2,  memb_delta_Latitude_r16_constraint_1 },
		0, 0, /* No default value */
		"delta-Latitude-r16"
		},
	{ ATF_POINTER, 1, offsetof(struct Delta_Latitude_r16, coarse_delta_Latitude_r16),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_coarse_delta_Latitude_r16_constr_3,  memb_coarse_delta_Latitude_r16_constraint_1 },
		0, 0, /* No default value */
		"coarse-delta-Latitude-r16"
		},
};
static const int asn_MAP_Delta_Latitude_r16_oms_1[] = { 1 };
static const ber_tlv_tag_t asn_DEF_Delta_Latitude_r16_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_Delta_Latitude_r16_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* delta-Latitude-r16 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* coarse-delta-Latitude-r16 */
};
asn_SEQUENCE_specifics_t asn_SPC_Delta_Latitude_r16_specs_1 = {
	sizeof(struct Delta_Latitude_r16),
	offsetof(struct Delta_Latitude_r16, _asn_ctx),
	asn_MAP_Delta_Latitude_r16_tag2el_1,
	2,	/* Count of tags in the map */
	asn_MAP_Delta_Latitude_r16_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	2,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_Delta_Latitude_r16 = {
	"Delta-Latitude-r16",
	"Delta-Latitude-r16",
	&asn_OP_SEQUENCE,
	asn_DEF_Delta_Latitude_r16_tags_1,
	sizeof(asn_DEF_Delta_Latitude_r16_tags_1)
		/sizeof(asn_DEF_Delta_Latitude_r16_tags_1[0]), /* 1 */
	asn_DEF_Delta_Latitude_r16_tags_1,	/* Same as above */
	sizeof(asn_DEF_Delta_Latitude_r16_tags_1)
		/sizeof(asn_DEF_Delta_Latitude_r16_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_Delta_Latitude_r16_1,
	2,	/* Elements count */
	&asn_SPC_Delta_Latitude_r16_specs_1	/* Additional specs */
};

