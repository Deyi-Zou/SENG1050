/* ============================================================= */
/* FILE : f1.cpp                                                 */
/* PROJECT : Focus Assignment 1                                  */
/* PROGRAMMER : Deyi Zou                                         */
/* FIRST VERSION : 2024-05-07                                    */
/* DESCRIPTION : takes in information about flights and          */
/*               use dynamic memory to store the destination     */ 
/*               and date in an array of structs to be displayed */
/* ============================================================= */
#include <stdio.h>
#include <string.h>
#include <malloc.h>	
#pragma warning(disable: 4996)

#define MAX_STRING_LENGTH 31

struct FlightInfo {
    char* destination;
    char* date;
};

void fillFlightInfo(FlightInfo* flightsPtr, char* userTypeDestination, char* userTypeDate);
void printFlightInfo(FlightInfo flights[]);

int main(void){
    struct FlightInfo flights[10] = { 0 };
    FlightInfo* flightsPtr = flights;

    char userTypeDestination[MAX_STRING_LENGTH];
    char userTypeDate[MAX_STRING_LENGTH];

    printf("Please input ten pairs of flights information:\n");

    int i;
    int count = 10;
    for (i = 0; i < count; i++)
    {
        fgets(userTypeDestination, MAX_STRING_LENGTH, stdin);
        char* whereCR = strchr(userTypeDestination, '\n'); // clear CR
        if (whereCR != NULL)
        {
            *whereCR = '\0';
        }
        fgets(userTypeDate, MAX_STRING_LENGTH, stdin);
        char* whereCR1 = strchr(userTypeDate, '\n');
        if (whereCR1 != NULL)
        {
            *whereCR1 = '\0';
        }
        fillFlightInfo(&flightsPtr[i], userTypeDestination, userTypeDate);

    }

    printFlightInfo(flights);

    for (i = 0; i < count; i++)
    {
        free(flightsPtr[i].destination);
        free(flightsPtr[i].date);
    }
                               
    return 0;
}


/* ================================================================ */
/* FUNCTION : fillFlightInfo( flightsPtr, destination, date)        */
/* PURPOSE  : This function is to allocate dynamic memory for       */
/*            the fields of flight struct                           */
/* INPUTS   : temPtr - a pointer to the flights struct array        */
/*            userTypeDestination - a string containing info of     */
/*                                  destination                     */
/*            userTypeDate - a string containing info of date       */
/* RETURNS  : none                                                  */
/* ================================================================ */

void fillFlightInfo(FlightInfo* flightsPtr, char* userTypeDestination, char* userTypeDate) {

    flightsPtr->destination = (char*)malloc(strlen(userTypeDestination) + 1);
    if (flightsPtr->destination == NULL) {
        printf("Out of memory\n");
        return;
    }
    strcpy(flightsPtr->destination, userTypeDestination);

    flightsPtr->date = (char*)malloc(strlen(userTypeDate) + 1);
    if (flightsPtr->date == NULL) {
        printf("Out of memory\n");
        return;
    }
    strcpy(flightsPtr->date, userTypeDate);

}




/* ======================================================== */
/* FUNCTION : printFlightInfo( flights)                     */
/* PURPOSE  : This function shows the info of each flight   */
/*            in the struct                                 */
/* INPUTS   : flights - a struct array contains flight info */
/* RETURNS  : none                                          */
/* ======================================================== */

void printFlightInfo(FlightInfo flights[]) {
    int i;
    int count = 10;
    for (i = 0; i < count; i++)
    {
        printf("%-35s", flights[i].destination);
        printf("%35s\n", flights[i].date);
    }
}
