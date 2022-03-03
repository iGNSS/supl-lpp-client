#include "osr.h"

void osr_init(OSR* od, int system_mask) {
    *od = {};

    od->system_mask = system_mask;
    od->gps.system  = SYS_GPS;
    od->glo.system  = SYS_GLO;
    od->gal.system  = SYS_GAL;
}

RTK_Satellite* osr_get_satellite(OSR_GNSS* gnss, long id) {
    for (auto i = 0; i < gnss->satellite_count; i++) {
        if (gnss->satellites[i].id == id) {
            return &gnss->satellites[i];
        }
    }

    return NULL;
}
