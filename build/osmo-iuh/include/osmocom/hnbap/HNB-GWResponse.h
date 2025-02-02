/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "HNBAP-IEs"
 * 	found in "../../asn1/hnbap/HNBAP-IEs.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_HNB_GWResponse_H_
#define	_HNB_GWResponse_H_


#include <asn_application.h>

/* Including external dependencies */
#include <osmocom/hnbap/HNBConfigInfo.h>
#include <osmocom/hnbap/RNC-ID.h>
#include <osmocom/hnbap/UnknownU-RNTIIndication.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum HNB_GWResponse_PR {
	HNB_GWResponse_PR_NOTHING,	/* No components present */
	HNB_GWResponse_PR_hNB,
	HNB_GWResponse_PR_macroRNC,
	HNB_GWResponse_PR_unknownU_RNTIIndication,
	/* Extensions may appear below */
	
} HNB_GWResponse_PR;

/* HNB-GWResponse */
typedef struct HNB_GWResponse {
	HNB_GWResponse_PR present;
	union HNB_GWResponse_u {
		HNBConfigInfo_t	 hNB;
		RNC_ID_t	 macroRNC;
		UnknownU_RNTIIndication_t	 unknownU_RNTIIndication;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} HNB_GWResponse_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_HNB_GWResponse;

#ifdef __cplusplus
}
#endif

#endif	/* _HNB_GWResponse_H_ */
#include <asn_internal.h>
