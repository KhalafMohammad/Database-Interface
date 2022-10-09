/* this program is made by Mohammad Khalaf
to view tables  and the data inside in SQL. it made in C-lang. programmer = Mohammad khalaf / 703190  */

#include <stdio.h>
#include <stdlib.h>
#include <mariadb/mysql.h>
#include <string.h>
#include <unistd.h>
#include "interface.h"// this the header that conatains the error function.




int main()
{
    
    MYSQL *con = mysql_init(NULL);// make connection with mariadb 
    MYSQL_ROW record;

    if (con == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "pipo", "theclown", "f1", 0, NULL, 0) == NULL)// here you include user name and password
    {
        close_error(con);// return error if it doesnt work
        mysql_close(con);
    }
    
    int m = 5;
    while ((m = 5))
    {

        int answer;// 1st question and the main interface

        printf("\nWelcome to mysql interface!!\n\n");
        printf("Choose 1,2,3 or 4 from the following:\n[1] Show all tables in db.\n[2] Use a table.\n[3] Show db version.\n[4] Quit?\n\n>>> ");
        scanf("%d", &answer);
        printf("\n");

        if (answer == 1) // show all the tables in the db
        {
            mysql_query(con, "show tables");
            MYSQL_RES *rs = mysql_store_result(con);

            if (rs == NULL)
            {
                close_error(con);
                mysql_close(con);
                return 1;
            }

            printf("tables in db:\n\n");
            while ((record = mysql_fetch_row(rs)))
            {
                printf("%s\n", record[0]);
                
            }
            sleep(3);
        }

        else if (answer == 2) // enter the name of the table that you want to view it's contents.
        {
            char table_name;

            printf("what table do you want to view?? enter the name of the table...\n>>> ");
            scanf("%s\n", &table_name);

            char input[1024];
            memset(input, '\0', sizeof(input));

            sprintf(input, "SELECT * FROM %s;\n", &table_name); // sends the changes to the db
            

            if (mysql_query(con, input) != 0)
            {
                close_error(con);
                mysql_close(con);
            }

            MYSQL_RES *result = mysql_store_result(con); // We get the result set using the mysql_store_result() function. The MYSQL_RES is a structure for holding a result set.

            if (result == NULL)
            {
                close_error(con);
                mysql_close(con);
            }

            int num_fields = mysql_num_fields(result);// We get the number of fields (columns) in the table.

            MYSQL_ROW row;
            MYSQL_FIELD *field; // The MYSQL_FIELD structure contains information about a field, such as the field's name, type and size.

            while ((row = mysql_fetch_row(result))) // We fetch the rows and print them to the screen.
            {
                for (int i = 0; i < num_fields; i++)
                {
                    if (i == 0)
                    {
                        while ((field = mysql_fetch_field(result))) // The first row contains the column headers. The mysql_fetch_field() call returns a MYSQL_FIELD structure. We get the column header names from this structure.
                        {
                            printf("%s ", field->name);
                        }

                        printf("\n");
                    }
                    printf("%s ", row[i] ? row[i] : "NULL");
                }

                printf("\n");
            }

            mysql_free_result(result);
            
        }

        else if (answer == 3) // this one shows you the current mysql version on your system.
        {
            mysql_query(con, "SELECT VERSION()");

            MYSQL_RES *rs = mysql_store_result(con);

            if (rs == NULL)
            {
                close_error(con);
                return 1;
            }

            if ((record = mysql_fetch_row(rs)))
            {
                printf("MySql Version: %s\n", record[0]);
                printf("\n\n\n");
            }
        }

        else if (answer == 4) // quits the program
        {
            printf("Quiting...\n\nDONE!\n\n");

            close_error(con);
            mysql_close(con); // exits the db and closes the connection 
        }

        else // if non of the above is entered its going to close the program.
        {
            close_error(con);
            mysql_close(con);
        }
    }
    
    close_error(con);
    exit(0);
}