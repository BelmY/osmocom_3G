/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "HNBAP-CommonDataTypes"
 * 	found in "../../asn1/hnbap/HNBAP-CommonDataTypes.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_Criticality_H_
#define	_Criticality_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Criticality {
	Criticality_reject	= 0,
	Criticality_ignore	= 1,
	Criticality_notify	= 2
} e_Criticality;

/* Criticality */
typedef long	 Criticality_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Criticality;
asn_struct_free_f Criticality_free;
asn_struct_print_f Criticality_print;
asn_constr_check_f Criticality_constraint;
ber_type_decoder_f Criticality_decode_ber;
der_type_encoder_f Criticality_encode_der;
xer_type_decoder_f Criticality_decode_xer;
xer_type_encoder_f Criticality_encode_xer;
per_type_decoder_f Criticality_decode_uper;
per_type_encoder_f Criticality_encode_uper;
per_type_decoder_f Criticality_decode_aper;
per_type_encoder_f Criticality_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _Criticality_H_ */
#include <asn_internal.h>
