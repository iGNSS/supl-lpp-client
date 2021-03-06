/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "Ver2-ULP-Components"
 * 	found in "/home/martin/repos/LPP-Client/asn/ULP-Components.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#include "ReportingCap.h"

static int
memb_minInt_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1 && value <= 3600)) {
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
memb_maxInt_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1 && value <= 1440)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_memb_minInt_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 12,  12,  1,  3600 }	/* (1..3600) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_maxInt_constr_3 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 11,  11,  1,  1440 }	/* (1..1440) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_ReportingCap_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct ReportingCap, minInt),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_minInt_constr_2,  memb_minInt_constraint_1 },
		0, 0, /* No default value */
		"minInt"
		},
	{ ATF_POINTER, 1, offsetof(struct ReportingCap, maxInt),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_maxInt_constr_3,  memb_maxInt_constraint_1 },
		0, 0, /* No default value */
		"maxInt"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ReportingCap, repMode),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RepMode_cap,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"repMode"
		},
	{ ATF_POINTER, 1, offsetof(struct ReportingCap, batchRepCap),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BatchRepCap,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"batchRepCap"
		},
};
static const int asn_MAP_ReportingCap_oms_1[] = { 1, 3 };
static const ber_tlv_tag_t asn_DEF_ReportingCap_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_ReportingCap_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* minInt */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* maxInt */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* repMode */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* batchRepCap */
};
asn_SEQUENCE_specifics_t asn_SPC_ReportingCap_specs_1 = {
	sizeof(struct ReportingCap),
	offsetof(struct ReportingCap, _asn_ctx),
	asn_MAP_ReportingCap_tag2el_1,
	4,	/* Count of tags in the map */
	asn_MAP_ReportingCap_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	4,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_ReportingCap = {
	"ReportingCap",
	"ReportingCap",
	&asn_OP_SEQUENCE,
	asn_DEF_ReportingCap_tags_1,
	sizeof(asn_DEF_ReportingCap_tags_1)
		/sizeof(asn_DEF_ReportingCap_tags_1[0]), /* 1 */
	asn_DEF_ReportingCap_tags_1,	/* Same as above */
	sizeof(asn_DEF_ReportingCap_tags_1)
		/sizeof(asn_DEF_ReportingCap_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_ReportingCap_1,
	4,	/* Elements count */
	&asn_SPC_ReportingCap_specs_1	/* Additional specs */
};

