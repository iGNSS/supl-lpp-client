/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LPP-PDU-Definitions"
 * 	found in "/home/martin/repos/LPP-Client/asn/LPP.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#include "EllipsoidPointWithAltitudeAndUncertaintyEllipsoid.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static int
memb_degreesLatitude_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 8388607)) {
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
memb_degreesLongitude_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= -8388608 && value <= 8388607)) {
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
memb_altitude_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 32767)) {
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
memb_uncertaintySemiMajor_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 127)) {
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
memb_uncertaintySemiMinor_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 127)) {
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
memb_orientationMajorAxis_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 179)) {
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
memb_uncertaintyAltitude_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 127)) {
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
memb_confidence_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 100)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_type_latitudeSign_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_altitudeDirection_constr_7 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_degreesLatitude_constr_5 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 23, -1,  0,  8388607 }	/* (0..8388607) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_degreesLongitude_constr_6 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 24, -1, -8388608,  8388607 }	/* (-8388608..8388607) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_altitude_constr_10 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 15,  15,  0,  32767 }	/* (0..32767) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_uncertaintySemiMajor_constr_11 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 7,  7,  0,  127 }	/* (0..127) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_uncertaintySemiMinor_constr_12 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 7,  7,  0,  127 }	/* (0..127) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_orientationMajorAxis_constr_13 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 8,  8,  0,  179 }	/* (0..179) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_uncertaintyAltitude_constr_14 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 7,  7,  0,  127 }	/* (0..127) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_confidence_constr_15 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 7,  7,  0,  100 }	/* (0..100) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_latitudeSign_value2enum_2[] = {
	{ 0,	5,	"north" },
	{ 1,	5,	"south" }
};
static const unsigned int asn_MAP_latitudeSign_enum2value_2[] = {
	0,	/* north(0) */
	1	/* south(1) */
};
static const asn_INTEGER_specifics_t asn_SPC_latitudeSign_specs_2 = {
	asn_MAP_latitudeSign_value2enum_2,	/* "tag" => N; sorted by tag */
	asn_MAP_latitudeSign_enum2value_2,	/* N => "tag"; sorted by N */
	2,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_latitudeSign_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_latitudeSign_2 = {
	"latitudeSign",
	"latitudeSign",
	&asn_OP_NativeEnumerated,
	asn_DEF_latitudeSign_tags_2,
	sizeof(asn_DEF_latitudeSign_tags_2)
		/sizeof(asn_DEF_latitudeSign_tags_2[0]) - 1, /* 1 */
	asn_DEF_latitudeSign_tags_2,	/* Same as above */
	sizeof(asn_DEF_latitudeSign_tags_2)
		/sizeof(asn_DEF_latitudeSign_tags_2[0]), /* 2 */
	{ 0, &asn_PER_type_latitudeSign_constr_2, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_latitudeSign_specs_2	/* Additional specs */
};

static const asn_INTEGER_enum_map_t asn_MAP_altitudeDirection_value2enum_7[] = {
	{ 0,	6,	"height" },
	{ 1,	5,	"depth" }
};
static const unsigned int asn_MAP_altitudeDirection_enum2value_7[] = {
	1,	/* depth(1) */
	0	/* height(0) */
};
static const asn_INTEGER_specifics_t asn_SPC_altitudeDirection_specs_7 = {
	asn_MAP_altitudeDirection_value2enum_7,	/* "tag" => N; sorted by tag */
	asn_MAP_altitudeDirection_enum2value_7,	/* N => "tag"; sorted by N */
	2,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_altitudeDirection_tags_7[] = {
	(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_altitudeDirection_7 = {
	"altitudeDirection",
	"altitudeDirection",
	&asn_OP_NativeEnumerated,
	asn_DEF_altitudeDirection_tags_7,
	sizeof(asn_DEF_altitudeDirection_tags_7)
		/sizeof(asn_DEF_altitudeDirection_tags_7[0]) - 1, /* 1 */
	asn_DEF_altitudeDirection_tags_7,	/* Same as above */
	sizeof(asn_DEF_altitudeDirection_tags_7)
		/sizeof(asn_DEF_altitudeDirection_tags_7[0]), /* 2 */
	{ 0, &asn_PER_type_altitudeDirection_constr_7, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_altitudeDirection_specs_7	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_EllipsoidPointWithAltitudeAndUncertaintyEllipsoid_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct EllipsoidPointWithAltitudeAndUncertaintyEllipsoid, latitudeSign),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_latitudeSign_2,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"latitudeSign"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct EllipsoidPointWithAltitudeAndUncertaintyEllipsoid, degreesLatitude),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_degreesLatitude_constr_5,  memb_degreesLatitude_constraint_1 },
		0, 0, /* No default value */
		"degreesLatitude"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct EllipsoidPointWithAltitudeAndUncertaintyEllipsoid, degreesLongitude),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_degreesLongitude_constr_6,  memb_degreesLongitude_constraint_1 },
		0, 0, /* No default value */
		"degreesLongitude"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct EllipsoidPointWithAltitudeAndUncertaintyEllipsoid, altitudeDirection),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_altitudeDirection_7,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"altitudeDirection"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct EllipsoidPointWithAltitudeAndUncertaintyEllipsoid, altitude),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_altitude_constr_10,  memb_altitude_constraint_1 },
		0, 0, /* No default value */
		"altitude"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct EllipsoidPointWithAltitudeAndUncertaintyEllipsoid, uncertaintySemiMajor),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_uncertaintySemiMajor_constr_11,  memb_uncertaintySemiMajor_constraint_1 },
		0, 0, /* No default value */
		"uncertaintySemiMajor"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct EllipsoidPointWithAltitudeAndUncertaintyEllipsoid, uncertaintySemiMinor),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_uncertaintySemiMinor_constr_12,  memb_uncertaintySemiMinor_constraint_1 },
		0, 0, /* No default value */
		"uncertaintySemiMinor"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct EllipsoidPointWithAltitudeAndUncertaintyEllipsoid, orientationMajorAxis),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_orientationMajorAxis_constr_13,  memb_orientationMajorAxis_constraint_1 },
		0, 0, /* No default value */
		"orientationMajorAxis"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct EllipsoidPointWithAltitudeAndUncertaintyEllipsoid, uncertaintyAltitude),
		(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_uncertaintyAltitude_constr_14,  memb_uncertaintyAltitude_constraint_1 },
		0, 0, /* No default value */
		"uncertaintyAltitude"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct EllipsoidPointWithAltitudeAndUncertaintyEllipsoid, confidence),
		(ASN_TAG_CLASS_CONTEXT | (9 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_confidence_constr_15,  memb_confidence_constraint_1 },
		0, 0, /* No default value */
		"confidence"
		},
};
static const ber_tlv_tag_t asn_DEF_EllipsoidPointWithAltitudeAndUncertaintyEllipsoid_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_EllipsoidPointWithAltitudeAndUncertaintyEllipsoid_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* latitudeSign */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* degreesLatitude */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* degreesLongitude */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* altitudeDirection */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* altitude */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* uncertaintySemiMajor */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* uncertaintySemiMinor */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* orientationMajorAxis */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 }, /* uncertaintyAltitude */
    { (ASN_TAG_CLASS_CONTEXT | (9 << 2)), 9, 0, 0 } /* confidence */
};
asn_SEQUENCE_specifics_t asn_SPC_EllipsoidPointWithAltitudeAndUncertaintyEllipsoid_specs_1 = {
	sizeof(struct EllipsoidPointWithAltitudeAndUncertaintyEllipsoid),
	offsetof(struct EllipsoidPointWithAltitudeAndUncertaintyEllipsoid, _asn_ctx),
	asn_MAP_EllipsoidPointWithAltitudeAndUncertaintyEllipsoid_tag2el_1,
	10,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_EllipsoidPointWithAltitudeAndUncertaintyEllipsoid = {
	"EllipsoidPointWithAltitudeAndUncertaintyEllipsoid",
	"EllipsoidPointWithAltitudeAndUncertaintyEllipsoid",
	&asn_OP_SEQUENCE,
	asn_DEF_EllipsoidPointWithAltitudeAndUncertaintyEllipsoid_tags_1,
	sizeof(asn_DEF_EllipsoidPointWithAltitudeAndUncertaintyEllipsoid_tags_1)
		/sizeof(asn_DEF_EllipsoidPointWithAltitudeAndUncertaintyEllipsoid_tags_1[0]), /* 1 */
	asn_DEF_EllipsoidPointWithAltitudeAndUncertaintyEllipsoid_tags_1,	/* Same as above */
	sizeof(asn_DEF_EllipsoidPointWithAltitudeAndUncertaintyEllipsoid_tags_1)
		/sizeof(asn_DEF_EllipsoidPointWithAltitudeAndUncertaintyEllipsoid_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_EllipsoidPointWithAltitudeAndUncertaintyEllipsoid_1,
	10,	/* Elements count */
	&asn_SPC_EllipsoidPointWithAltitudeAndUncertaintyEllipsoid_specs_1	/* Additional specs */
};

