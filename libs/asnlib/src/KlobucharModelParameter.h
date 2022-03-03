/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LPP-PDU-Definitions"
 * 	found in "/home/martin/repos/LPP-Client/asn/LPP.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#ifndef	_KlobucharModelParameter_H_
#define	_KlobucharModelParameter_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BIT_STRING.h>
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* KlobucharModelParameter */
typedef struct KlobucharModelParameter {
	BIT_STRING_t	 dataID;
	long	 alfa0;
	long	 alfa1;
	long	 alfa2;
	long	 alfa3;
	long	 beta0;
	long	 beta1;
	long	 beta2;
	long	 beta3;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} KlobucharModelParameter_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_KlobucharModelParameter;
extern asn_SEQUENCE_specifics_t asn_SPC_KlobucharModelParameter_specs_1;
extern asn_TYPE_member_t asn_MBR_KlobucharModelParameter_1[9];

#ifdef __cplusplus
}
#endif

#endif	/* _KlobucharModelParameter_H_ */
#include <asn_internal.h>
