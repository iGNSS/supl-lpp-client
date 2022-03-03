/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LPP-PDU-Definitions"
 * 	found in "/home/martin/repos/LPP-Client/asn/LPP.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#ifndef	_NR_DL_PRS_AssistanceDataPerFreq_r16_H_
#define	_NR_DL_PRS_AssistanceDataPerFreq_r16_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct NR_DL_PRS_PositioningFrequencyLayer_r16;
struct NR_DL_PRS_AssistanceDataPerTRP_r16;

/* NR-DL-PRS-AssistanceDataPerFreq-r16 */
typedef struct NR_DL_PRS_AssistanceDataPerFreq_r16 {
	struct NR_DL_PRS_AssistanceDataPerFreq_r16__nr_DL_PRS_AssistanceDataPerFreq {
		A_SEQUENCE_OF(struct NR_DL_PRS_AssistanceDataPerTRP_r16) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} nr_DL_PRS_AssistanceDataPerFreq;
	struct NR_DL_PRS_PositioningFrequencyLayer_r16	*nr_DL_PRS_PositioningFrequencyLayer_r16	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NR_DL_PRS_AssistanceDataPerFreq_r16_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NR_DL_PRS_AssistanceDataPerFreq_r16;
extern asn_SEQUENCE_specifics_t asn_SPC_NR_DL_PRS_AssistanceDataPerFreq_r16_specs_1;
extern asn_TYPE_member_t asn_MBR_NR_DL_PRS_AssistanceDataPerFreq_r16_1[2];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "NR-DL-PRS-PositioningFrequencyLayer-r16.h"
#include "NR-DL-PRS-AssistanceDataPerTRP-r16.h"

#endif	/* _NR_DL_PRS_AssistanceDataPerFreq_r16_H_ */
#include <asn_internal.h>
