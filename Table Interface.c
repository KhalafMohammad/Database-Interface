#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mariadb/mysql.h>
#include <unistd.h>

#define DEBUG
#define maximum_array 3000

void close_error(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

int main()
{
    char table_name[10] = "circuits";
    char circuitRef[255];
    char name[255];
    char location[255];
    char country[255];
    float lat;
    float lng;
    int alt;
    char url[255];
    
    
    MYSQL *con = mysql_init(NULL);
    MYSQL_ROW row;
    MYSQL_FIELD *field;
    
    // MYSQL_ROW record;

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
        int answer1a;
        printf("\nHello!!\nThis is the interface that operate the table %s.\n\n", table_name);
        usleep(100);
        printf("choose 1,2,3,4 or 5 of what do you want to do?\n");
        sleep(1);
        printf("[1] View table.\n[2] Add to table.\n[3] Modify table.\n[4] Delete data.\n[5] quit.\n>>> ");
        scanf("%d", &answer1a);
        printf("\n");

        if (answer1a == 1)
        {
            char table_view[maximum_array];
            memset(table_view, '\0', sizeof(table_view));
            sprintf(table_view, "SELECT * FROM %s", table_name);
            mysql_query(con, table_view);
            

            MYSQL_RES *result = mysql_store_result(con);

            if (result == NULL)
            {
                close_error(con);
            }

            int num_fields = mysql_num_fields(result);


            while ((row = mysql_fetch_row(result)))
            {
                for(int i = 0; i < num_fields; i++)
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
            sleep(3);
            // close_error(con);
        }
        else if(answer1a == 2)
        {
            printf("what do you want to insert?\nAnswer the following quistions with what you want to insert into the table.\n");
            sleep(2);

            printf("Insert into circuitRef?\n>>> ");
            scanf("%s", circuitRef);
            sleep(1);

            printf("Insert into name?\n>>> ");
            scanf("%s", name);
            sleep(1);

            printf("Insert into location?\n>>> ");
            scanf("%s", location);
            sleep(1);

            printf("Insert into country?\n>>> ");
            scanf("%s", country);
            sleep(1);

            printf("Insert into lat?\n>>> ");
            scanf("%f", &lat);
            sleep(1);

            printf("Insert into lng?\n>>> ");
            scanf("%f", &lng);
            sleep(1);

            printf("Insert into alt?\n>>> ");
            scanf("%d", &alt);
            sleep(1);

            printf("Insert into url?\n>>> ");
            scanf("%s", url);
            sleep(1);

            // printf("%s %s %s %s %f %f %d %s", circuitRef, name, location, country, lat, lng, alt, url);
            char added_circuits[maximum_array];
            memset(added_circuits, '\0', sizeof(added_circuits));

            sprintf(added_circuits, "INSERT into circuits(circuitRef, name, location, country, lat, lng,\
            alt, url)VALUES(\'%s\', \'%s\', \'%s\', \'%s\', \'%.3f\', \'%.2f\', \'%d\', \'%s\');",
            circuitRef, name, location, country, lat, lng, alt, url);

            mysql_query(con, added_circuits);
            sleep(3);
        }

        
        else if(answer1a == 3)
        {
            int mod_table;
            printf("choose from the following.\n[1] Add column.\n[2] Drop column.\n[3] change datatype of a column.\n");
            scanf("%d", &mod_table);

            if (mod_table == 1)
            {
                char new_column[255];
                char column_datatype[255];
                printf("add name of new colomn:\n>>> ");
                scanf("%s", new_column);
                sleep(1);

                printf("add datatype of the new colomn:\n>>> ");
                scanf("%s", column_datatype);
                sleep(1);

                char column[maximum_array];
                memset(column, '\0', sizeof(column));
                sprintf(column, "ALTER TABLE %s ADD %s %s;", table_name, new_column, column_datatype);
                printf("query added successfully!!\n\n");
                mysql_query(con, column);
                sleep(2);

            }

            else if (mod_table == 2)
            {
                char delete_column[255];
                printf("Which column do you want to delete??\n>>> ");
                scanf("%s", delete_column);
                
                char del_column[maximum_array];
                memset(del_column, '\0', sizeof(del_column));

                sprintf(del_column, "ALTER TABLE %s DROP COLUMN %s;", table_name, delete_column);
                printf("query added successfully!!\n\n");
                mysql_query(con, del_column);
                sleep(2);
            }

            else if (mod_table == 3)
            {
                char column_name[255];
                char column_newdatatype[255];
                printf("which column do you want to change it datatype?\n>>> ");
                scanf("%s", column_name);
                printf("what datatype do you want it to be?\n>>> ");
                scanf("%s", column_newdatatype);

                char new_datatype[maximum_array];
                memset(new_datatype, '\0', sizeof(new_datatype));

                sprintf(new_datatype, "ALTER TABLE %s MODIFY COLUMN %s %s;", table_name, column_name, column_newdatatype);
                sleep(2);
                printf("query added successfully!!\n\n");
                mysql_query(con, new_datatype);
                sleep(2);
                
            }
            
        }

        else if(answer1a == 4)
        {
            char row[255];
            char rowb[255];
            printf("Which row do you want to delete?\n>>> ");
            scanf("%s", row);
            sleep(1);
            printf("Which name do you want to delete?\n>>> ");
            scanf("%s", rowb);
            sleep(1);



            char row2[maximum_array];
            memset(row2, '\0', sizeof(row2));
            sprintf(row2, "DELETE FROM %s WHERE %s='%s';", table_name, row, rowb);
            printf("query added successfully!!\n\n");
            mysql_query(con, row2);
            sleep(2);
        }

        else if (answer1a == 5)
        {
            printf("Quiting!...\n");
            sleep(2);
            printf("Done!...BYE!...\n\n");
            mysql_close(con);
            close_error(0);
        }
        else{
            mysql_close(con);
            close_error(0);
        }
    }
close_error(0);
exit(0);
}