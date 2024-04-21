//
// Created by MAC ARTHUR on 29/03/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "column.h"
#include "cdataframe.h"


int main() {
    // COLUMN tests:
    // create_column test:
    /**COLUMN *mycol = create_column("My column");
    printf("%s\n", mycol->title);*/

    // insert_value test:
    /**int val = 5;
    if (insert_value(mycol, val))
        printf("Value added successfully to my column\n");
    else
        printf("Error adding value to my column\n");*/

    // delete_column test:
    // see below

    // print_col test:
    /**insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 15);
    print_col(mycol);*/

    // nb_occurrences_value test:
    /**insert_value(mycol, 52);
    printf("%d\n", nb_occurrences_value(mycol, 52));*/

    // value_at_position test:
    /**printf("%d\n", value_at_position(mycol, 2));*/

    // nb_values_greater test:
    /**printf("%d\n", nb_values_greater(mycol, 44));*/

    // nb_values_lower test:
    /**printf("%d\n", nb_values_lower(mycol, 44));*/

    // nb_values_equal test:
    /**printf("%d\n", nb_values_equal(mycol, 44));*/

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
        printf("%d\n", mydataframe->lsize);
    }
    else {
        printf("CDataframe is not empty\n");
        printf("%d\n", mydataframe->lsize);
    }*/

    // 2. Display tests:
    // display_cdataframe test:
    /**display_cdataframe(mydataframe);*/

    // display_rows_cdataframe test:
    /**add_column_cdataframe(mydataframe, "1st column");
    add_column_cdataframe(mydataframe, "2nd column");
    add_row_cdataframe(mydataframe);
    add_row_cdataframe(mydataframe);
    add_row_cdataframe(mydataframe);
    replace_value_cdataframe(mydataframe, 1, 2, 3);
    display_rows_cdataframe(mydataframe);*/

    // display_columns_cdataframe test:
    /**add_column_cdataframe(mydataframe, "1st column");
    add_column_cdataframe(mydataframe, "2nd column");
    add_row_cdataframe(mydataframe);
    add_row_cdataframe(mydataframe);
    add_row_cdataframe(mydataframe);
    replace_value_cdataframe(mydataframe, 1, 2, 3);
    display_columns_cdataframe(mydataframe);*/

    // 3. Usual operations tests:
    // add_row_cdataframe test:
    /**if (add_row_cdataframe(mydataframe) == 1) {
        printf("Row added successfully\n");
        display_cdataframe(mydataframe);
    }
    else {
        printf("CDataframe is empty\n");
    }*/

    // delete_row_cdataframe test:
    /**if (delete_row_cdataframe(mydataframe, 3) == 1) {
        printf("Row deleted successfully\n");
        display_cdataframe(mydataframe);
    }
    else {
        printf("Row not found\n");
    }*/

    // add_column_cdataframe test:
    /**printf("%d\n", add_column_cdataframe(mydataframe, "1st column"));
    printf("%d\n", add_column_cdataframe(mydataframe, "2nd column"));
    printf("%s, %d, %d\n", mydataframe->columns[1]->title, mydataframe->lsize, mydataframe->columns[1]->lsize);*/

    // delete_column_cdataframe test:
    /**if (delete_column_cdataframe(mydataframe, "1st column") == 1) {
        printf("Column deleted successfully\n");
        printf("%d\n", mydataframe->lsize);
    }
    else {
        printf("Column not found\n");
    }*/

    // rename_column_cdataframe test:
    /**printf("%s\n", mydataframe->columns[0]->title);
    if (rename_column_cdataframe(mydataframe, "2nd column", "1st column") == 1) {
        printf("Column renamed successfully\n");
        printf("%s\n", mydataframe->columns[0]->title);
    }
    else {
        printf("Column not found\n");
    }*/

    // search_value_cdataframe test:
    /**add_row_cdataframe(mydataframe);
    add_row_cdataframe(mydataframe);
    add_row_cdataframe(mydataframe);
    replace_value_cdataframe(mydataframe, 1, 1, 52);
    if (search_value_cdataframe(mydataframe, 52) == 1) {
        printf("Value found\n");
    }
    else {
        printf("Value not found\n");
    }*/

    // replace_value_cdataframe test:
    /**if (replace_value_cdataframe(mydataframe, 1, 1, 5)) {
        printf("Value replaced\n");
        printf("%d\n", mydataframe->columns[0]->data[0]);
    }
    else {
        printf("Value not found\n");
    }*/

    // column_names_cdataframe test:
    /**add_column_cdataframe(mydataframe, "2nd column");
    add_column_cdataframe(mydataframe, "3rd column");
    column_names_cdataframe(mydataframe);*/

    // 4. Analysis and statistics tests:
    // nb_rows_cdataframe test:
    /**nb_rows_cdataframe(mydataframe);*/

    // nb_columns_cdataframe test:
    /**nb_columns_cdataframe(mydataframe);*/

    // nb_equal_cells_cdataframe test:
    /**replace_value_cdataframe(mydataframe, 1, 2, 52);
    replace_value_cdataframe(mydataframe, 1, 3, 52);
    add_column_cdataframe(mydataframe, "4th column");
    replace_value_cdataframe(mydataframe, 4, 3, 52);
    nb_equal_cells_cdataframe(mydataframe, 52);*/

    // nb_greater_cells_cdataframe test:
    /**replace_value_cdataframe(mydataframe, 2, 1, 58);
    nb_greater_cells_cdataframe(mydataframe, 52);*/

    // nb_lower_cells_cdataframe test:
    /**nb_lower_cells_cdataframe(mydataframe, 52);*/


    // free mydataframe:
    /**int column_nb;
    for (column_nb = 0; column_nb < mydataframe->lsize; column_nb = column_nb + 1) {
        delete_column(mydataframe->columns[column_nb]);
    }
    free(mydataframe->columns);
    free(mydataframe);
    printf("tuturu !");*/

    return 0;
}
