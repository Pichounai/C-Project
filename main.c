//
// Created by MAC ARTHUR on 29/03/2024.
//d

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "column.h"
#include "cdataframe.h"


int main() {
    // COLUMN tests:
    // create_column test:
    /**COLUMN *mycol = create_column(STRING, "My column");
    printf("%s\n", mycol->title);*/

    // insert_value test:
    /**char a[] = "abra", c[] = "kadabra";
    insert_value(mycol, &a);
    insert_value(mycol, NULL);
    insert_value(mycol, &c);
    a[1] = 'a';
    print_col(mycol);*/

    // delete_column test:
    // see below

    // convert_value test:
    /**char str[50];
    int a = 52, b = 44, c = 15, d = 18;
    insert_value(mycol, &a);
    insert_value(mycol, &b);
    insert_value(mycol, &c);
    insert_value(mycol, &d);
    convert_value(mycol, 2, str, 50);
    printf("%s \n", str);*/

    // print_col test:
    /**char a = 'A', c = 'C';
    insert_value(mycol, &a);
    insert_value(mycol, NULL);
    insert_value(mycol, &c);
    print_col(mycol);*/

    // nb_occurrences_value test:
    /**char a[] = "jj jj";
    char b[] = "FF FF";
    char c[] = "jj jj";
    insert_value(mycol, a);
    insert_value(mycol, b);
    insert_value(mycol, NULL);
    insert_value(mycol, c);
    char *x = NULL;
    printf("%d\n", nb_occurrences_value(mycol, NULLVAL, x));*/

    // value_at_position test:
    /**char str[256];
    int a = 52, b = 44, c = 15, d = 18;
    insert_value(mycol, &a);
    insert_value(mycol, &b);
    insert_value(mycol, &c);
    insert_value(mycol, &d);
    printf("%s\n", value_at_position(mycol, 2, str));*/

    // nb_values_greater test:
    /**float a = 1.25;
    float b = 0.01;
    float c = 1.5;
    insert_value(mycol, &a);
    insert_value(mycol, &b);
    insert_value(mycol, NULL);
    insert_value(mycol, &c);
    float x = 0.5;
    printf("%d\n", nb_values_greater(mycol, FLOAT, &x));*/

    // nb_values_lower test:
    /**double a = 1.25;
    double b = 0.01;
    double c = 1.5;
    insert_value(mycol, &a);
    insert_value(mycol, &b);
    insert_value(mycol, NULL);
    insert_value(mycol, &c);
    double x = 1.25;
    printf("%d\n", nb_values_lower(mycol, DOUBLE, &x));*/

    // nb_values_equal test:
    /**unsigned int a = 1;
    unsigned int b = 2;
    unsigned int c = 2;
    insert_value(mycol, &a);
    insert_value(mycol, &b);
    insert_value(mycol, NULL);
    insert_value(mycol, &c);
    unsigned int x = 2;
    printf("%d\n", nb_values_equal(mycol, UINT, &x));*/

    // delete_column test:
    /**delete_column(mycol);
    printf("tuturu !");*/


    // CDATAFRAME tests:
    // 1. Filling tests:
    // create_cdataframe test:
    /**CDATAFRAME *mydataframe = create_cdataframe();*/

    // filling_cdataframe test:
    /**filling_cdataframe(mydataframe);
    display_cdataframe(mydataframe);*/

    // hard_filling_cdataframe test:
    /**if (hard_filling_cdataframe(mydataframe) == 1) {
        printf("CDataframe filled successfully\n");
        printf("%d\n", mydataframe->size);
        display_cdataframe(mydataframe);
    }
    else {
        printf("CDataframe is not empty\n");
    }*/

    // 2. Display tests:
    // display_cdataframe test:
    /**add_column_cdataframe(mydataframe, INT, "1st column");
    add_column_cdataframe(mydataframe, STRING, "2nd column");
    add_row_cdataframe(mydataframe);
    add_row_cdataframe(mydataframe);
    add_row_cdataframe(mydataframe);
    int test_display_row = 3;
    replace_value_cdataframe(mydataframe, 1, 2, INT, &test_display_row);
    char test_display_column[] = "hello";
    replace_value_cdataframe(mydataframe, 2, 1, STRING, &test_display_column);
    display_cdataframe(mydataframe);*/

    // display_rows_cdataframe test:
    /**add_column_cdataframe(mydataframe, INT, "1st column");
    add_column_cdataframe(mydataframe, STRING, "2nd column");
    add_row_cdataframe(mydataframe);
    add_row_cdataframe(mydataframe);
    add_row_cdataframe(mydataframe);
    int test_display_row = 3;
    replace_value_cdataframe(mydataframe, 1, 2, INT, &test_display_row);
    display_rows_cdataframe(mydataframe);*/

    // display_columns_cdataframe test:
    /**add_column_cdataframe(mydataframe, INT, "1st column");
    add_column_cdataframe(mydataframe, STRING, "2nd column");
    add_row_cdataframe(mydataframe);
    add_row_cdataframe(mydataframe);
    add_row_cdataframe(mydataframe);
    char test_display_column[] = "This is not a str";
    replace_value_cdataframe(mydataframe, 2, 1, STRING, &test_display_column);
    display_columns_cdataframe(mydataframe);*/

    // 3. Usual operations tests:
    // add_row_cdataframe test:
    /**add_column_cdataframe(mydataframe, INT, "1st column");
    add_column_cdataframe(mydataframe, STRING, "2nd column");
    if (add_row_cdataframe(mydataframe) == 1) {
        add_row_cdataframe(mydataframe);
        printf("Row added successfully\n");
        display_cdataframe(mydataframe);
    }
    else {
        printf("CDataframe is empty\n");
    }*/

    // delete_row_cdataframe test:
    /**add_column_cdataframe(mydataframe, INT, "1st column");
    add_column_cdataframe(mydataframe, STRING, "2nd column");
    add_column_cdataframe(mydataframe, CHAR, "3rd column");
    add_column_cdataframe(mydataframe, DOUBLE, "4th column");
    add_row_cdataframe(mydataframe);
    add_row_cdataframe(mydataframe);
    if (delete_row_cdataframe(mydataframe, 3) == 1) {
        printf("Row deleted successfully\n");
        display_cdataframe(mydataframe);
    }
    else {
        printf("Row not found\n");
    }*/

    // add_column_cdataframe test:
    /**printf("%d\n", add_column_cdataframe(mydataframe, INT, "1st column"));
    add_column_cdataframe(mydataframe, STRING, "2nd column");
    add_column_cdataframe(mydataframe, CHAR, "3rd column");
    printf("%d, %s, %d\n", mydataframe->size, mydataframe->columns[2]->title, mydataframe->columns[2]->column_type);*/

    // delete_column_cdataframe test:
    /**add_column_cdataframe(mydataframe, INT, "1st column");
    add_column_cdataframe(mydataframe, STRING, "2nd column");
    add_column_cdataframe(mydataframe, FLOAT, "3rd column");
    add_column_cdataframe(mydataframe, UINT, "4th column");
    if (delete_column_cdataframe(mydataframe, "2nd column") == 1) {
        printf("Column deleted successfully\n");
        printf("%d\n", mydataframe->size);
        printf("%s, %d\n", mydataframe->columns[0]->title, mydataframe->columns[0]->column_type);
        printf("%s, %d\n", mydataframe->columns[1]->title, mydataframe->columns[1]->column_type);
        printf("%s, %d\n", mydataframe->columns[2]->title, mydataframe->columns[2]->column_type);
    }
    else {
        printf("Column not found\n");
    }*/

    // rename_column_cdataframe test:
    /**add_column_cdataframe(mydataframe, INT, "1st column");
    add_column_cdataframe(mydataframe, STRING, "3rd column");
    printf("%s, %d\n", mydataframe->columns[1]->title, mydataframe->columns[1]->column_type);
    if (rename_column_cdataframe(mydataframe, "3rd column", "2nd column") == 1) {
        printf("Column renamed successfully\n");
        printf("%s, %d\n", mydataframe->columns[0]->title, mydataframe->columns[0]->column_type);
        printf("%s, %d\n", mydataframe->columns[1]->title, mydataframe->columns[1]->column_type);
    }
    else {
        printf("Column not found\n");
    }*/

    // search_value_cdataframe test:
    /**add_column_cdataframe(mydataframe, INT, "1st column");
    add_column_cdataframe(mydataframe, STRING, "2nd column");
    add_row_cdataframe(mydataframe);
    add_row_cdataframe(mydataframe);
    int test_search = 7;
    replace_value_cdataframe(mydataframe, 1, 2, INT, &test_search);
    display_cdataframe(mydataframe);
    int test_search2 = 7;
    if (search_value_cdataframe(mydataframe, INT, &test_search2) == 1) {
        printf("Value found\n");
    }
    else {
        printf("Value not found\n");
    }*/

    // replace_value_cdataframe test:
    /**add_column_cdataframe(mydataframe, INT, "1st column");
    add_column_cdataframe(mydataframe, STRING, "2nd column");
    add_row_cdataframe(mydataframe);
    add_row_cdataframe(mydataframe);
    display_cdataframe(mydataframe);
    int new_value = 3;
    int check_replace_value_cdataframe = replace_value_cdataframe(mydataframe, 1, 2, INT, &new_value);
    new_value = 4;
    if (check_replace_value_cdataframe == 1) {
        printf("Value replaced\n");
        display_cdataframe(mydataframe);
        replace_value_cdataframe(mydataframe, 1, 2, NULLVAL, NULL);
        display_cdataframe(mydataframe);
    }
    else {
        if (check_replace_value_cdataframe == -1) {
            printf("Value type does not correspond column type\n");
            display_cdataframe(mydataframe);
        }
        else {
            printf("Value does not exist\n");
        }
    }*/

    // column_names_cdataframe test:
    /**add_column_cdataframe(mydataframe, INT, "1st column");
    add_column_cdataframe(mydataframe, STRING, "2nd column");
    add_column_cdataframe(mydataframe, FLOAT, "3rd column");
    add_column_cdataframe(mydataframe, UINT, "4th column");
    column_names_cdataframe(mydataframe);*/

    // 4. Analysis and statistics tests:
    // nb_rows_cdataframe test:
    /**nb_rows_cdataframe(mydataframe);*/

    // nb_columns_cdataframe test:
    /**nb_columns_cdataframe(mydataframe);*/

    // nb_equal_cells_cdataframe test:
    /**add_column_cdataframe(mydataframe, INT, "1st column");
    add_column_cdataframe(mydataframe, STRING, "2nd column");
    add_column_cdataframe(mydataframe, INT, "3rd column");
    add_row_cdataframe(mydataframe);
    add_row_cdataframe(mydataframe);
    add_row_cdataframe(mydataframe);
    int test_equal = 52, test_equal2 = 19;
    replace_value_cdataframe(mydataframe, 1, 1, INT, &test_equal);
    replace_value_cdataframe(mydataframe, 1, 3, INT, &test_equal2);
    replace_value_cdataframe(mydataframe, 3, 1, INT, &test_equal);
    replace_value_cdataframe(mydataframe, 3, 2, INT, &test_equal);
    display_cdataframe(mydataframe);
    nb_equal_cells_cdataframe(mydataframe, INT, &test_equal);*/

    // nb_greater_cells_cdataframe test:
    /**add_column_cdataframe(mydataframe, STRING, "1st column");
    add_column_cdataframe(mydataframe, STRING, "2nd column");
    add_column_cdataframe(mydataframe, INT, "3rd column");
    add_row_cdataframe(mydataframe);
    add_row_cdataframe(mydataframe);
    int test_greater = 68;
    replace_value_cdataframe(mydataframe, 1, 1, STRING, "D");
    replace_value_cdataframe(mydataframe, 2, 2, STRING, "B");
    replace_value_cdataframe(mydataframe, 2, 2, STRING, "CD");
    replace_value_cdataframe(mydataframe, 3, 2, INT, &test_greater);
    display_cdataframe(mydataframe);
    nb_greater_cells_cdataframe(mydataframe, STRING, "C");*/

    // nb_lower_cells_cdataframe test:
    /**add_column_cdataframe(mydataframe, CHAR, "1st column");
    add_row_cdataframe(mydataframe);
    char test_lower = 'd';
    replace_value_cdataframe(mydataframe, 1, 1, CHAR, &test_lower);
    display_cdataframe(mydataframe);
    nb_lower_cells_cdataframe(mydataframe, CHAR, &test_lower);*/


    // free mydataframe:
    /**int column_nb;
    for (column_nb = 0; column_nb < mydataframe->size; column_nb = column_nb + 1) {
        delete_column(mydataframe->columns[column_nb]);
    }
    free(mydataframe->columns);
    free(mydataframe);
    printf("tuturu !");*/

    return 0;
}
