#ifndef RTE_ConsumptionApplication_H
#define RTE_ConsumptionApplication_H
#ifdef RTE_APPLICATION_HEADER_FILE
#error Multiple application header files included.
#endif /* RTE_APPLICATION_HEADER_FILE */
#define RTE_APPLICATION_HEADER_FILE

#include "Rte_ConsumptionApplication_Type.h"
#include "Rte_DataHandleType.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct Rte_CDS_ConsumptionApplication {
    uint8 Rte_Dummy;
};

typedef struct Rte_CDS_ConsumptionApplication Rte_CDS_ConsumptionApplication;
typedef const Rte_CDS_ConsumptionApplication * const Rte_Instance;
extern const Rte_CDS_ConsumptionApplication * const Rte_Inst_ConsumptionApplication;
#define ConsumptionApplication_START_SEC_CODE
#include "ConsumptionApplication_MemMap.h"

void EstimateConsumption(void);

#define ConsumptionApplication_STOP_SEC_CODE
#include "ConsumptionApplication_MemMap.h"



Std_ReturnType Rte_Read_TankPort_currentTankInML(sint32 *out);
Std_ReturnType Rte_Read_TankPort_lastTankInML(sint32 *out);
Std_ReturnType Rte_Read_TravelPort_estimatedKMRemaining(sint16 *out);
Std_ReturnType Rte_Write_TankPort_lastTankInML(sint32 lastTankInML);
Std_ReturnType Rte_Write_TravelPort_estimatedConsumption(sint32 estimatedConsumption);
#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */
#endif /* RTE_ConsumptionApplication_H */
