#include "lpp.h"
#include "internal_lpp.h"

static GNSS_SupportList* build_support_list() {
    auto gnss_list = ALLOC_ZERO(GNSS_SupportList);
    asn_sequence_empty(&gnss_list->list);

    {
        auto element                        = ALLOC_ZERO(GNSS_SupportElement);
        element->gnss_ID.gnss_id            = GNSS_ID__gnss_id_gps;
        element->adr_Support                = false;
        element->velocityMeasurementSupport = true;
        asn_bit_string_set_length(&element->agnss_Modes.posModes, 8);
        asn_bit_string_set_reverse(&element->agnss_Modes.posModes,
                                   PositioningModes__posModes_ue_based, 1);
        asn_bit_string_set_reverse(&element->agnss_Modes.posModes,
                                   PositioningModes__posModes_ue_assisted, 1);

        auto ext               = ALLOC_ZERO(GNSS_SupportElement::GNSS_SupportElement__ext1);
        ext->ha_gnss_Modes_r15 = ALLOC_ZERO(PositioningModes);
        element->ext1          = ext;
        asn_bit_string_set_length(&ext->ha_gnss_Modes_r15->posModes, 8);
        asn_bit_string_set_reverse(&ext->ha_gnss_Modes_r15->posModes,
                                   PositioningModes__posModes_ue_based, 1);

        asn_bit_string_set_length(&element->gnss_Signals.gnss_SignalIDs, 8);
        asn_bit_string_set(&element->gnss_Signals.gnss_SignalIDs, 0, 1);
        asn_bit_string_set(&element->gnss_Signals.gnss_SignalIDs, 1, 1);
        asn_bit_string_set(&element->gnss_Signals.gnss_SignalIDs, 2, 1);
        asn_bit_string_set(&element->gnss_Signals.gnss_SignalIDs, 3, 1);
        asn_bit_string_set(&element->gnss_Signals.gnss_SignalIDs, 4, 1);
        asn_bit_string_set(&element->gnss_Signals.gnss_SignalIDs, 5, 1);
        asn_bit_string_set(&element->gnss_Signals.gnss_SignalIDs, 6, 1);
        asn_bit_string_set(&element->gnss_Signals.gnss_SignalIDs, 7, 1);
        asn_sequence_add(&gnss_list->list, element);
    }

    {
        auto element                        = ALLOC_ZERO(GNSS_SupportElement);
        element->gnss_ID.gnss_id            = GNSS_ID__gnss_id_glonass;
        element->adr_Support                = false;
        element->velocityMeasurementSupport = true;
        asn_bit_string_set_length(&element->agnss_Modes.posModes, 8);
        asn_bit_string_set_reverse(&element->agnss_Modes.posModes,
                                   PositioningModes__posModes_ue_based, 1);
        asn_bit_string_set_reverse(&element->agnss_Modes.posModes,
                                   PositioningModes__posModes_ue_assisted, 1);

        auto ext               = ALLOC_ZERO(GNSS_SupportElement::GNSS_SupportElement__ext1);
        ext->ha_gnss_Modes_r15 = ALLOC_ZERO(PositioningModes);
        element->ext1          = ext;
        asn_bit_string_set_length(&ext->ha_gnss_Modes_r15->posModes, 8);
        asn_bit_string_set_reverse(&ext->ha_gnss_Modes_r15->posModes,
                                   PositioningModes__posModes_ue_based, 1);

        asn_bit_string_set_length(&element->gnss_Signals.gnss_SignalIDs, 8);
        asn_bit_string_set(&element->gnss_Signals.gnss_SignalIDs, 3, 1);
        asn_bit_string_set(&element->gnss_Signals.gnss_SignalIDs, 4, 1);
        asn_bit_string_set(&element->gnss_Signals.gnss_SignalIDs, 5, 1);
        asn_bit_string_set(&element->gnss_Signals.gnss_SignalIDs, 6, 1);
        asn_bit_string_set(&element->gnss_Signals.gnss_SignalIDs, 7, 1);
        asn_sequence_add(&gnss_list->list, element);
    }

    {
        auto element                        = ALLOC_ZERO(GNSS_SupportElement);
        element->gnss_ID.gnss_id            = GNSS_ID__gnss_id_galileo;
        element->adr_Support                = false;
        element->velocityMeasurementSupport = true;
        asn_bit_string_set_length(&element->agnss_Modes.posModes, 8);
        asn_bit_string_set_reverse(&element->agnss_Modes.posModes,
                                   PositioningModes__posModes_ue_based, 1);
        asn_bit_string_set_reverse(&element->agnss_Modes.posModes,
                                   PositioningModes__posModes_ue_assisted, 1);

        auto ext               = ALLOC_ZERO(GNSS_SupportElement::GNSS_SupportElement__ext1);
        ext->ha_gnss_Modes_r15 = ALLOC_ZERO(PositioningModes);
        element->ext1          = ext;
        asn_bit_string_set_length(&ext->ha_gnss_Modes_r15->posModes, 8);
        asn_bit_string_set_reverse(&ext->ha_gnss_Modes_r15->posModes,
                                   PositioningModes__posModes_ue_based, 1);

        asn_bit_string_set_length(&element->gnss_Signals.gnss_SignalIDs, 8);
        asn_bit_string_set(&element->gnss_Signals.gnss_SignalIDs, 0, 1);
        asn_bit_string_set(&element->gnss_Signals.gnss_SignalIDs, 1, 1);
        asn_bit_string_set(&element->gnss_Signals.gnss_SignalIDs, 2, 1);
        asn_bit_string_set(&element->gnss_Signals.gnss_SignalIDs, 3, 1);
        asn_bit_string_set(&element->gnss_Signals.gnss_SignalIDs, 4, 1);
        asn_bit_string_set(&element->gnss_Signals.gnss_SignalIDs, 5, 1);
        asn_bit_string_set(&element->gnss_Signals.gnss_SignalIDs, 6, 1);
        asn_bit_string_set(&element->gnss_Signals.gnss_SignalIDs, 7, 1);
        asn_sequence_add(&gnss_list->list, element);
    }

    return gnss_list;
}

static AssistanceDataSupportList* build_assistance_support() {
    auto as = ALLOC_ZERO(AssistanceDataSupportList);

    // GNSS Common AD Support
    auto as_ext1 =
        ALLOC_ZERO(GNSS_CommonAssistanceDataSupport::GNSS_CommonAssistanceDataSupport__ext1);

    auto rtk_reference_station_support = ALLOC_ZERO(GNSS_RTK_ReferenceStationInfoSupport_r15);
    auto rtk_auxiliary_station_support = ALLOC_ZERO(GNSS_RTK_AuxiliaryStationDataSupport_r15);
    as_ext1->gnss_RTK_ReferenceStationInfoSupport_r15 = rtk_reference_station_support;
    as_ext1->gnss_RTK_AuxiliaryStationDataSupport_r15 = rtk_auxiliary_station_support;
    as->gnss_CommonAssistanceDataSupport.ext1         = as_ext1;

    // GNSS Generic AD Support
    auto generic_assistance = &as->gnss_GenericAssistanceDataSupport;
    asn_sequence_empty(&generic_assistance->list);

    {
        auto gps_assistance             = ALLOC_ZERO(GNSS_GenericAssistDataSupportElement);
        gps_assistance->gnss_ID.gnss_id = GNSS_ID__gnss_id_gps;
        gps_assistance->gnss_AcquisitionAssistanceSupport =
            ALLOC_ZERO(GNSS_AcquisitionAssistanceSupport);

        auto ext = ALLOC_ZERO(
            GNSS_GenericAssistDataSupportElement::GNSS_GenericAssistDataSupportElement__ext2);
        gps_assistance->ext2                  = ext;
        ext->gnss_RTK_ObservationsSupport_r15 = ALLOC_ZERO(GNSS_RTK_ObservationsSupport_r15_t);
        auto signals = &ext->gnss_RTK_ObservationsSupport_r15->gnssSignalIDs_r15.gnss_SignalIDs;
        asn_bit_string_set_length(signals, 8);  // 0xFF
        asn_bit_string_set(signals, 0, 1);
        asn_bit_string_set(signals, 1, 1);
        asn_bit_string_set(signals, 2, 1);
        asn_bit_string_set(signals, 3, 1);
        asn_bit_string_set(signals, 4, 1);
        asn_bit_string_set(signals, 5, 1);
        asn_bit_string_set(signals, 6, 1);
        asn_bit_string_set(signals, 7, 1);

        ext->gnss_RTK_ResidualsSupport_r15 = ALLOC_ZERO(GNSS_RTK_ResidualsSupport_r15_t);
        GNSS_Link_CombinationsList_r15_t* link_list =
            &ext->gnss_RTK_ResidualsSupport_r15->link_combinations_support_r15;
        asn_sequence_empty(&link_list->list);

        {
            GNSS_Link_Combinations_r15_t* link = ALLOC_ZERO(GNSS_Link_Combinations_r15_t);
            link->l1_r15.gnss_FrequencyID_r15  = 0;
            link->l2_r15.gnss_FrequencyID_r15  = 1;
            asn_sequence_add(&link_list->list, link);
        }

        asn_sequence_add(&generic_assistance->list, gps_assistance);
    }

    {
        auto glonass_assistance             = ALLOC_ZERO(GNSS_GenericAssistDataSupportElement_t);
        glonass_assistance->gnss_ID.gnss_id = GNSS_ID__gnss_id_glonass;
        glonass_assistance->gnss_AcquisitionAssistanceSupport =
            ALLOC_ZERO(GNSS_AcquisitionAssistanceSupport_t);

        auto ext = ALLOC_ZERO(
            GNSS_GenericAssistDataSupportElement::GNSS_GenericAssistDataSupportElement__ext2);
        glonass_assistance->ext2              = ext;
        ext->gnss_RTK_ObservationsSupport_r15 = ALLOC_ZERO(GNSS_RTK_ObservationsSupport_r15_t);
        auto signals = &ext->gnss_RTK_ObservationsSupport_r15->gnssSignalIDs_r15.gnss_SignalIDs;
        asn_bit_string_set_length(signals, 8);  // 0xFF
        asn_bit_string_set(signals, 3, 1);
        asn_bit_string_set(signals, 4, 1);
        asn_bit_string_set(signals, 5, 1);
        asn_bit_string_set(signals, 6, 1);
        asn_bit_string_set(signals, 7, 1);

        ext->glo_RTK_BiasInformationSupport_r15 = ALLOC_ZERO(GLO_RTK_BiasInformationSupport_r15_t);
        ext->gnss_RTK_ResidualsSupport_r15      = ALLOC_ZERO(GNSS_RTK_ResidualsSupport_r15_t);
        auto link_list = &ext->gnss_RTK_ResidualsSupport_r15->link_combinations_support_r15;
        asn_sequence_empty(&link_list->list);

        {
            auto link                         = ALLOC_ZERO(GNSS_Link_Combinations_r15_t);
            link->l1_r15.gnss_FrequencyID_r15 = 0;
            link->l2_r15.gnss_FrequencyID_r15 = 1;
            asn_sequence_add(&link_list->list, link);
        }

        asn_sequence_add(&generic_assistance->list, glonass_assistance);
    }

    {
        auto galileo_assistance             = ALLOC_ZERO(GNSS_GenericAssistDataSupportElement);
        galileo_assistance->gnss_ID.gnss_id = GNSS_ID__gnss_id_galileo;
        galileo_assistance->gnss_AcquisitionAssistanceSupport =
            ALLOC_ZERO(GNSS_AcquisitionAssistanceSupport);

        auto ext = ALLOC_ZERO(
            GNSS_GenericAssistDataSupportElement::GNSS_GenericAssistDataSupportElement__ext2);
        galileo_assistance->ext2              = ext;
        ext->gnss_RTK_ObservationsSupport_r15 = ALLOC_ZERO(GNSS_RTK_ObservationsSupport_r15_t);
        auto signals = &ext->gnss_RTK_ObservationsSupport_r15->gnssSignalIDs_r15.gnss_SignalIDs;
        asn_bit_string_set_length(signals, 8);  // 0xFF
        asn_bit_string_set(signals, 0, 1);
        asn_bit_string_set(signals, 1, 1);
        asn_bit_string_set(signals, 2, 1);
        asn_bit_string_set(signals, 3, 1);
        asn_bit_string_set(signals, 4, 1);
        asn_bit_string_set(signals, 5, 1);
        asn_bit_string_set(signals, 6, 1);
        asn_bit_string_set(signals, 7, 1);

        ext->gnss_RTK_ResidualsSupport_r15 = ALLOC_ZERO(GNSS_RTK_ResidualsSupport_r15_t);
        auto link_list = &ext->gnss_RTK_ResidualsSupport_r15->link_combinations_support_r15;
        asn_sequence_empty(&link_list->list);

        {
            GNSS_Link_Combinations_r15_t* link = ALLOC_ZERO(GNSS_Link_Combinations_r15_t);
            link->l1_r15.gnss_FrequencyID_r15  = 0;
            link->l2_r15.gnss_FrequencyID_r15  = 1;
            asn_sequence_add(&link_list->list, link);
        }

        asn_sequence_add(&generic_assistance->list, galileo_assistance);
    }

    return as;
}

OCTET_STRING* lpp_provide_capabilities(LPP_Transaction* transaction) {
    auto message = lpp_create(transaction, LPP_MessageBody__c1_PR_provideCapabilities);
    auto body    = message->lpp_MessageBody;

    auto cext               = &body->choice.c1.choice.provideCapabilities.criticalExtensions;
    cext->present           = ProvideCapabilities__criticalExtensions_PR_c1;
    cext->choice.c1.present = ProvideCapabilities__criticalExtensions__c1_PR_provideCapabilities_r9;

    auto ext2 = ALLOC_ZERO(A_GNSS_ProvideCapabilities::A_GNSS_ProvideCapabilities__ext2);
    ext2->periodicAssistanceData_r15 = asn_bit_string_create();
    asn_bit_string_set_length(ext2->periodicAssistanceData_r15, 8);  // 0xFF
    asn_bit_string_set_reverse(
        ext2->periodicAssistanceData_r15,
        A_GNSS_ProvideCapabilities__ext2__periodicAssistanceData_r15_solicited, 1);
    asn_bit_string_set_reverse(
        ext2->periodicAssistanceData_r15,
        A_GNSS_ProvideCapabilities__ext2__periodicAssistanceData_r15_unsolicited, 1);

    auto gnss_capabilities                       = ALLOC_ZERO(A_GNSS_ProvideCapabilities);
    gnss_capabilities->assistanceDataSupportList = build_assistance_support();
    gnss_capabilities->gnss_SupportList          = build_support_list();
    gnss_capabilities->ext2                      = ext2;

    auto ecid_capabilities = ALLOC_ZERO(ECID_ProvideCapabilities);
    asn_bit_string_set_length(&ecid_capabilities->ecid_MeasSupported, 8);
    asn_bit_string_set_reverse(&ecid_capabilities->ecid_MeasSupported,
                               ECID_ProvideCapabilities__ecid_MeasSupported_rsrpSup, 1);
    asn_bit_string_set_reverse(&ecid_capabilities->ecid_MeasSupported,
                               ECID_ProvideCapabilities__ecid_MeasSupported_rsrqSup, 1);

    auto pcr9                        = &cext->choice.c1.choice.provideCapabilities_r9;
    pcr9->a_gnss_ProvideCapabilities = gnss_capabilities;
    pcr9->ecid_ProvideCapabilities   = ecid_capabilities;

    auto result = lpp_encode(message);
    lpp_destroy(message);
    return result;
}