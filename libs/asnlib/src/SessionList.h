/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "SUPL-REPORT"
 * 	found in "/home/martin/repos/LPP-Client/asn/SUPL.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#ifndef	_SessionList_H_
#define	_SessionList_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct SessionInformation;

/* SessionList */
typedef struct SessionList {
	A_SEQUENCE_OF(struct SessionInformation) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SessionList_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SessionList;
extern asn_SET_OF_specifics_t asn_SPC_SessionList_specs_1;
extern asn_TYPE_member_t asn_MBR_SessionList_1[1];
extern asn_per_constraints_t asn_PER_type_SessionList_constr_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "SessionInformation.h"

#endif	/* _SessionList_H_ */
#include <asn_internal.h>
