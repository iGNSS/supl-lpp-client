/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ULP-Version-2-message-extensions"
 * 	found in "/home/martin/repos/LPP-Client/asn/SUPL.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#ifndef	_Ver2_SUPL_POS_extension_H_
#define	_Ver2_SUPL_POS_extension_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct UTRAN_GPSReferenceTimeAssistance;
struct UTRAN_GPSReferenceTimeResult;
struct UTRAN_GANSSReferenceTimeAssistance;
struct UTRAN_GANSSReferenceTimeResult;

/* Ver2-SUPL-POS-extension */
typedef struct Ver2_SUPL_POS_extension {
	struct UTRAN_GPSReferenceTimeAssistance	*utran_GPSReferenceTimeAssistance	/* OPTIONAL */;
	struct UTRAN_GPSReferenceTimeResult	*utran_GPSReferenceTimeResult	/* OPTIONAL */;
	struct UTRAN_GANSSReferenceTimeAssistance	*utran_GANSSReferenceTimeAssistance	/* OPTIONAL */;
	struct UTRAN_GANSSReferenceTimeResult	*utran_GANSSReferenceTimeResult	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Ver2_SUPL_POS_extension_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Ver2_SUPL_POS_extension;
extern asn_SEQUENCE_specifics_t asn_SPC_Ver2_SUPL_POS_extension_specs_1;
extern asn_TYPE_member_t asn_MBR_Ver2_SUPL_POS_extension_1[4];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "UTRAN-GPSReferenceTimeAssistance.h"
#include "UTRAN-GPSReferenceTimeResult.h"
#include "UTRAN-GANSSReferenceTimeAssistance.h"
#include "UTRAN-GANSSReferenceTimeResult.h"

#endif	/* _Ver2_SUPL_POS_extension_H_ */
#include <asn_internal.h>
