/* This file has been generated.*/
#include "Rte_ConsumptionApplication.h"


#ifdef __TRUSTINSOFT_ANALYZER__
#include <tis_builtin.h>
#endif
#include <float.h>
#include <stddef.h>
#include <math.h>

const Std_ReturnType __tis_Async_Call_results[] =
{
#ifdef RTE_E_OK
    RTE_E_OK,
#endif
#ifdef RTE_E_LIMIT
    RTE_E_LIMIT,
#endif
#ifdef RTE_E_TRANSFORMER_LIMIT
    RTE_E_TRANSFORMER_LIMIT,
#endif
#ifdef RTE_E_HARD_TRANSFORMER_ERROR
    RTE_E_HARD_TRANSFORMER_ERROR,
#endif
#ifdef RTE_E_SOFT_TRANSFORMER_ERROR
    RTE_E_SOFT_TRANSFORMER_ERROR,
#endif
#ifdef RTE_E_COM_STOPPED
    RTE_E_COM_STOPPED,
#endif
#ifdef RTE_E_UNCONNECTED
    RTE_E_UNCONNECTED,
#endif
#ifdef RTE_E_SEG_FAULT
    RTE_E_SEG_FAULT,
#endif
#ifdef RTE_E_COM_BUSY
    RTE_E_COM_BUSY,
#endif
};

const Std_ReturnType __tis_Sync_Call_results[] =
{
#ifdef RTE_E_OK
    RTE_E_OK,
#endif
#ifdef RTE_E_IN_EXCLUSIVE_AREA
    RTE_E_IN_EXCLUSIVE_AREA,
#endif
#ifdef RTE_E_TRANSFORMER_LIMIT
    RTE_E_TRANSFORMER_LIMIT,
#endif
#ifdef RTE_E_HARD_TRANSFORMER_ERROR
    RTE_E_HARD_TRANSFORMER_ERROR,
#endif
#ifdef RTE_E_SOFT_TRANSFORMER_ERROR
    RTE_E_SOFT_TRANSFORMER_ERROR,
#endif
#ifdef RTE_E_COM_STOPPED
    RTE_E_COM_STOPPED,
#endif
#ifdef RTE_E_TIMEOUT
    RTE_E_TIMEOUT,
#endif
#ifdef RTE_E_UNCONNECTED
    RTE_E_UNCONNECTED,
#endif
#ifdef RTE_E_SEG_FAULT
    RTE_E_SEG_FAULT,
#endif
#ifdef RTE_E_COM_BUSY
    RTE_E_COM_BUSY,
#endif
};

const Std_ReturnType __tis_Feedback_blocking_results[] =
{
#ifdef RTE_E_NO_DATA
    RTE_E_NO_DATA,
#endif
#ifdef RTE_E_COM_STOPPED
    RTE_E_COM_STOPPED,
#endif
#ifdef RTE_E_TIMEOUT
    RTE_E_TIMEOUT,
#endif
#ifdef RTE_E_TRANSMIT_ACK
    RTE_E_TRANSMIT_ACK,
#endif
#ifdef RTE_E_UNCONNECTED
    RTE_E_UNCONNECTED,
#endif
#ifdef RTE_E_IN_EXCLUSIVE_AREA
    RTE_E_IN_EXCLUSIVE_AREA,
#endif
#ifdef RTE_E_HARD_TRANSFORMER_ERROR
    RTE_E_HARD_TRANSFORMER_ERROR,
#endif
#ifdef RTE_E_SOFT_TRANSFORMER_ERROR
    RTE_E_SOFT_TRANSFORMER_ERROR,
#endif
};

const Std_ReturnType __tis_Feedback_non_blocking_results[] =
{
#ifdef RTE_E_NO_DATA
    RTE_E_NO_DATA,
#endif
#ifdef RTE_E_COM_STOPPED
    RTE_E_COM_STOPPED,
#endif
#ifdef RTE_E_TIMEOUT
    RTE_E_TIMEOUT,
#endif
#ifdef RTE_E_TRANSMIT_ACK
    RTE_E_TRANSMIT_ACK,
#endif
#ifdef RTE_E_UNCONNECTED
    RTE_E_UNCONNECTED,
#endif
#ifdef RTE_E_HARD_TRANSFORMER_ERROR
    RTE_E_HARD_TRANSFORMER_ERROR,
#endif
#ifdef RTE_E_SOFT_TRANSFORMER_ERROR
    RTE_E_SOFT_TRANSFORMER_ERROR,
#endif
};

const Std_ReturnType __tis_IFeedback_results[] =
{
#ifdef RTE_E_NO_DATA
    RTE_E_NO_DATA,
#endif
#ifdef RTE_E_COM_STOPPED
    RTE_E_COM_STOPPED,
#endif
#ifdef RTE_E_TIMEOUT
    RTE_E_TIMEOUT,
#endif
#ifdef RTE_E_TRANSMIT_ACK
    RTE_E_TRANSMIT_ACK,
#endif
#ifdef RTE_E_UNCONNECTED
    RTE_E_UNCONNECTED,
#endif
#ifdef RTE_E_HARD_TRANSFORMER_ERROR
    RTE_E_HARD_TRANSFORMER_ERROR,
#endif
#ifdef RTE_E_SOFT_TRANSFORMER_ERROR
    RTE_E_SOFT_TRANSFORMER_ERROR,
#endif
};

const Std_ReturnType __tis_Invalidate_results[] =
{
#ifdef RTE_E_OK
    RTE_E_OK,
#endif
#ifdef RTE_E_COM_STOPPED
    RTE_E_COM_STOPPED,
#endif
#ifdef RTE_E_HARD_TRANSFORMER_ERROR
    RTE_E_HARD_TRANSFORMER_ERROR,
#endif
#ifdef RTE_E_SOFT_TRANSFORMER_ERROR
    RTE_E_SOFT_TRANSFORMER_ERROR,
#endif
};

const Std_ReturnType __tis_Read_results[] =
{
#ifdef RTE_E_OK
    RTE_E_OK,
#endif
#ifdef RTE_E_INVALID
    RTE_E_INVALID,
#endif
#ifdef RTE_E_MAX_AGE_EXCEEDED
    RTE_E_MAX_AGE_EXCEEDED,
#endif
#ifdef RTE_E_NEVER_RECEIVED
    RTE_E_NEVER_RECEIVED,
#endif
#ifdef RTE_E_OUT_OF_RANGE
    RTE_E_OUT_OF_RANGE,
#endif
#ifdef RTE_E_COM_BUSY
    RTE_E_COM_BUSY,
#endif
#ifdef RTE_E_COM_STOPPED
    RTE_E_COM_STOPPED,
#endif
#ifdef RTE_E_UNCONNECTED
    RTE_E_UNCONNECTED,
#endif
#ifdef RTE_E_HARD_TRANSFORMER_ERROR
    RTE_E_HARD_TRANSFORMER_ERROR,
#endif
#ifdef RTE_E_SOFT_TRANSFORMER_ERROR
    RTE_E_SOFT_TRANSFORMER_ERROR,
#endif
};

const Std_ReturnType __tis_Receive_results[] =
{
#ifdef RTE_E_OK
    RTE_E_OK,
#endif
#ifdef RTE_E_NO_DATA
    RTE_E_NO_DATA,
#endif
#ifdef RTE_E_TIMEOUT
    RTE_E_TIMEOUT,
#endif
#ifdef RTE_E_LOST_DATA
    RTE_E_LOST_DATA,
#endif
#ifdef RTE_E_IN_EXCLUSIVE_AREA
    RTE_E_IN_EXCLUSIVE_AREA,
#endif
#ifdef RTE_E_HARD_TRANSFORMER_ERROR
    RTE_E_HARD_TRANSFORMER_ERROR,
#endif
#ifdef RTE_E_SOFT_TRANSFORMER_ERROR
    RTE_E_SOFT_TRANSFORMER_ERROR,
#endif
};

const Std_ReturnType __tis_Result_results[] =
{
#ifdef RTE_E_OK
    RTE_E_OK,
#endif
#ifdef RTE_E_TRANSFORMER_LIMIT
    RTE_E_TRANSFORMER_LIMIT,
#endif
#ifdef RTE_E_HARD_TRANSFORMER_LIMIT
    RTE_E_HARD_TRANSFORMER_LIMIT,
#endif
#ifdef RTE_E_HARD_TRANSFORMER_ERROR
    RTE_E_HARD_TRANSFORMER_ERROR,
#endif
#ifdef RTE_E_NO_DATA
    RTE_E_NO_DATA,
#endif
#ifdef RTE_E_TIMEOUT
    RTE_E_TIMEOUT,
#endif
#ifdef RTE_E_COM_STOPPED
    RTE_E_COM_STOPPED,
#endif
#ifdef RTE_E_UNCONNECTED
    RTE_E_UNCONNECTED,
#endif
#ifdef RTE_E_IN_EXCLUSIVE_AREA
    RTE_E_IN_EXCLUSIVE_AREA,
#endif
#ifdef RTE_E_SEG_FAULT
    RTE_E_SEG_FAULT,
#endif
#ifdef RTE_E_COM_BUSY
    RTE_E_COM_BUSY,
#endif
};

const Std_ReturnType __tis_Send_results[] =
{
#ifdef RTE_E_OK
    RTE_E_OK,
#endif
#ifdef RTE_E_COM_STOPPED
    RTE_E_COM_STOPPED,
#endif
#ifdef RTE_E_LIMIT
    RTE_E_LIMIT,
#endif
#ifdef RTE_E_SEG_FAULT
    RTE_E_SEG_FAULT,
#endif
#ifdef RTE_E_COM_BUSY
    RTE_E_COM_BUSY,
#endif
#ifdef RTE_E_HARD_TRANSFORMER_ERROR
    RTE_E_HARD_TRANSFORMER_ERROR,
#endif
#ifdef RTE_E_SOFT_TRANSFORMER_ERROR
    RTE_E_SOFT_TRANSFORMER_ERROR,
#endif
};

const Std_ReturnType __tis_SwitchAck_blocking_results[] =
{
#ifdef RTE_E_TIMEOUT
    RTE_E_TIMEOUT,
#endif
#ifdef RTE_E_TRANSMIT_ACK
    RTE_E_TRANSMIT_ACK,
#endif
#ifdef RTE_E_UNCONNECTED
    RTE_E_UNCONNECTED,
#endif
#ifdef RTE_E_IN_EXCLUSIVE_AREA
    RTE_E_IN_EXCLUSIVE_AREA,
#endif
};

const Std_ReturnType __tis_SwitchAck_non_blocking_results[] =
{
#ifdef RTE_E_TIMEOUT
    RTE_E_TIMEOUT,
#endif
#ifdef RTE_E_TRANSMIT_ACK
    RTE_E_TRANSMIT_ACK,
#endif
#ifdef RTE_E_UNCONNECTED
    RTE_E_UNCONNECTED,
#endif
#ifdef RTE_E_NO_DATA
    RTE_E_NO_DATA,
#endif
};

const Std_ReturnType __tis_Trigger_results[] =
{
#ifdef RTE_E_OK
    RTE_E_OK,
#endif
#ifdef RTE_E_LIMIT
    RTE_E_LIMIT,
#endif
};

const Std_ReturnType __tis_Write_results[] =
{
#ifdef RTE_E_OK
    RTE_E_OK,
#endif
#ifdef RTE_E_COM_STOPPED
    RTE_E_COM_STOPPED,
#endif
#ifdef RTE_E_SEG_FAULT
    RTE_E_SEG_FAULT,
#endif
#ifdef RTE_E_COM_BUSY
    RTE_E_COM_BUSY,
#endif
#ifdef RTE_E_HARD_TRANSFORMER_ERROR
    RTE_E_HARD_TRANSFORMER_ERROR,
#endif
#ifdef RTE_E_SOFT_TRANSFORMER_ERROR
    RTE_E_SOFT_TRANSFORMER_ERROR,
#endif
};

const Std_ReturnType __tis_IWrite_results[] =
{
#ifdef RTE_E_OK
    RTE_E_OK,
#endif
};

void tis_autosar_unknown_sint32(sint32 *data) {
    tis_make_unknown(data, sizeof(*data));
}

void tis_autosar_constraint_tank_contenant_sint32(sint32 *data) {
    *data = tis_unsigned_long_long_interval(0ULL, 100000ULL);
}

void tis_autosar_unknown_sint16(sint16 *data) {
    tis_make_unknown(data, sizeof(*data));
}

void tis_autosar_constraint_zero_to_thousand_sint16(sint16 *data) {
    *data = tis_unsigned_long_long_interval(0ULL, 1000ULL);
}

void tis_autosar_constraint_zero_to_max_sint32(sint32 *data) {
    *data = tis_unsigned_long_long_interval(0ULL, 2147483647ULL);
}

Std_ReturnType Rte_Read_TankPort_currentTankInML(sint32 *out){
    Std_ReturnType result = __tis_Read_results[tis_interval(0, sizeof(__tis_Read_results)/sizeof(*__tis_Read_results) - 1)];

    if (result == RTE_E_OK)
    {
        tis_autosar_constraint_tank_contenant_sint32(out);
    }
    else
    {
        tis_autosar_unknown_sint32(out);
    }
    return result;
}

Std_ReturnType Rte_Read_TankPort_lastTankInML(sint32 *out){
    Std_ReturnType result = __tis_Read_results[tis_interval(0, sizeof(__tis_Read_results)/sizeof(*__tis_Read_results) - 1)];

    if (result == RTE_E_OK)
    {
        tis_autosar_constraint_tank_contenant_sint32(out);
    }
    else
    {
        tis_autosar_unknown_sint32(out);
    }
    return result;
}

Std_ReturnType Rte_Read_TravelPort_estimatedKMRemaining(sint16 *out){
    Std_ReturnType result = __tis_Read_results[tis_interval(0, sizeof(__tis_Read_results)/sizeof(*__tis_Read_results) - 1)];

    if (result == RTE_E_OK)
    {
        tis_autosar_constraint_zero_to_thousand_sint16(out);
    }
    else
    {
        tis_autosar_unknown_sint16(out);
    }
    return result;
}

/*@
    requires 0 <= lastTankInML <= 100000;
*/
Std_ReturnType Rte_Write_TankPort_lastTankInML(sint32 lastTankInML){
    Std_ReturnType result = __tis_Write_results[tis_interval(0, sizeof(__tis_Write_results)/sizeof(*__tis_Write_results) - 1)];

    return result;
}

/*@
    requires 0 <= estimatedConsumption <= 2147483647;
*/
Std_ReturnType Rte_Write_TravelPort_estimatedConsumption(sint32 estimatedConsumption){
    Std_ReturnType result = __tis_Write_results[tis_interval(0, sizeof(__tis_Write_results)/sizeof(*__tis_Write_results) - 1)];

    return result;
}



