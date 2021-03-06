/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ULP-Components"
 * 	found in "/home/martin/repos/LPP-Client/asn/ULP-Components.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#ifndef	_Horandvervel_H_
#define	_Horandvervel_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BIT_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Horandvervel */
typedef struct Horandvervel {
	BIT_STRING_t	 verdirect;
	BIT_STRING_t	 bearing;
	BIT_STRING_t	 horspeed;
	BIT_STRING_t	 verspeed;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Horandvervel_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Horandvervel;
extern asn_SEQUENCE_specifics_t asn_SPC_Horandvervel_specs_1;
extern asn_TYPE_member_t asn_MBR_Horandvervel_1[4];

#ifdef __cplusplus
}
#endif

#endif	/* _Horandvervel_H_ */
#include <asn_internal.h>
