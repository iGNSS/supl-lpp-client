/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LPP-PDU-Definitions"
 * 	found in "/home/martin/repos/LPP-Client/asn/LPP.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#ifndef	_PeriodicalReportingCriteria_H_
#define	_PeriodicalReportingCriteria_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum PeriodicalReportingCriteria__reportingAmount {
	PeriodicalReportingCriteria__reportingAmount_ra1	= 0,
	PeriodicalReportingCriteria__reportingAmount_ra2	= 1,
	PeriodicalReportingCriteria__reportingAmount_ra4	= 2,
	PeriodicalReportingCriteria__reportingAmount_ra8	= 3,
	PeriodicalReportingCriteria__reportingAmount_ra16	= 4,
	PeriodicalReportingCriteria__reportingAmount_ra32	= 5,
	PeriodicalReportingCriteria__reportingAmount_ra64	= 6,
	PeriodicalReportingCriteria__reportingAmount_ra_Infinity	= 7
} e_PeriodicalReportingCriteria__reportingAmount;
typedef enum PeriodicalReportingCriteria__reportingInterval {
	PeriodicalReportingCriteria__reportingInterval_noPeriodicalReporting	= 0,
	PeriodicalReportingCriteria__reportingInterval_ri0_25	= 1,
	PeriodicalReportingCriteria__reportingInterval_ri0_5	= 2,
	PeriodicalReportingCriteria__reportingInterval_ri1	= 3,
	PeriodicalReportingCriteria__reportingInterval_ri2	= 4,
	PeriodicalReportingCriteria__reportingInterval_ri4	= 5,
	PeriodicalReportingCriteria__reportingInterval_ri8	= 6,
	PeriodicalReportingCriteria__reportingInterval_ri16	= 7,
	PeriodicalReportingCriteria__reportingInterval_ri32	= 8,
	PeriodicalReportingCriteria__reportingInterval_ri64	= 9
} e_PeriodicalReportingCriteria__reportingInterval;

/* PeriodicalReportingCriteria */
typedef struct PeriodicalReportingCriteria {
	long	*reportingAmount	/* DEFAULT 7 */;
	long	 reportingInterval;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PeriodicalReportingCriteria_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_reportingAmount_2;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_reportingInterval_11;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_PeriodicalReportingCriteria;
extern asn_SEQUENCE_specifics_t asn_SPC_PeriodicalReportingCriteria_specs_1;
extern asn_TYPE_member_t asn_MBR_PeriodicalReportingCriteria_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _PeriodicalReportingCriteria_H_ */
#include <asn_internal.h>
