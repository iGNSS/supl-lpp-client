#pragma once
#include "osr.h"

struct MessageFilter {
    // Tell RTCMGenerator which MSM messages you're interested in. The output
    // will be the highest MSM message possible with the data available.
    struct {
        bool msm4 = true;  // if possible generate MSM4 messages
        bool msm5 = true;  // if possible generate MSM5 messages
        bool msm6 = true;  // if possible generate MSM6 messages
        bool msm7 = true;  // if possible generate MSM7 messages
    } msm;

    struct {
        bool mt1006 = true;
        bool mt1032 = true;
    } reference_station;

    bool mt1030 = true;
    bool mt1031 = true;

    bool mt1230 = true;
};

struct GNSSSystems {
    bool gps;
    bool glonass;
    bool galileo;
};

struct Generated {
    int  msm;
    bool mt1074;
    bool mt1075;
    bool mt1076;
    bool mt1077;
    bool mt1084;
    bool mt1085;
    bool mt1086;
    bool mt1087;
    bool mt1094;
    bool mt1095;
    bool mt1096;
    bool mt1097;
    bool mt1006;
    bool mt1032;
    bool mt1030;
    bool mt1031;
    bool mt1230;
};

struct LPP_Message;
class RTCMGenerator {
public:
    RTCMGenerator() = default;
    RTCMGenerator(GNSSSystems, MessageFilter);

    // Generate RTCM messages from LPP message.
    // Returns bytes written to 'buffer' and 'buffer_size' is updated to
    // required size.
    size_t convert(unsigned char* buffer, size_t* buffer_size, LPP_Message*, Generated* = NULL);

private:
    bool verify_msm4(OSR_GNSS* gnss);
    bool verify_msm5(OSR_GNSS* gnss);
    bool verify_msm7(OSR_GNSS* gnss);

private:
    GNSSSystems   gnss_systems;
    MessageFilter filter;
    OSR           osr;

    time_t ref_station_last_sent;
};