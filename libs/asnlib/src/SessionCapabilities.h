/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ULP-Version-2-parameter-extensions"
 * 	found in "/home/martin/repos/LPP-Client/asn/SUPL.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#ifndef	_SessionCapabilities_H_
#define	_SessionCapabilities_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SessionCapabilities */
typedef struct SessionCapabilities {
	long	 maxNumberTotalSessions;
	long	 maxNumberPeriodicSessions;
	long	 maxNumberTriggeredSessions;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SessionCapabilities_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SessionCapabilities;
extern asn_SEQUENCE_specifics_t asn_SPC_SessionCapabilities_specs_1;
extern asn_TYPE_member_t asn_MBR_SessionCapabilities_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _SessionCapabilities_H_ */
#include <asn_internal.h>
