/* this program is made by Mohammad Khalaf
to view tables  and the data inside in SQL. it made in C-lang. programmer = Mohammad khalaf / 703190  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mariadb/mysql.h>
#include <unistd.h>
#include "interface.h" // this the header that conatains the error function.


#define DEBUG
#define maximum_array 3000


int main()
{
    const char table_name[10] = "circuits"; // Name of the table 
    // char circuitRef[255];  // name of the columns in the table
    // char name[255];
    // char location[255];
    // char country[255];
    // float lat;
    // float lng;
    // int alt;
    // char url[255];
    
    
    MYSQL *con = mysql_init(NULL); // make connection with mariadb 
    MYSQL_ROW row;
    MYSQL_FIELD *field;
    
    // MYSQL_ROW record;

    if (con == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "pipo", "theclown", "f1", 0, NULL, 0) == NULL) // here you include user name and password
    {
        close_error(con);  // return error if it doesnt work
    }
    
    int m = 5;
    while ((m = 5)) // begin the questions in loop
    {                     // 1st question and the main interface
        int answer1a;
        printf("\nHello!!\nThis is the interface that operate the table %s.\n\n", table_name);
        usleep(100);
        printf("choose 1,2,3,4 or 5 of what do you want to do?\n");
        sleep(1);
        printf("[1] View table.\n[2] Add to table.\n[3] Modify table.\n[4] Delete data.\n[5] quit.\n>>> ");
        scanf("%d", &answer1a);
        printf("\n");

        if (answer1a == 1) // here you can view the table and the column headers of the table.
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


            while ((row = mysql_fetch_row(result))) // here it prints out every row in the table 
            {
                for(int i = 0; i < num_fields; i++)
                {
                    if (i == 0)
                    {
                        while ((field = mysql_fetch_field(result))) // here it prints out the headers 
                        {
                            printf("%s ", field->name);
                        }

                        printf("\n");
                    }
                    printf("%s ", row[i] ? row[i] : "NULL"); // here it prints the all the rows.
                }

                printf("\n");
            }

            mysql_free_result(result);
            sleep(3);
            // close_error(con);
        }
        else if(answer1a == 2) // add new content or values to table 
        {
            printf("what do you want to insert?\nAnswer the following quistions with what you want to insert into the table.\n");
            sleep(2);
            
            // ask for every column the content that you want to insert into the table.

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

            // insert the content that you aswered into the table.

            char added_circuits[maximum_array];
            memset(added_circuits, '\0', sizeof(added_circuits));

            sprintf(added_circuits, "INSERT into circuits(circuitRef, name, location, country, lat, lng,\
            alt, url)VALUES(\'%s\', \'%s\', \'%s\', \'%s\', \'%.3f\', \'%.2f\', \'%d\', \'%s\');",
            circuitRef, name, location, country, lat, lng, alt, url);

            mysql_query(con, added_circuits);// here it sends the chages to the database.
            sleep(3);
        }

        
        else if(answer1a == 3)  // this interface is within the main interface, and it asks you if you want to add new column or delete a column or change a datatype of a column.
        {
            int mod_table;
            printf("choose from the following.\n[1] Add column.\n[2] Drop column.\n[3] change datatype of a column.\n");
            scanf("%d", &mod_table);

            if (mod_table == 1) // here it asks if you want to add a column. it asks you to enter a name and a datatype for the new column.
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
                mysql_query(con, column);// here it sends the chages to the database.
                sleep(2);

            }

            else if (mod_table == 2) // here it asks if the you want to delete aka drop a column.
            {
                char delete_column[255];
                printf("Which column do you want to delete??\n>>> ");
                scanf("%s", delete_column);
                
                char del_column[maximum_array];
                memset(del_column, '\0', sizeof(del_column));

                sprintf(del_column, "ALTER TABLE %s DROP COLUMN %s;", table_name, delete_column);
                printf("query added successfully!!\n\n");
                mysql_query(con, del_column); // here it sends the chages to the database.
                sleep(2);
            }

            else if (mod_table == 3) // this one asks if you wanna change a column's datatype
            {
                char column_name[255];
                char column_newdatatype[255];
                printf("which column do you want to change it datatype?\n>>> ");// which column will you change 
                scanf("%s", column_name);
                printf("what datatype do you want it to be?\n>>> ");// what datatype do you want it to be.
                scanf("%s", column_newdatatype);

                char new_datatype[maximum_array];
                memset(new_datatype, '\0', sizeof(new_datatype));

                sprintf(new_datatype, "ALTER TABLE %s MODIFY COLUMN %s %s;", table_name, column_name, column_newdatatype);
                sleep(2);
                printf("query added successfully!!\n\n");
                mysql_query(con, new_datatype);// here it sends the chages to the database.
                sleep(2);
                
            }
            
        }

        else if(answer1a == 4)// here it delets a row of content
        {
            char row[255];
            char rowb[255];
            printf("Which row do you want to delete?\n>>> "); // which column is it that you want to delete
            scanf("%s", row);
            sleep(1);
            printf("Which name do you want to delete?\n>>> "); // what name is in that column that you want to delete
            scanf("%s", rowb);
            sleep(1);

            char row2[maximum_array];
            memset(row2, '\0', sizeof(row2));
            sprintf(row2, "DELETE FROM %s WHERE %s='%s';", table_name, row, rowb);
            printf("query added successfully!!\n\n");
            mysql_query(con, row2); // here it sends the chages to the database.
            sleep(2);
        }

        else if (answer1a == 5) // this option quits the program and the database.
        {
            printf("Quiting!...\n");
            sleep(2);
            printf("Done!...BYE!...\n\n");
            mysql_close(con);
            close_error(0);
        }
        else{
            mysql_close(con); // if you havent entered any thing it just stops.
            close_error(0);
        }
    }
close_error(0);
exit(0);
}