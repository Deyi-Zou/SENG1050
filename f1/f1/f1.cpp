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
                               
    return 0;
}
