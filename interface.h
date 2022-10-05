#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mariadb/mysql.h>
#include <unistd.h>

void close_error(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}
