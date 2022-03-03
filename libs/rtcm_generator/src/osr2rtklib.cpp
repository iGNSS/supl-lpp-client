#include "osr2rtklib.h"

// Code for converting from OSR to
// the the format expected by RTKLIB.

/* msm signal id table -------------------------------------------------------*/
static const char* msm_sig_gps[32] = {
    /* GPS: ref [13] table 3.5-87, ref [14][15] table 3.5-91 */
    "1C", "",   "",   "",   "1P", "1W", "2C", "2P",     /* 0-7   */
    "2W", "2S", "2L", "2X", "5I", "5Q", "5X",           /* 8-14  */
    "1S", "1L", "1X", "",   "",   "",   "",   "",       /* 15-22 */
    "",   "",   "",   "",   "",   "",   "",   "",   "", /* 23-31 */
};

static const char* msm_sig_glo[32] = {
    /* GLONASS: ref [13] table 3.5-93, ref [14][15] table 3.5-97 */
    "1C", "2C", "", "1P", "2P", "", "", "", "", "", "", "", "", "", "", "",
    "",   "",   "", "",   "",   "", "", "", "", "", "", "", "", "", "", "",
};

static const char* msm_sig_gal[32] = {
    /* Galileo: ref [15] table 3.5-100 */
    "",   "",   "",   "",   "",   "1C", "1A", "1B", /* 0-7 */
    "1X", "1Z", "6C", "6A", "6B", "6X", "6Z",       /* 8-14 */
    "7I", "7Q", "7X", "8I", "8Q", "8X", "5I", "5Q", /* 15-22 */
    "5X", "",   "",   "",   "",   "",   "",   "",   "",
}; /* 23-31 */

// TODO code not verified with SUPL server changes. We may need to fix this
// later
static const char* msm_sig_qzs[32] = {
    /* QZSS: ref [15] table 3.5-103 */
    "",   "1C", "", "", "", "",   "",   "",   "6S", "6L", "6X", "", "", "",   "2S", "2L",
    "2X", "",   "", "", "", "5I", "5Q", "5X", "",   "",   "",   "", "", "1S", "1L", "1X",
};

// TODO code not verified with SUPL server changes. We may need to fix this
// later
static const char* msm_sig_sbs[32] = {
    /* SBAS: ref [13] table 3.5-T+005 */
    "", "1C", "", "", "", "",   "",   "",   "", "", "", "", "", "", "", "",
    "", "",   "", "", "", "5I", "5Q", "5X", "", "", "", "", "", "", "", "",
};

// TODO code not verified with SUPL server changes. We may need to fix this
// later
static const char* msm_sig_cmp[32] = {
    /* BeiDou: ref [15] table 3.5-106 */
    "", "1I", "1Q", "1X", "", "", "", "6I", "6Q", "6X", "", "", "", "7I", "7Q", "7X",
    "", "",   "",   "",   "", "", "", "",   "",   "",   "", "", "", "",   "",   "",
};

static int obsindex(obs_t* obs, gtime_t time, int sat) {
    int i, j;

    for (i = 0; i < obs->n; i++) {
        if (obs->data[i].sat == sat) return i; /* field already exists */
    }
    if (i >= MAXOBS) return -1; /* overflow */

    /* add new field */
    obs->data[i].time = time;
    obs->data[i].sat  = sat;

    /*Initial values are set to 0*/
    for (j = 0; j < NFREQ + NEXOBS; j++) {
        obs->data[i].L[j] = obs->data[i].P[j] = 0.0;
        obs->data[i].D[j]                     = 0.0;
        obs->data[i].SNR[j] = obs->data[i].LLI[j] = obs->data[i].code[j] = 0;
    }
    obs->n++;
    return i;
}

/* Convert satellite/signal data (Observations) to rtk_obs ---------------------
 * Save converted data as rtk_obs
 * args   : OSR *src              I struct to save obs_data
 *        : RTKSatellite* satellites          I satellite data
 *        : int satellite_count                 I number of satellites
 *        : int sys        I satellite system (SYS_GPS, SYS_GAL, SYS_GLO,
 *                                             SYS_QZS, SYS_SBS, SYS_CMP,
 SYS_IRN)
 *        : gtime_t time   I sat time (time_glo, time_gal, time_gps)
 * return : none
 * notes  : currently only GLONASS, GPS and GALELIO satellites are supported
 *
 -----------------------------------------------------------------------------*/
void osr2rtklib_convert(rtcm_t* rtcm, int sys, gtime_t time, RTK_Satellite* satellites,
                        int satellite_count) {
    int    total_signals = 0;
    obs_t* dst           = &rtcm->obs;
    for (auto i = 0; i < satellite_count; i++) {
        RTK_Satellite* satellite = &satellites[i];
        total_signals += satellite->signal_count;
        // satellite->id is 0 indexed
        // But RTKLIB has satellites indexed from 1
        int sat_id          = satellite->id + 1;
        int satellite_index = -1;

        if (sys == SYS_QZS)
            sat_id += MINPRNQZS - 1;
        else if (sys == SYS_SBS)
            sat_id += MINPRNSBS - 1;

        int sat = satno(sys, sat_id);
        if (sat) {
            // Get/add index in obsdata for satellite
            satellite_index = obsindex(dst, time, sat);
        }

        if (sat <= 0 || satellite_index < 0) continue;

        obsd_t* dst_satellite = &dst->data[satellite_index];
        for (auto k = 0; k < satellite->signal_count; k++) {
            RTK_Signal* signal = &satellite->signals[k];

            const char* signal_type;
            switch (sys) {
            case SYS_GPS: signal_type = msm_sig_gps[signal->id]; break;
            case SYS_GLO: signal_type = msm_sig_glo[signal->id]; break;
            case SYS_GAL: signal_type = msm_sig_gal[signal->id]; break;
            case SYS_QZS: signal_type = msm_sig_qzs[signal->id]; break;
            case SYS_SBS: signal_type = msm_sig_sbs[signal->id]; break;
            case SYS_CMP: signal_type = msm_sig_cmp[signal->id]; break;
            default: signal_type = ""; break;
            }

            // Convert signal_type ("1C", ...) to signal_code (CODE_?)
            int           signal_freq;
            unsigned char signal_code = obs2code(signal_type, &signal_freq);
            if (signal_freq < 0) continue;

            // index for RTKLIB obs array
            int signal_index = k;

            dst_satellite->integer_ms[signal_index] = OptDouble{
                .value     = satellite->integer_ms.or_value(0.0),
                .available = satellite->integer_ms.has_value(),
            };

            dst_satellite->rough_range_modulo_ms[signal_index] = OptDouble{
                .value     = satellite->rough_range.or_value(0.0),
                .available = satellite->rough_range.has_value(),
            };

            dst_satellite->rough_phase_range_rates[signal_index] = OptDouble{
                .value     = satellite->rough_phase_range_rate.or_value(0.0),
                .available = satellite->rough_phase_range_rate.has_value(),
            };

            if (satellite->glo_frequency_channel.has_value()) {
                dst_satellite->extended_satellite_info[signal_index] =
                    satellite->glo_frequency_channel.value() + 7;
            } else {
                dst_satellite->extended_satellite_info[signal_index] = 0;
            }

            dst_satellite->fine_pseudo_range[signal_index] = OptDouble{
                .value     = signal->fine_PseudoRange.or_value(0.0),
                .available = signal->fine_PseudoRange.has_value(),
            };

            dst_satellite->fine_phase_range[signal_index] = OptDouble{
                .value     = signal->fine_PhaseRange.or_value(0.0),
                .available = signal->fine_PhaseRange.has_value(),
            };

            dst_satellite->fine_phase_range_rates[signal_index] = OptDouble{
                .value     = signal->fine_PhaseRangeRate.or_value(0.0),
                .available = signal->fine_PhaseRangeRate.has_value(),
            };

            dst_satellite->carrier_to_noise_ratio[signal_index] = OptDouble{
                .value     = signal->carrier_to_noise_ratio.or_value(0.0),
                .available = signal->carrier_to_noise_ratio.has_value(),
            };

            dst_satellite->phase_range_lock[signal_index] = OptDouble{
                .value     = signal->lockTimeIndicator.or_value(0.0),
                .available = signal->lockTimeIndicator.has_value(),
            };

            dst_satellite->half_cycle[signal_index] =
                signal->halfCycleAmbiguityIndicator.or_value(0);

            // TODO(ewasjon): remove?
            dst_satellite->code[signal_index] = signal_code;
        }
    }
}
