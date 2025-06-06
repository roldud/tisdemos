/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Implementation template
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This implementation is incomplete and is neither intended nor qualified for use in series production
 *                without applying suitable quality measures. The implementation as well as any of its modifications
 *                must be tested with diligent care and must comply with all quality requirements which are necessary
 *                according to the state of the art before its use.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  ConsumptionApplication.c
 *        SW-C Type:  ConsumptionApplication
 *  Generation Time:  2024-03-15 13:37:36
 *
 *        Generator:  MICROSAR RTE ContractPhase Generator Version 3.14.22
 *                    RTE Core Version 4.31.0
 *          License:  DVSwcGen
 *
 *      Description:  C-Code implementation template for SW-C <ConsumptionApplication>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_ConsumptionApplication.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * sint16: Integer in interval [-32768...32767] (standard type)
 * sint32: Integer in interval [-2147483648...2147483647] (standard type)
 *
 *********************************************************************************************************************/


#define ConsumptionApplication_START_SEC_CODE
#include "ConsumptionApplication_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EstimateConsumption
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_TankPort_currentTankInML(sint32 *data)
 *   Std_ReturnType Rte_Read_TankPort_lastTankInML(sint32 *data)
 *   Std_ReturnType Rte_Read_TravelPort_estimatedKMRemaining(sint16 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_TankPort_lastTankInML(sint32 data)
 *   Std_ReturnType Rte_Write_TravelPort_estimatedConsumption(sint32 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EstimateConsumption_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ConsumptionApplication_CODE) EstimateConsumption(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EstimateConsumption
 *********************************************************************************************************************/

  // Let's assume this runnable is run once every km.
  sint32 currentTank;
  sint32 lastTank;
  sint32 consumptionForOneKM;
  sint32 estimatedConsumption;
  sint16 remainingDistance;

  Rte_Read_TankPort_currentTankInML(&currentTank);
  Rte_Read_TankPort_lastTankInML(&lastTank);
  Rte_Read_TravelPort_estimatedKMRemaining(&remainingDistance);
  
  consumptionForOneKM = lastTank - currentTank;
  estimatedConsumption = consumptionForOneKM * remainingDistance;
  
  Rte_Write_TankPort_lastTankInML(currentTank);
  Rte_Write_TravelPort_estimatedConsumption(estimatedConsumption);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define ConsumptionApplication_STOP_SEC_CODE
#include "ConsumptionApplication_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
