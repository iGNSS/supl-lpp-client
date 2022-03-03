#pragma once
#include "asnlib.h"
#include <lpp.h>
#include "osr.h"

typedef uint32_t RTKGatherResult;

#define RTK_G_NONE 0
#define RTK_G_OBSERVATIONS 1
#define RTK_G_BIAS_INFORMATION 2
#define RTK_G_REFERENCE_STATION 4

bool gather_reference_station(LPP_Message* lpp, OSR* osr);
bool gather_observations(LPP_Message* lpp, OSR* osr);

double from_msm_lock_ex(long value);
double from_msm_lock(long value);
