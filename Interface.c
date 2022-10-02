/* this program is made by Mohammad Khalaf
to view tables  and the data inside in SQL. it made in C-lang. programmer = Mohammad khalaf / 703190  */

#include <stdio.h>
#include <stdlib.h>
#include <mariadb/mysql.h>
#include <string.h>

void close_error(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

int main()
{
    
    MYSQL *con = mysql_init(NULL);
    MYSQL_ROW record;

    if (con == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "pipo", "theclown", "f1", 0, NULL, 0) == NULL)
    {
        close_error(con);
    }
    
    int m = 5;
    while ((m = 5))
    {

        int answer;

        printf("\nWelcome to mysql interface!!\n\n");
        printf("Choose 1,2,3 or 4 from the following:\n[1] Show data from tables.\n[2] Use a table.\n[3] Show db version.\n[4] Quit?\n\n>>> ");
        scanf("%d", &answer);
        printf("\n");

        if (answer == 1)
        {
            mysql_query(con, "show tables");
            MYSQL_RES *rs = mysql_store_result(con);

            if (rs == NULL)
            {
                close_error(con);
                return 1;
            }

            printf("tables in db:\n\n");
            while ((record = mysql_fetch_row(rs)))
            {
                printf("%s\n", record[0]);
            }
        }

        else if (answer == 2)
        {
            char table_name;

            printf("what table do you want to view?? enter the name of the table...\n>>> ");
            scanf("%s\n", &table_name);

            char input[1024];
            memset(input, '\0', sizeof(input));

            sprintf(input, "SELECT * FROM %s;\n", &table_name);
            // printf("current input is %s\n", input);
            // close_error(0);

            if (mysql_query(con, input) != 0)
            {
                close_error(con);
            }

            MYSQL_RES *result = mysql_store_result(con);

            if (result == NULL)
            {
                close_error(con);
            }

            int num_fields = mysql_num_fields(result);

            MYSQL_ROW row;
            MYSQL_FIELD *field;

            while ((row = mysql_fetch_row(result)))
            {
                for (int i = 0; i < num_fields; i++)
                {
                    if (i == 0)
                    {
                        while ((field = mysql_fetch_field(result)))
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
            // close_error(con);
        }

        else if (answer == 3)
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

        else if (answer == 4)
        {
            printf("Quiting...\n\nDONE!\n\n");

            close_error(con);
        }

        else
        {
            close_error(con);
        }
    }
    close_error(con);
    exit(0);
}
