/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LPP-PDU-Definitions"
 * 	found in "/home/martin/repos/LPP-Client/asn/LPP.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#ifndef	_SupportedChannels_11bg_r14_H_
#define	_SupportedChannels_11bg_r14_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BOOLEAN.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SupportedChannels-11bg-r14 */
typedef struct SupportedChannels_11bg_r14 {
	BOOLEAN_t	 ch1_r14;
	BOOLEAN_t	 ch2_r14;
	BOOLEAN_t	 ch3_r14;
	BOOLEAN_t	 ch4_r14;
	BOOLEAN_t	 ch5_r14;
	BOOLEAN_t	 ch6_r14;
	BOOLEAN_t	 ch7_r14;
	BOOLEAN_t	 ch8_r14;
	BOOLEAN_t	 ch9_r14;
	BOOLEAN_t	 ch10_r14;
	BOOLEAN_t	 ch11_r14;
	BOOLEAN_t	 ch12_r14;
	BOOLEAN_t	 ch13_r14;
	BOOLEAN_t	 ch14_r14;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SupportedChannels_11bg_r14_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SupportedChannels_11bg_r14;
extern asn_SEQUENCE_specifics_t asn_SPC_SupportedChannels_11bg_r14_specs_1;
extern asn_TYPE_member_t asn_MBR_SupportedChannels_11bg_r14_1[14];

#ifdef __cplusplus
}
#endif

#endif	/* _SupportedChannels_11bg_r14_H_ */
#include <asn_internal.h>
