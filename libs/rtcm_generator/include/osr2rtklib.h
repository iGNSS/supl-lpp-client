#pragma once
#include <rtklib.h>
#include "osr.h"

void osr2rtklib_convert(rtcm_t* rtcm, int sys, gtime_t time,
                        RTK_Satellite* satellites, int satellite_count);
