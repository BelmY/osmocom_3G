#include <string.h>

#include <osmocom/core/logging.h>
#include <osmocom/core/utils.h>
#include <osmocom/core/application.h>
#include <osmocom/gsm/gsup.h>

#define VERBOSE_FPRINTF(...)

/* Tests for osmo_gsup_messages.c */

#define TEST_IMSI_IE 0x01, 0x08, 0x21, 0x43, 0x65, 0x87, 0x09, 0x21, 0x43, 0xf5
#define TEST_IMSI_STR "123456789012345"

static void test_gsup_messages_dec_enc(void)
{
	int test_idx;
	int rc;
	uint8_t buf[1024];

	static const uint8_t send_auth_info_req[] = {
		0x08,
		TEST_IMSI_IE
	};

	static const uint8_t send_auth_info_err[] = {
		0x09,
		TEST_IMSI_IE,
		0x02, 0x01, 0x07 /* GPRS no allowed */
	};

	static const uint8_t send_auth_info_res[] = {
		0x0a,
		TEST_IMSI_IE,
		0x03, 0x22, /* Auth tuple */
			0x20, 0x10,
				0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
				0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10,
			0x21, 0x04,
				0x21, 0x22, 0x23, 0x24,
			0x22, 0x08,
				0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38,
		0x03, 0x22, /* Auth tuple */
			0x20, 0x10,
				0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88,
				0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90,
			0x21, 0x04,
				0xa1, 0xa2, 0xa3, 0xa4,
			0x22, 0x08,
				0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8,
	};

	static const uint8_t update_location_req[] = {
		0x04,
		TEST_IMSI_IE,
	};

	static const uint8_t update_location_err[] = {
		0x05,
		TEST_IMSI_IE,
		0x02, 0x01, 0x07 /* GPRS no allowed */
	};

	static const uint8_t update_location_res[] = {
		0x06,
		TEST_IMSI_IE,
		0x08, 0x07, /* MSISDN of the subscriber */
			0x91, 0x94, 0x61, 0x46, 0x32, 0x24, 0x43,
		0x09, 0x07, /* HLR-Number of the subscriber */
			0x91, 0x83, 0x52, 0x38, 0x48, 0x83, 0x93,
		0x04, 0x00, /* PDP info complete */
		0x05, 0x15,
			0x10, 0x01, 0x01,
			0x11, 0x02, 0xf1, 0x21, /* IPv4 */
			0x12, 0x09, 0x04, 't', 'e', 's', 't', 0x03, 'a', 'p', 'n',
			0x13, 0x01, 0x02,
		0x05, 0x11,
			0x10, 0x01, 0x02,
			0x11, 0x02, 0xf1, 0x21, /* IPv4 */
			0x12, 0x08, 0x03, 'f', 'o', 'o', 0x03, 'a', 'p', 'n',
	};

	static const uint8_t location_cancellation_req[] = {
		0x1c,
		TEST_IMSI_IE,
		0x06, 0x01, 0x00,
	};

	static const uint8_t location_cancellation_err[] = {
		0x1d,
		TEST_IMSI_IE,
		0x02, 0x01, 0x03 /* Illegal MS */
	};

	static const uint8_t location_cancellation_res[] = {
		0x1e,
		TEST_IMSI_IE,
	};

	static const uint8_t purge_ms_req[] = {
		0x0c,
		TEST_IMSI_IE,
	};

	static const uint8_t purge_ms_err[] = {
		0x0d,
		TEST_IMSI_IE,
		0x02, 0x01, 0x03, /* Illegal MS */
	};

	static const uint8_t purge_ms_res[] = {
		0x0e,
		TEST_IMSI_IE,
		0x07, 0x00,
	};

	static const uint8_t send_auth_info_res_umts[] = {
		0x0a,
		TEST_IMSI_IE,
		0x03, 0x62, /* Auth tuple */
			0x20, 0x10, /* rand */
				0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
				0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10,
			0x21, 0x04, /* sres */
				0x21, 0x22, 0x23, 0x24,
			0x22, 0x08, /* kc */
				0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38,
			0x23, 0x10, /* IK (UMTS) */
				0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
				0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10,
			0x24, 0x10, /* CK (UMTS) */
				0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
				0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10,
			0x25, 0x10, /* AUTN (UMTS) */
				0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
				0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10,
			0x27, 0x08, /* RES (UMTS) */
				0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
		0x03, 0x62, /* Auth tuple */
			0x20, 0x10, /* rand */
				0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8,
				0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0x10,
			0x21, 0x04, /* sres */
				0xb1, 0xb2, 0xb3, 0xb4,
			0x22, 0x08, /* kc */
				0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8,
			0x23, 0x10, /* IK (UMTS) */
				0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8,
				0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf, 0xd0,
			0x24, 0x10, /* CK (UMTS) */
				0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8,
				0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef, 0xe0,
			0x25, 0x10, /* AUTN (UMTS) */
				0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8,
				0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff, 0xf0,
			0x27, 0x08, /* RES (UMTS) */
				0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98,
	};

	static const uint8_t send_auth_info_req_auts[] = {
		0x08,
		TEST_IMSI_IE,
		0x26, 0x0e, /* AUTS (UMTS) */
			0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
			0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e,
		0x20, 0x10, /* rand */
			0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
			0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10,
	};

	static const struct test {
		char *name;
		const uint8_t *data;
		size_t data_len;
	} test_messages[] = {
		{"Send Authentication Info Request",
			send_auth_info_req, sizeof(send_auth_info_req)},
		{"Send Authentication Info Error",
			send_auth_info_err, sizeof(send_auth_info_err)},
		{"Send Authentication Info Result",
			send_auth_info_res, sizeof(send_auth_info_res)},
		{"Update Location Request",
			update_location_req, sizeof(update_location_req)},
		{"Update Location Error",
			update_location_err, sizeof(update_location_err)},
		{"Update Location Result",
			update_location_res, sizeof(update_location_res)},
		{"Location Cancellation Request",
			location_cancellation_req, sizeof(location_cancellation_req)},
		{"Location Cancellation Error",
			location_cancellation_err, sizeof(location_cancellation_err)},
		{"Location Cancellation Result",
			location_cancellation_res, sizeof(location_cancellation_res)},
		{"Purge MS Request",
			purge_ms_req, sizeof(purge_ms_req)},
		{"Purge MS Error",
			purge_ms_err, sizeof(purge_ms_err)},
		{"Purge MS Result",
			purge_ms_res, sizeof(purge_ms_res)},
		{"Send Authentication Info Result with IK, CK, AUTN and RES (UMTS)",
			send_auth_info_res_umts, sizeof(send_auth_info_res_umts)},
		{"Send Authentication Info Request with AUTS and RAND (UMTS)",
			send_auth_info_req_auts, sizeof(send_auth_info_req_auts)},
	};

	printf("Test GSUP message decoding/encoding\n");

	for (test_idx = 0; test_idx < ARRAY_SIZE(test_messages); test_idx++) {
		const struct test *t = &test_messages[test_idx];
		struct osmo_gsup_message gm = {0};
		struct msgb *msg = msgb_alloc(4096, "gsup_test");

		printf("  Testing %s\n", t->name);

		rc = osmo_gsup_decode(t->data, t->data_len, &gm);
		OSMO_ASSERT(rc >= 0);

		osmo_gsup_encode(msg, &gm);

		fprintf(stderr, "  generated message: %s\n", msgb_hexdump(msg));
		fprintf(stderr, "  original message:  %s\n", osmo_hexdump(t->data, t->data_len));
		fprintf(stderr, "  IMSI:              %s\n", gm.imsi);
		OSMO_ASSERT(strcmp(gm.imsi, TEST_IMSI_STR) == 0);
		OSMO_ASSERT(msgb_length(msg) == t->data_len);
		OSMO_ASSERT(memcmp(msgb_data(msg), t->data, t->data_len) == 0);

		msgb_free(msg);
	}

	/* simple truncation test */
	for (test_idx = 0; test_idx < ARRAY_SIZE(test_messages); test_idx++) {
		int j;
		const struct test *t = &test_messages[test_idx];
		int ie_end = t->data_len;
		struct osmo_gsup_message gm = {0};
		int counter = 0;
		int parse_err = 0;

		for (j = t->data_len - 1; j >= 0; --j) {
			rc = osmo_gsup_decode(t->data, j, &gm);
			counter += 1;

			VERBOSE_FPRINTF(stderr,
				"  partial message decoding: "
				"orig_len = %d, trunc = %d, rc = %d, ie_end = %d\n",
				t->data_len, j, rc, ie_end);
			if (rc >= 0) {
				VERBOSE_FPRINTF(stderr,
					"    remaing partial message: %s\n",
					osmo_hexdump(t->data + j, ie_end - j));

				OSMO_ASSERT(j <= ie_end - 2);
				OSMO_ASSERT(t->data[j+0] <= OSMO_GSUP_CN_DOMAIN_IE);
				OSMO_ASSERT(t->data[j+1] <= ie_end - j - 2);

				ie_end = j;
			} else {
				parse_err += 1;
			}
		}

		fprintf(stderr,
			"  message %d: tested %d truncations, %d parse failures\n",
			test_idx, counter, parse_err);
	}

	/* Don't log thousands of message modification errors */
	LOGP(DLGSUP, LOGL_NOTICE, "Stopping DLGSUP logging\n");
	log_set_category_filter(osmo_stderr_target, DLGSUP, 0, 0);

	/* message modification test (relies on ASAN or valgrind being used) */
	for (test_idx = 0; test_idx < ARRAY_SIZE(test_messages); test_idx++) {
		int j;
		const struct test *t = &test_messages[test_idx];
		struct osmo_gsup_message gm = {0};
		uint8_t val;
		int counter = 0;
		int parse_err = 0;

		OSMO_ASSERT(sizeof(buf) >= t->data_len);

		for (j = t->data_len - 1; j >= 0; --j) {
			memcpy(buf, t->data, t->data_len);
			val = 0;
			do {
				VERBOSE_FPRINTF(stderr,
					"t = %d, len = %d, val = %d\n",
					test_idx, j, val);
				buf[j] = val;
				rc = osmo_gsup_decode(buf, t->data_len, &gm);
				counter += 1;
				if (rc < 0)
					parse_err += 1;

				val += 1;
			} while (val != (uint8_t)256);
		}

		fprintf(stderr,
			"  message %d: tested %d modifications, %d parse failures\n",
			test_idx, counter, parse_err);
	}
}

const struct log_info_cat default_categories[] = {
};

static struct log_info info = {
	.cat = default_categories,
	.num_cat = ARRAY_SIZE(default_categories),
};

int main(int argc, char **argv)
{
	osmo_init_logging(&info);
	log_set_print_filename(osmo_stderr_target, 0);
	log_set_print_timestamp(osmo_stderr_target, 0);
	log_set_use_color(osmo_stderr_target, 0);
	log_set_print_category(osmo_stderr_target, 1);

	test_gsup_messages_dec_enc();

	printf("Done.\n");
	return EXIT_SUCCESS;
}
