#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <mariadb/mysql.h>
#include <string.h>
#include <unistd.h>
#include "main.c"

extern char circuitRef[255];  // name of the columns in the table
extern char name[255];
extern char location[255];
extern char country[255];
extern float lat;
extern float lng;
extern int alt;
extern char url[255];
extern int raceId;
extern int constructorId;
extern int points;
extern char status[255];
extern char constructorRef[255];
extern char nationality[255];
extern float points;
extern int position;
extern char positionText[255];
extern int wins;
extern char driverRef[255];
extern int number;
extern char code[3];
extern char forename[255];
extern char surname[255];
extern char dob[20];
extern int driverId;
extern int lap;
extern char time[255];
extern int milliseconds;
extern int stop;
extern char duration[255];
extern char q1[255];
extern char q2[255];
extern char q3[255];
extern int year;
extern int round;
extern int circuitId;
extern char date[255];
extern int grid;
extern int positionOrder;
extern int laps;
extern int fastestLap;
extern int rank;
extern char fastestLapTime[255];
extern char fastestLapSpeed[255];
extern int statusId;
extern int targetId;
extern int win;
    

const char* close_error(MYSQL *con); // In order to avoid unnecessary repetition, we create a custom close_error() function. that returns the an error of something is worng in your input.