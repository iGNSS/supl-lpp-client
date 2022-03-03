#pragma once
#include <rtklib.h>
#include "osr2rtklib.h"

#define RTCM_PROC_SUCCESS 0
#define RTCM_PROC_FAILED -1

rtcm_t* osr2rtcm_begin();
rtcm_t* osr2rtcm_end(rtcm_t* rtcm);
rtcm_t* gen_rtcm_1006(RTK_ReferenceStation sta);
rtcm_t* gen_rtcm_1032(RTK_ReferenceStation         ref,
                      RTK_PhysicalReferenceStation sta);
rtcm_t* gen_gnss_residuals(RTK_Residuals* residuals);
rtcm_t* gen_rtcm_msm4(OSR_GNSS* gnss, long ref_sta_id, int sync);
rtcm_t* gen_rtcm_msm5(OSR_GNSS* gnss, long ref_sta_id, int sync);
rtcm_t* gen_rtcm_msm7(OSR_GNSS* gnss, long ref_sta_id, int sync);
rtcm_t* gen_rtcm_1230(RTK_GLO_BiasInformation bias);