#pragma once

#include <asnlib.h>
#include <stdint.h>


BIT_STRING* asn_bit_string_create();
void asn_bit_string_expand(BIT_STRING* string, int bytes);
int64_t asn_bit_string_int64(BIT_STRING* bits, int start);
int64_t asn_bit_string_int64_left(BIT_STRING* bits, int min, int max);
void asn_bit_string_set_reverse(BIT_STRING* string, int bit, int value);
void asn_bit_string_set(BIT_STRING* string, int bit, int value);
int asn_bit_string_get(BIT_STRING* string, int bit);
void asn_bit_string_shift_left(BIT_STRING* string, int count);
void asn_bit_string_minimize(BIT_STRING* string);
void asn_bit_string_set_length(BIT_STRING* string, int bits);
void asn_bit_string_set_range(BIT_STRING* string, int from, int to);
void asn_bit_string_set_s32(BIT_STRING* string, int _value);
void asn_bit_string_set_s32_shifted(BIT_STRING* string, int _value,
                                    int shift_count);
void supl_fill_tracking_area_code(TrackingAreaCode_t* tac, int tac_value);
void supl_fill_cell_identity(CellIdentity_t* ci, int ci_value);
MCC* supl_create_mcc(int mcc_value);
void supl_fill_mcc(MCC* mcc, int mcc_value);
void supl_fill_mnc(MNC* mnc, int mnc_value);
ECGI* ecgi_create(long mcc, long mnc, long id);
double long_pointer2scaled_double(long* ptr, double def, double arg);
double long_pointer(long* ptr, long def);
long gnss2long(GNSS_SignalID_t gnss_id);

inline long* newLong(long value) {
    long* x = ALLOC_ZERO(long);
    *x      = value;
    return x;
}

