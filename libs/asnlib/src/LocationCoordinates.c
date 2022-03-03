/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LPP-PDU-Definitions"
 * 	found in "/home/martin/repos/LPP-Client/asn/LPP.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#include "LocationCoordinates.h"

asn_per_constraints_t asn_PER_type_LocationCoordinates_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  3,  3,  0,  6 }	/* (0..6,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_LocationCoordinates_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct LocationCoordinates, choice.ellipsoidPoint),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Ellipsoid_Point,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ellipsoidPoint"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LocationCoordinates, choice.ellipsoidPointWithUncertaintyCircle),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Ellipsoid_PointWithUncertaintyCircle,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ellipsoidPointWithUncertaintyCircle"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LocationCoordinates, choice.ellipsoidPointWithUncertaintyEllipse),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_EllipsoidPointWithUncertaintyEllipse,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ellipsoidPointWithUncertaintyEllipse"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LocationCoordinates, choice.polygon),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Polygon,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"polygon"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LocationCoordinates, choice.ellipsoidPointWithAltitude),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_EllipsoidPointWithAltitude,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ellipsoidPointWithAltitude"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LocationCoordinates, choice.ellipsoidPointWithAltitudeAndUncertaintyEllipsoid),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_EllipsoidPointWithAltitudeAndUncertaintyEllipsoid,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ellipsoidPointWithAltitudeAndUncertaintyEllipsoid"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LocationCoordinates, choice.ellipsoidArc),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_EllipsoidArc,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ellipsoidArc"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LocationCoordinates, choice.highAccuracyEllipsoidPointWithUncertaintyEllipse_v1510),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_HighAccuracyEllipsoidPointWithUncertaintyEllipse_r15,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"highAccuracyEllipsoidPointWithUncertaintyEllipse-v1510"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LocationCoordinates, choice.highAccuracyEllipsoidPointWithAltitudeAndUncertaintyEllipsoid_v1510),
		(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_HighAccuracyEllipsoidPointWithAltitudeAndUncertaintyEllipsoid_r15,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"highAccuracyEllipsoidPointWithAltitudeAndUncertaintyEllipsoid-v1510"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_LocationCoordinates_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* ellipsoidPoint */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* ellipsoidPointWithUncertaintyCircle */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* ellipsoidPointWithUncertaintyEllipse */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* polygon */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* ellipsoidPointWithAltitude */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* ellipsoidPointWithAltitudeAndUncertaintyEllipsoid */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* ellipsoidArc */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* highAccuracyEllipsoidPointWithUncertaintyEllipse-v1510 */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 } /* highAccuracyEllipsoidPointWithAltitudeAndUncertaintyEllipsoid-v1510 */
};
asn_CHOICE_specifics_t asn_SPC_LocationCoordinates_specs_1 = {
	sizeof(struct LocationCoordinates),
	offsetof(struct LocationCoordinates, _asn_ctx),
	offsetof(struct LocationCoordinates, present),
	sizeof(((struct LocationCoordinates *)0)->present),
	asn_MAP_LocationCoordinates_tag2el_1,
	9,	/* Count of tags in the map */
	0, 0,
	7	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_LocationCoordinates = {
	"LocationCoordinates",
	"LocationCoordinates",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ 0, &asn_PER_type_LocationCoordinates_constr_1, CHOICE_constraint },
	asn_MBR_LocationCoordinates_1,
	9,	/* Elements count */
	&asn_SPC_LocationCoordinates_specs_1	/* Additional specs */
};

