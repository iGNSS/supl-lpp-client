/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ULP-Version-2-message-extensions"
 * 	found in "/home/martin/repos/LPP-Client/asn/SUPL.asn"
 * 	`asn1c -fcompound-names -no-gen-OER -pdu=all -no-gen-example -S /home/martin/repos/LPP-Client/ASN1C/skeletons`
 */

#ifndef	_NotificationMode_H_
#define	_NotificationMode_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NotificationMode {
	NotificationMode_normal	= 0,
	NotificationMode_basedOnLocation	= 1
	/*
	 * Enumeration is extensible
	 */
} e_NotificationMode;

/* NotificationMode */
typedef long	 NotificationMode_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_NotificationMode_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_NotificationMode;
extern const asn_INTEGER_specifics_t asn_SPC_NotificationMode_specs_1;
asn_struct_free_f NotificationMode_free;
asn_struct_print_f NotificationMode_print;
asn_constr_check_f NotificationMode_constraint;
ber_type_decoder_f NotificationMode_decode_ber;
der_type_encoder_f NotificationMode_encode_der;
xer_type_decoder_f NotificationMode_decode_xer;
xer_type_encoder_f NotificationMode_encode_xer;
per_type_decoder_f NotificationMode_decode_uper;
per_type_encoder_f NotificationMode_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _NotificationMode_H_ */
#include <asn_internal.h>
