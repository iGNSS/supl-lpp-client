#include "rtcm_generator.h"
#include "lpp2osr.h"
#include "osr2rtcm.h"
#include "osr2rtklib.h"

RTCMGenerator::RTCMGenerator(GNSSSystems gnss_systems, MessageFilter filter)
    : gnss_systems(gnss_systems), filter(filter) {
    // Setup observations data
    osr_init(&osr, SYS_GAL | SYS_GPS | SYS_GLO);

    ref_station_last_sent = time(NULL) - 100;
}

bool RTCMGenerator::verify_msm4(OSR_GNSS* gnss) {
    for (auto i = 0; i < gnss->satellite_count; i++) {
        auto& satellite = gnss->satellites[i];
        if (satellite.id < 0) continue;
        if (satellite.id >= 64) continue;

        // RTCM cannot encode DF398 as missing
        if (!satellite.rough_range.has_value()) return false;

        for (auto j = 0; j < satellite.signal_count; j++) {
            auto& signal = satellite.signals[j];

            // RTCM cannot encode DF402 as missing
            if (!signal.lockTimeIndicator.has_value()) return false;

            // RTCM cannot encode DF420 as missing
            if (!signal.halfCycleAmbiguityIndicator.has_value()) return false;
        }
    }

    return true;
}

bool RTCMGenerator::verify_msm5(OSR_GNSS* gnss) {
    for (auto i = 0; i < gnss->satellite_count; i++) {
        auto& satellite = gnss->satellites[i];
        if (satellite.id < 0) continue;
        if (satellite.id >= 64) continue;

        // RTCM cannot encode DF398 as missing
        if (!satellite.rough_range.has_value()) return false;

        if (gnss->system == SYS_GLO) {
            if (satellite.glo_frequency_channel.has_value()) {
                return true;
            }
        }

        for (auto j = 0; j < satellite.signal_count; j++) {
            auto& signal = satellite.signals[j];

            // RTCM cannot encode DF402 as missing
            if (!signal.lockTimeIndicator.has_value()) return false;

            // RTCM cannot encode DF420 as missing
            if (!signal.halfCycleAmbiguityIndicator.has_value()) return false;

            if (signal.fine_PhaseRangeRate.has_value()) {
                return true;
            }
        }
    }

    return false;
}

bool RTCMGenerator::verify_msm7(OSR_GNSS* gnss) {
    for (auto i = 0; i < gnss->satellite_count; i++) {
        auto& satellite = gnss->satellites[i];
        if (satellite.id < 0) continue;
        if (satellite.id >= 64) continue;

        // RTCM cannot encode DF398 as missing
        if (!satellite.rough_range.has_value()) return false;

        if (gnss->system == SYS_GLO) {
            if (satellite.glo_frequency_channel.has_value()) continue;
        }

        for (auto j = 0; j < satellite.signal_count; j++) {
            auto& signal = satellite.signals[j];

            // RTCM cannot encode DF402 as missing
            if (!signal.lockTimeIndicator.has_value()) return false;

            // RTCM cannot encode DF420 as missing
            if (!signal.halfCycleAmbiguityIndicator.has_value()) return false;

            if (!signal.fine_PhaseRangeRate.has_value()) continue;

            // fine pseudo range: DF405 vs DF400
            auto df400_encoded = (long)round(signal.fine_PseudoRange.value() / P2_24);
            auto df400_decoded = df400_encoded * P2_24;
            auto df405_encoded = (long)round(signal.fine_PseudoRange.value() / P2_29);
            auto df405_decoded = df405_encoded * P2_29;
            if (fabs(df400_decoded - df405_decoded) > 0.0) {
                return true;
            }

            // fine phase range: DF406 vs DF401
            auto df401_encoded = (long)round(signal.fine_PhaseRange.value() / P2_29);
            auto df401_decoded = df401_encoded * P2_29;
            auto df406_encoded = (long)round(signal.fine_PhaseRange.value() / P2_31);
            auto df406_decoded = df406_encoded * P2_31;
            if (fabs(df401_decoded - df406_decoded) > 0.0) {
                return true;
            }

            // lock time indiciator: DF407 vs DF402
            auto df402_encoded = to_msm_lock(signal.lockTimeIndicator.value());
            auto df402_decoded = from_msm_lock(df402_encoded);
            if (df402_decoded != signal.lockTimeIndicator.value()) {
                return true;
            }

            if (signal.carrier_to_noise_ratio.has_value()) {
                // carrier to noise ratio: DF408 vs DF403
                auto df403_encoded = (long)round(signal.carrier_to_noise_ratio.value());
                auto df403_decoded = df403_encoded;
                auto df408_encoded = (long)round(signal.carrier_to_noise_ratio.value() / 0.0625);
                auto df408_decoded = df408_encoded * 0.0625;
                if (fabs(df403_decoded - df408_decoded) > 0.0) {
                    return true;
                }
            }
        }
    }

    return false;
}

size_t RTCMGenerator::convert(unsigned char* buffer, size_t* buffer_size, LPP_Message* message,
                              Generated* generated) {
    // We need to keep these objects in memory so we can send all
    // messages in one stream
    rtcm_t* rtcm_1006 = NULL;
    rtcm_t* rtcm_1032 = NULL;
    rtcm_t* rtcm_1074 = NULL;
    rtcm_t* rtcm_1075 = NULL;
    rtcm_t* rtcm_1076 = NULL;
    rtcm_t* rtcm_1077 = NULL;
    rtcm_t* rtcm_1084 = NULL;
    rtcm_t* rtcm_1085 = NULL;
    rtcm_t* rtcm_1086 = NULL;
    rtcm_t* rtcm_1087 = NULL;
    rtcm_t* rtcm_1094 = NULL;
    rtcm_t* rtcm_1095 = NULL;
    rtcm_t* rtcm_1096 = NULL;
    rtcm_t* rtcm_1097 = NULL;
    rtcm_t* rtcm_1030 = NULL;
    rtcm_t* rtcm_1031 = NULL;
    rtcm_t* rtcm_1230 = NULL;

    osr.gps.satellite_count  = 0;
    osr.gps.residuals        = {};
    osr.gps.bias_information = {};
    osr.glo.satellite_count  = 0;
    osr.glo.residuals        = {};
    osr.glo.bias_information = {};
    osr.gal.satellite_count  = 0;
    osr.gal.residuals        = {};
    osr.gal.bias_information = {};

    auto got_reference_station = gather_reference_station(message, &osr);
    auto got_observations      = gather_observations(message, &osr);

    if (!got_observations) {
        return 0;
    }

    bool msm_has_been_generated = false;

    // Generate MSM7 messages
    if (filter.msm.msm7 && !msm_has_been_generated) {
        // Check if msm7 is required
        auto gps  = verify_msm7(&osr.gps);
        auto glo  = verify_msm7(&osr.glo);
        auto gal  = verify_msm7(&osr.gal);
        auto last = !(filter.msm.msm4 || filter.msm.msm5 || filter.msm.msm6);
        if (gps || glo || gal || last) {
            if (gnss_systems.galileo) {
                rtcm_1097 =
                    gen_rtcm_msm7(&osr.gal, osr.common_observation_info_reference_station_id,
                                  gnss_systems.glonass || gnss_systems.gps);
            }

            if (gnss_systems.glonass) {
                rtcm_1087 = gen_rtcm_msm7(
                    &osr.glo, osr.common_observation_info_reference_station_id, gnss_systems.gps);
            }

            if (gnss_systems.gps) {
                rtcm_1077 = gen_rtcm_msm7(&osr.gps,
                                          osr.common_observation_info_reference_station_id, false);
            }

            msm_has_been_generated = rtcm_1097 || rtcm_1087 || rtcm_1077;
        }
    }

    // Generate MSM5 messages
    if (filter.msm.msm5 && !msm_has_been_generated) {
        // Check if msm5 is required
        auto gps  = verify_msm5(&osr.gps);
        auto glo  = verify_msm5(&osr.glo);
        auto gal  = verify_msm5(&osr.gal);
        auto last = !(filter.msm.msm4);
        if (gps || glo || gal || last) {
            if (gnss_systems.galileo) {
                rtcm_1095 =
                    gen_rtcm_msm5(&osr.gal, osr.common_observation_info_reference_station_id,
                                  gnss_systems.glonass || gnss_systems.gps);
            }

            if (gnss_systems.glonass) {
                rtcm_1085 = gen_rtcm_msm5(
                    &osr.glo, osr.common_observation_info_reference_station_id, gnss_systems.gps);
            }

            if (gnss_systems.gps) {
                rtcm_1075 = gen_rtcm_msm5(&osr.gps,
                                          osr.common_observation_info_reference_station_id, false);
            }

            msm_has_been_generated = rtcm_1095 || rtcm_1085 || rtcm_1075;
        }
    }

    // Generate MSM4 messages
    if (filter.msm.msm4 && !msm_has_been_generated) {
        if (gnss_systems.galileo) {
            rtcm_1094 = gen_rtcm_msm4(&osr.gal, osr.common_observation_info_reference_station_id,
                                      gnss_systems.glonass || gnss_systems.gps);
        }

        if (gnss_systems.glonass) {
            rtcm_1084 = gen_rtcm_msm4(&osr.glo, osr.common_observation_info_reference_station_id,
                                      gnss_systems.gps);
        }

        if (gnss_systems.gps) {
            rtcm_1074 =
                gen_rtcm_msm4(&osr.gps, osr.common_observation_info_reference_station_id, false);
        }

        msm_has_been_generated = rtcm_1094 || rtcm_1084 || rtcm_1074;
    }

    // Only generate other message if any msm messages were successfully generated.
    if (msm_has_been_generated) {
        auto now = time(0);
        if (got_reference_station || (now - ref_station_last_sent) >= 10) {
            if (osr.reference_station.has_value()) {
                rtcm_1006 = gen_rtcm_1006(osr.reference_station.value());
                if (osr.reference_station.value().physical.has_value()) {
                    rtcm_1032 = gen_rtcm_1032(osr.reference_station.value(),
                                              osr.reference_station.value().physical.value());
                }
                ref_station_last_sent = now;
            }
        }

        if (filter.mt1030 && gnss_systems.gps) {
            if (osr.gps.residuals.has_value()) {
                rtcm_1030 = gen_gnss_residuals(&osr.gps.residuals.value());
            }
        }

        if (filter.mt1031 && gnss_systems.glonass) {
            if (osr.glo.residuals.has_value()) {
                rtcm_1031 = gen_gnss_residuals(&osr.glo.residuals.value());
            }
        }

        if (filter.mt1230 && gnss_systems.glonass) {
            if (osr.glo.bias_information.has_value()) {
                rtcm_1230 = gen_rtcm_1230(osr.glo.bias_information.value());
            }
        }
    }

    int nbytes = 0;
    if (rtcm_1006 != NULL) nbytes += rtcm_1006->nbyte;
    if (rtcm_1032 != NULL) nbytes += rtcm_1032->nbyte;
    if (rtcm_1074 != NULL) nbytes += rtcm_1074->nbyte;
    if (rtcm_1075 != NULL) nbytes += rtcm_1075->nbyte;
    if (rtcm_1077 != NULL) nbytes += rtcm_1077->nbyte;
    if (rtcm_1084 != NULL) nbytes += rtcm_1084->nbyte;
    if (rtcm_1085 != NULL) nbytes += rtcm_1085->nbyte;
    if (rtcm_1087 != NULL) nbytes += rtcm_1087->nbyte;
    if (rtcm_1094 != NULL) nbytes += rtcm_1094->nbyte;
    if (rtcm_1095 != NULL) nbytes += rtcm_1095->nbyte;
    if (rtcm_1097 != NULL) nbytes += rtcm_1097->nbyte;
    if (rtcm_1030 != NULL) nbytes += rtcm_1030->nbyte;
    if (rtcm_1031 != NULL) nbytes += rtcm_1031->nbyte;
    if (rtcm_1230 != NULL) nbytes += rtcm_1230->nbyte;

    if (generated) {
        *generated = {};
        if (rtcm_1006) generated->mt1006 = true;
        if (rtcm_1030) generated->mt1030 = true;
        if (rtcm_1031) generated->mt1031 = true;
        if (rtcm_1032) generated->mt1032 = true;
        if (rtcm_1230) generated->mt1230 = true;

        if (rtcm_1074) generated->mt1074 = true;
        if (rtcm_1075) generated->mt1075 = true;
        if (rtcm_1076) generated->mt1076 = true;
        if (rtcm_1077) generated->mt1077 = true;

        if (rtcm_1084) generated->mt1084 = true;
        if (rtcm_1085) generated->mt1085 = true;
        if (rtcm_1086) generated->mt1086 = true;
        if (rtcm_1087) generated->mt1087 = true;

        if (rtcm_1094) generated->mt1094 = true;
        if (rtcm_1095) generated->mt1095 = true;
        if (rtcm_1096) generated->mt1096 = true;
        if (rtcm_1097) generated->mt1097 = true;

        generated->msm = -1;
        if (rtcm_1074 || rtcm_1084 || rtcm_1094) generated->msm = 4;
        if (rtcm_1075 || rtcm_1085 || rtcm_1095) generated->msm = 5;
        if (rtcm_1076 || rtcm_1086 || rtcm_1096) generated->msm = 6;
        if (rtcm_1077 || rtcm_1087 || rtcm_1097) generated->msm = 7;
    }

    auto index  = (size_t)0;
    auto append = [&](rtcm_t*& message) {
        if (message != NULL && index + message->nbyte < *buffer_size) {
            memcpy(&buffer[index], message->buff, message->nbyte);
            index += message->nbyte;
            message = osr2rtcm_end(message);
        }
    };

    append(rtcm_1006);
    append(rtcm_1032);
    append(rtcm_1030);
    append(rtcm_1031);
    append(rtcm_1230);

    append(rtcm_1097);
    append(rtcm_1087);
    append(rtcm_1077);
    append(rtcm_1096);
    append(rtcm_1086);
    append(rtcm_1076);
    append(rtcm_1095);
    append(rtcm_1085);
    append(rtcm_1075);
    append(rtcm_1094);
    append(rtcm_1084);
    append(rtcm_1074);

    *buffer_size = nbytes;
    return index;
}
