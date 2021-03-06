/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "Ver2-ULP-Components"
 * 	found in "/home/martin/repos/LPP-Client/asn/ULP-Components.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#include "LteCellInformation.h"

static int
memb_tA_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 1282)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_memb_tA_constr_7 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 11,  11,  0,  1282 }	/* (0..1282) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_LteCellInformation_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct LteCellInformation, cellGlobalIdEUTRA),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CellGlobalIdEUTRA,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"cellGlobalIdEUTRA"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LteCellInformation, physCellId),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PhysCellId,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"physCellId"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LteCellInformation, trackingAreaCode),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TrackingAreaCode,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"trackingAreaCode"
		},
	{ ATF_POINTER, 4, offsetof(struct LteCellInformation, rsrpResult),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RSRP_Range,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"rsrpResult"
		},
	{ ATF_POINTER, 3, offsetof(struct LteCellInformation, rsrqResult),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RSRQ_Range,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"rsrqResult"
		},
	{ ATF_POINTER, 2, offsetof(struct LteCellInformation, tA),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_tA_constr_7,  memb_tA_constraint_1 },
		0, 0, /* No default value */
		"tA"
		},
	{ ATF_POINTER, 1, offsetof(struct LteCellInformation, measResultListEUTRA),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MeasResultListEUTRA,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"measResultListEUTRA"
		},
};
static const int asn_MAP_LteCellInformation_oms_1[] = { 3, 4, 5, 6 };
static const ber_tlv_tag_t asn_DEF_LteCellInformation_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_LteCellInformation_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* cellGlobalIdEUTRA */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* physCellId */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* trackingAreaCode */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* rsrpResult */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* rsrqResult */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* tA */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 } /* measResultListEUTRA */
};
asn_SEQUENCE_specifics_t asn_SPC_LteCellInformation_specs_1 = {
	sizeof(struct LteCellInformation),
	offsetof(struct LteCellInformation, _asn_ctx),
	asn_MAP_LteCellInformation_tag2el_1,
	7,	/* Count of tags in the map */
	asn_MAP_LteCellInformation_oms_1,	/* Optional members */
	4, 0,	/* Root/Additions */
	7,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_LteCellInformation = {
	"LteCellInformation",
	"LteCellInformation",
	&asn_OP_SEQUENCE,
	asn_DEF_LteCellInformation_tags_1,
	sizeof(asn_DEF_LteCellInformation_tags_1)
		/sizeof(asn_DEF_LteCellInformation_tags_1[0]), /* 1 */
	asn_DEF_LteCellInformation_tags_1,	/* Same as above */
	sizeof(asn_DEF_LteCellInformation_tags_1)
		/sizeof(asn_DEF_LteCellInformation_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_LteCellInformation_1,
	7,	/* Elements count */
	&asn_SPC_LteCellInformation_specs_1	/* Additional specs */
};

