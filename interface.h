#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <mariadb/mysql.h>
#include <string.h>
#include <unistd.h>
#include "error.h"

const char* close_error(MYSQL *con); // In order to avoid unnecessary repetition, we create a custom close_error() function. that returns the an error of something is worng in your input.