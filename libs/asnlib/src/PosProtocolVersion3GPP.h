/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ULP-Version-2-parameter-extensions"
 * 	found in "/home/martin/repos/LPP-Client/asn/SUPL.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#ifndef	_PosProtocolVersion3GPP_H_
#define	_PosProtocolVersion3GPP_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* PosProtocolVersion3GPP */
typedef struct PosProtocolVersion3GPP {
	long	 majorVersionField;
	long	 technicalVersionField;
	long	 editorialVersionField;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PosProtocolVersion3GPP_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PosProtocolVersion3GPP;
extern asn_SEQUENCE_specifics_t asn_SPC_PosProtocolVersion3GPP_specs_1;
extern asn_TYPE_member_t asn_MBR_PosProtocolVersion3GPP_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _PosProtocolVersion3GPP_H_ */
#include <asn_internal.h>
