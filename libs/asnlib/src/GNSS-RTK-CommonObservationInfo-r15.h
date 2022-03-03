/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "LPP-PDU-Definitions"
 * 	found in "/home/martin/repos/LPP-Client/asn/LPP.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#ifndef	_GNSS_RTK_CommonObservationInfo_r15_H_
#define	_GNSS_RTK_CommonObservationInfo_r15_H_


#include <asn_application.h>

/* Including external dependencies */
#include "GNSS-ReferenceStationID-r15.h"
#include <NativeInteger.h>
#include <BIT_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* GNSS-RTK-CommonObservationInfo-r15 */
typedef struct GNSS_RTK_CommonObservationInfo_r15 {
	GNSS_ReferenceStationID_r15_t	 referenceStationID_r15;
	long	 clockSteeringIndicator_r15;
	long	 externalClockIndicator_r15;
	BIT_STRING_t	 smoothingIndicator_r15;
	BIT_STRING_t	 smoothingInterval_r15;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GNSS_RTK_CommonObservationInfo_r15_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GNSS_RTK_CommonObservationInfo_r15;
extern asn_SEQUENCE_specifics_t asn_SPC_GNSS_RTK_CommonObservationInfo_r15_specs_1;
extern asn_TYPE_member_t asn_MBR_GNSS_RTK_CommonObservationInfo_r15_1[5];

#ifdef __cplusplus
}
#endif

#endif	/* _GNSS_RTK_CommonObservationInfo_r15_H_ */
#include <asn_internal.h>
