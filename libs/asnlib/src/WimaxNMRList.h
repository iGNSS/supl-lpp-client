/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "Ver2-ULP-Components"
 * 	found in "/home/martin/repos/LPP-Client/asn/ULP-Components.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#ifndef	_WimaxNMRList_H_
#define	_WimaxNMRList_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct WimaxNMR;

/* WimaxNMRList */
typedef struct WimaxNMRList {
	A_SEQUENCE_OF(struct WimaxNMR) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} WimaxNMRList_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_WimaxNMRList;
extern asn_SET_OF_specifics_t asn_SPC_WimaxNMRList_specs_1;
extern asn_TYPE_member_t asn_MBR_WimaxNMRList_1[1];
extern asn_per_constraints_t asn_PER_type_WimaxNMRList_constr_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "WimaxNMR.h"

#endif	/* _WimaxNMRList_H_ */
#include <asn_internal.h>
