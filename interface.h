#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mariadb/mysql.h>
#include <unistd.h>

void close_error(MYSQL *con) // In order to avoid unnecessary repetition, we create a custom close_error() function. that returns the an error of something is worng in your input.
{
    fprintf(stderr, "%s\n", mysql_error(con)); // returns the error from the database of mariadb
    mysql_close(con);
    exit(1);
}
