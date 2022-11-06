#include <stdio.h>
#include <stdlib.h>
#include <mariadb/mysql.h>
#include <string.h>
#include <unistd.h>

char circuitRef[255];  // name of the columns in the table
char name[255];
char location[255];
char country[255];
float lat;
float lng;
int alt;
char url[255];
int raceId;
int constructorId;
int points;
char status[255];
char constructorRef[255];
char nationality[255];
float points;
int position;
char positionText[255];
int wins;
char driverRef[255];
int number;
char code[3];
char forename[255];
char surname[255];
char dob[20];
int driverId;
int lap;
char time[255];
int milliseconds;
int stop;
char duration[255];
char q1[255];
char q2[255];
char q3[255];
int year;
int round;
int circuitId;
char date[255];
int grid;
int positionOrder;
int laps;
int fastestLap;
int rank;
char fastestLapTime[255];
char fastestLapSpeed[255];
int statusId;
int targetId;
int win;
    

const char* close_error(MYSQL *con)// In order to avoid unnecessary repetition, we create a custom close_error() function. that returns the an error of something is worng in your input.
{
    fprintf(stderr, "%s\n", mysql_error(con));// returns the error from the database of mariadb
    mysql_close(con);
    exit(1);
}