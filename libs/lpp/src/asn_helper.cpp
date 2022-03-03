#include "asn_helper.h"

BIT_STRING* asn_bit_string_create() {
    BIT_STRING* string = ALLOC_ZERO(BIT_STRING);
    return string;
}

void asn_bit_string_expand(BIT_STRING* string, int bytes) {
    assert(bytes > 0);
    if ((size_t)bytes > string->size) {
        int diff = bytes - string->size;

        uint8_t* new_buf = (uint8_t*)calloc(bytes, sizeof(uint8_t));
        memcpy(new_buf + diff, string->buf, string->size);

        free(string->buf);
        string->buf  = new_buf;
        string->size = bytes;
    }
}

int64_t asn_bit_string_int64(BIT_STRING* bits, int start) {
    int64_t value = 0;
    for (size_t i = 0; i < bits->size; i++) {
        for (size_t j = 0; j < 8; j++) {
            int64_t index = i * 8 + (7 - j);
            if (bits->buf[i] & (1 << j))
                value |= (1llu << index);
        }
    }

    value <<= start;

    return value;
}

int64_t asn_bit_string_int64_left(BIT_STRING* bits, int min, int max) {
    int64_t value     = 0;
    int64_t bit_count = bits->size * 8 - bits->bits_unused;
    for (int i = bits->size - 1; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            int64_t index = i * 8 + (7 - j);
            if ((bit_count - 1 - index) >= max || (bit_count - 1 - index) < min)
                continue;

            if (bits->buf[i] & (1 << j))
                value |= (1llu << (bit_count - 1 - index));
        }
    }

    value >>= min;
#if 0
    // xer_fprint(stdout, &asn_DEF_BIT_STRING, bits);
    uint64_t x = 1llu << bit_count;
    while (x) {
        if (x == (1llu << (max - 1)))
            printf("|");
        printf("%u", (x & value) ? 1 : 0);
        if (x == (1llu << min))
            printf("|");
        x >>= 1;
    }
    printf("\n");
#endif
    return value;
}

void asn_bit_string_set_reverse(BIT_STRING* string, int bit, int value) {
    int size = 1 + bit / 8;
    asn_bit_string_expand(string, size);

    int byte       = bit / 8;
    int byte_index = string->size - 1 - byte;
    int local_bit  = 7 - (bit - byte * 8);

    if (value)
        string->buf[byte_index] |= 1 << local_bit;
    else
        string->buf[byte_index] &= ~(1 << local_bit);
}

void asn_bit_string_set(BIT_STRING* string, int bit, int value) {
    int size = 1 + bit / 8;
    asn_bit_string_expand(string, size);

    int byte       = bit / 8;
    int byte_index = string->size - 1 - byte;
    int local_bit  = bit - byte * 8;

    if (value)
        string->buf[byte_index] |= 1 << local_bit;
    else
        string->buf[byte_index] &= ~(1 << local_bit);
}

int asn_bit_string_get(BIT_STRING* string, int bit) {
    size_t byte       = bit / 8;
    size_t local_bit  = bit - byte * 8;
    size_t byte_index = string->size - 1 - byte;
    if (byte_index >= string->size)
        return 0;
    return (string->buf[byte_index] >> local_bit) & 1;
}

void asn_bit_string_shift_left(BIT_STRING* string, int count) {
    BIT_STRING new_string{};
    for (size_t i = 0; i < string->size * 8; i++) {
        int value = asn_bit_string_get(string, i);
        if (i + (size_t)count < string->size * 8)
            asn_bit_string_set(&new_string, i + count, value);
    }

    new_string.bits_unused = string->bits_unused;
    *string                = new_string;  // TODO: Free?
}

void asn_bit_string_minimize(BIT_STRING* string) {
    assert(string->size >= 1 && string->bits_unused == 0);
    uint8_t value = string->buf[0];
    uint8_t mask  = 0x80;

    while ((value & mask) == 0 && mask > 0 && string->bits_unused < 7) {
        string->bits_unused++;
        mask >>= 1;
    }

    asn_bit_string_shift_left(string, string->bits_unused);
}

void asn_bit_string_set_length(BIT_STRING* string, int bits) {
    asn_bit_string_expand(string, (bits + 7) / 8);
    int unused          = string->size * 8 - bits;
    string->bits_unused = unused;
}

void asn_bit_string_set_range(BIT_STRING* string, int from, int to) {
    for (int i = from; i < to; i++) {
        asn_bit_string_set(string, i, true);
    }

    asn_bit_string_minimize(string);
}

void asn_bit_string_set_s32(BIT_STRING* string, int _value) {
    unsigned int value = _value;
    for (auto i = 0u; i < sizeof(int) * 8; i++) {
        asn_bit_string_set(string, i, value & (1ull << i));
    }
}

void supl_fill_tracking_area_code(TrackingAreaCode_t* tac, int tac_value) {
    for (int i = 0; i < 16; i++) {
        asn_bit_string_set(tac, i, tac_value & (1 << i));
    }
}

void asn_bit_string_set_s32_shifted(BIT_STRING* string, int _value,
                                    int shift_count) {
    unsigned int value = _value;
    for (auto i = 0u; i < sizeof(int) * 8; i++) {
        asn_bit_string_set(string, i, value & (1ull << i));
    }
    asn_bit_string_shift_left(string, shift_count);
}

void supl_fill_cell_identity(CellIdentity_t* ci, int ci_value) {
    ci->bits_unused = 4;

    for (int i = 0; i < 28; i++) {
        asn_bit_string_set(ci, i + ci->bits_unused, ci_value & (1 << i));
    }
}

MCC* supl_create_mcc(int mcc_value) {
    if (mcc_value < 0 || mcc_value > 999) {
        return NULL;
    }

    MCC_MNC_Digit* d;
    MCC*           mcc;
    char           tmp[8];
    uint32_t       i = 0;

    mcc = ALLOC_ZERO(MCC);
    sprintf(tmp, "%d", mcc_value);
    for (i = 0; i < strlen(tmp); i++) {
        d  = ALLOC_ZERO(MCC_MNC_Digit_t);
        *d = tmp[i] - '0';
        ASN_SEQUENCE_ADD(mcc, d);
    }

    return mcc;
}

void supl_fill_mcc(MCC* mcc, int mcc_value) {
    if (mcc_value < 0 || mcc_value > 999) {
        return;
    }

    MCC_MNC_Digit* d;
    char           tmp[8];
    uint32_t       i = 0;

    sprintf(tmp, "%d", mcc_value);
    for (i = 0; i < strlen(tmp); i++) {
        d  = ALLOC_ZERO(MCC_MNC_Digit);
        *d = tmp[i] - '0';
        ASN_SEQUENCE_ADD(mcc, d);
    }
}

void supl_fill_mnc(MNC* mnc, int mnc_value) {
    if (mnc_value < 0 || mnc_value > 999) {
        return;
    }

    MCC_MNC_Digit* d;
    char           tmp[8];
    uint32_t       i = 0;

    sprintf(tmp, "%02d", mnc_value);
    for (i = 0; i < strlen(tmp); i++) {
        d  = ALLOC_ZERO(MCC_MNC_Digit);
        *d = tmp[i] - '0';
        ASN_SEQUENCE_ADD(mnc, d);
    }
}

ECGI* ecgi_create(long mcc, long mnc, long id) {
    ECGI* primary_cell = ALLOC_ZERO(ECGI);

    supl_fill_mcc((MCC*)&primary_cell->mcc, mcc);
    supl_fill_mnc((MNC*)&primary_cell->mnc, mnc);

    supl_fill_cell_identity(&primary_cell->cellidentity, id);
    return primary_cell;
}

double long_pointer2scaled_double(long* ptr, double def, double arg) {
    if (!ptr)
        return def;
    return *ptr / arg;
}

double long_pointer(long* ptr, long def) {
    if (!ptr)
        return def;
    return *ptr;
}

long gnss2long(GNSS_SignalID_t gnss_id) {
    if (gnss_id.ext1) {
        return *gnss_id.ext1->gnss_SignalID_Ext_r15;
    } else {
        return gnss_id.gnss_SignalID;
    }
}

