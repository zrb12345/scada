/**
********************************************************************************
* @file     dpm200.h
* @author   Diem
*
* @brief Dieses File enthaelt alle Definitionen und Deklarationen
*        welche vom Modul exportiert werden, und von anderen Modulen auf
* 	einer anderen CPU genutzt werden koennen.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

#ifndef DPM200__H 			/* Problemvermeidung bei mehr- */
#define DPM200__H 			/* maligem Inkludieren des Files */

#ifdef __cplusplus
extern "C" {
#endif

/*--- Defines ---*/

#define DPM_CMD_RAMINF	    1	    /* Abfragen der DP-RAM Charktere */
#define DPM_CMD_SETNET	    2	    /* Setzen der Net-Infostruktur */
#define DPM_CMD_INITDONE    3       /* Init vom Server bendet */
#define DPM_CMD_GETNETADDR  4       /* Abfragen der DP-RAM/Shadow/Lock Addressen */

 
/*--- Strukturen ---*/


/*--- Funktionsprototyping ---*/


/*--- Variablendefinitionen ---*/

#ifdef __cplusplus
}
#endif

#endif
