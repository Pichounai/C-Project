// Project CDataframe Arthur DELANNOY Abderrahmane SASSY L1-INT4
// Arthur DELANNOY - Abderrahmane SASSY
// This file contains every cdataframe's functions

#define REALOC_SIZE 256

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "column.h"
#include "cdataframe.h"


// 1. Filling
/**
* @brief: Create a cdataframe
* @return: Pointer to created cdataframe
*/
CDATAFRAME *create_cdataframe() {
    CDATAFRAME *cdataframe = (CDATAFRAME*) malloc(sizeof(CDATAFRAME));
    cdataframe->columns = NULL;
    cdataframe->max_size = 0;
    cdataframe->size = 0;
    return cdataframe;
}

/**
* @brief: Filling in the CDataframe with user input
* @param1: Pointer to the cdataframe
*/
void filling_cdataframe(CDATAFRAME *cdataframe) {
    if (cdataframe->size != 0) {
        printf("The CDataframe is already filled\n");
    }
    else {
        int nb_columns_to_add = 0;
        printf("Enter the number of the columns you want to add:");
        scanf("%d", &nb_columns_to_add);
        printf("\n");
        int nb_rows_to_add = 0;
        printf("Enter the number of the rows you want to add:");
        scanf("%d", &nb_rows_to_add);
        printf("\n");
        int column_nb, row_nb;
        for (column_nb = 0; column_nb < nb_columns_to_add; column_nb = column_nb + 1) {
            char *column_name = (char*) malloc(REALOC_SIZE * sizeof(char));
            if (column_nb == 0) {
                printf("Enter the name of the 1st column:");
            }
            else {
                if (column_nb == 1) {
                    printf("Enter the name of the 2nd column:");
                }
                else {
                    if (column_nb == 2) {
                        printf("Enter the name of the 3rd column:");
                    }
                    else {
                        printf("Enter the name of the %dth column:", column_nb + 1);
                    }
                }
            }
            scanf("%[^\n]%*c", gets(column_name));
            printf("\n");
            ENUM_TYPE type_of_column;
            printf("Enter the type of %s (1.unsigned int, 2.int, 3.char, 4.float, 5.double, 6.string):", column_name);
            scanf("%d", &type_of_column);
            printf("\n");
            add_column_cdataframe(cdataframe, type_of_column + 1, column_name);
            printf("%s:\n", cdataframe->columns[column_nb]->title);
            for (row_nb = 0; row_nb < nb_rows_to_add; row_nb = row_nb + 1) {
                if (column_nb == 0) {
                    add_row_cdataframe(cdataframe);
                }
                int enter_value;
                if (row_nb == 0) {
                    printf("Do you want to enter a value in the 1st row (0.no, 1.yes):");
                }
                else {
                    if (row_nb == 1) {
                        printf("Do you want to enter a value in the 2nd row (0.no, 1.yes):");
                    }
                    else {
                        if (row_nb == 2) {
                            printf("Do you want to enter a value in the 3rd row (0.no, 1.yes):");
                        }
                        else {
                            printf("Do you want to enter a value in the %dth row (0.no, 1.yes):", column_nb + 1);
                        }
                    }
                }
                scanf("%d", &enter_value);
                printf("\n");
                if (enter_value == 1) {
                    printf("Enter the value:");
                    switch(type_of_column) {
                        case 1: {
                            unsigned int value_to_add;
                            scanf("%u", &value_to_add);
                            replace_value_cdataframe(cdataframe, column_nb + 1, row_nb + 1, UINT, &value_to_add);
                            break;
                        }
                        case 2: {
                            int value_to_add;
                            scanf("%d", &value_to_add);
                            replace_value_cdataframe(cdataframe, column_nb + 1, row_nb + 1, INT, &value_to_add);
                            break;
                        }
                        case 3: {
                            char value_to_add;
                            scanf(" %c", &value_to_add);
                            replace_value_cdataframe(cdataframe, column_nb + 1, row_nb + 1, CHAR, &value_to_add);
                            break;
                        }
                        case 4: {
                            float value_to_add;
                            scanf("%f", &value_to_add);
                            replace_value_cdataframe(cdataframe, column_nb + 1, row_nb + 1, FLOAT, &value_to_add);
                            break;
                        }
                        case 5: {
                            double value_to_add;
                            scanf("%lf", &value_to_add);
                            replace_value_cdataframe(cdataframe, column_nb + 1, row_nb + 1, DOUBLE, &value_to_add);
                            break;
                        }
                        case 6: {
                            char *string_to_add = (char*) malloc(REALOC_SIZE * sizeof(char));
                            scanf("%[^\n]%*c", gets(string_to_add));
                            replace_value_cdataframe(cdataframe, column_nb + 1, row_nb + 1, STRING, string_to_add);
                            break;
                        }
                    }
                    printf("\n");
                }
            }
        }
        printf("CDataframe is filled\n");
    }
}

/**
* @brief: Hard filling of the cdataframe, by default every column will be of type int and full of NULL
* @param1: Pointer to the cdataframe
* @return: 1 if the cdataframe as been filled 0 if the cdataframe already contained things
*/
int hard_filling_cdataframe(CDATAFRAME *cdataframe) {
    if (cdataframe->max_size != 0) {
        return 0;
    }
    int column_nb, row_nb;
    for (column_nb = 0; column_nb < REALOC_SIZE; column_nb = column_nb + 1) {
        if (column_nb == 0) {
            add_column_cdataframe(cdataframe, INT, "1st column");
            for (row_nb = 0; row_nb < REALOC_SIZE; row_nb = row_nb + 1) {
                add_row_cdataframe(cdataframe);
            }
        }
        else {
            if (column_nb == 1) {
                add_column_cdataframe(cdataframe, INT, "2nd column");
            }
            else {
                if (column_nb == 2) {
                    add_column_cdataframe(cdataframe, INT, "3rd column");
                }
                else {
                    char column_name[12];
                    sprintf(column_name, "%dth column", column_nb + 1);
                    add_column_cdataframe(cdataframe, INT, column_name);
                }
            }
        }
    }
    return 1;
}

// 2. Display
/**
* @brief: Display the entire cdataframe
* @param1: Pointer to the cdataframe
*/
void display_cdataframe(CDATAFRAME *cdataframe) {
    if (cdataframe->size == 0) {
        printf("CDataframe is empty\n");
    }
    else {
        printf("CDataframe:");
        int column_nb;
        for (column_nb = 0; column_nb < cdataframe->size; column_nb = column_nb + 1) {
            printf("\n");
            printf("%d. %s:\n", column_nb + 1, cdataframe->columns[column_nb]->title);
            print_col(cdataframe->columns[column_nb]);
        }
    }
}

/**
* @brief: Dispalay a part of the CDataframe rows according to a user-provided limit
* @param1: Pointer to the cdataframe
*/
void display_rows_cdataframe(CDATAFRAME *cdataframe) {
    if (cdataframe->size == 0) {
        printf("CDataframe is empty\n");
    }
    else {
        int first_row_display, last_row_display;
        printf("From witch row do you want to begin displaying:");
        scanf("%d", &first_row_display);
        printf("\n");
        printf("At witch row do you want to stop displaying:");
        scanf("%d", &last_row_display);
        printf("\n");
        if (first_row_display > last_row_display || last_row_display > cdataframe->columns[0]->size) {
            printf("Not possible\n");
        }
        else {
            int row_nb, column_nb;
            for (row_nb = first_row_display - 1; row_nb < last_row_display; row_nb = row_nb + 1) {
                printf("%d. ", row_nb + 1);
                for (column_nb = 0; column_nb < cdataframe->size; column_nb = column_nb + 1) {
                    if (cdataframe->columns[column_nb]->data[row_nb] == NULL) {
                        printf("NULL");
                    }
                    else {
                        if (cdataframe->columns[column_nb]->column_type == STRING) {
                            printf("%s", (char*)cdataframe->columns[column_nb]->data[row_nb]);
                        }
                        else {
                            char str_value[256];
                            convert_value(cdataframe->columns[column_nb], row_nb, str_value, 256);
                            printf("%s", str_value);
                        }
                    }
                    if (column_nb != cdataframe->size - 1) {
                        printf("; ");
                    }
                    else {
                        printf("\n");
                    }
                }
            }
        }
    }
}

/**
* @brief: Display a part of the columns of the CDataframe according to a limit supplied by the user
* @param1: Pointer to the cdataframe
*/
void display_columns_cdataframe(CDATAFRAME *cdataframe) {
    if (cdataframe->size == 0) {
        printf("CDataframe is empty\n");
    }
    else {
        int first_column_display, last_column_display;
        printf("From witch column do you want to begin displaying:");
        scanf("%d", &first_column_display);
        printf("\n");
        printf("At witch column do you want to stop displaying:");
        scanf("%d", &last_column_display);
        printf("\n");
        if (first_column_display > last_column_display || last_column_display > cdataframe->size) {
            printf("Not possible\n");
        }
        else {
            int column_nb, row_nb;
            for (column_nb = first_column_display - 1; column_nb < last_column_display; column_nb = column_nb + 1) {
                char *column_type;
                switch(cdataframe->columns[column_nb]->column_type) {
                    case UINT: {
                        column_type = "unsigned int";
                        break;
                    }
                    case INT: {
                        column_type = "int";
                        break;
                    }
                    case CHAR: {
                        column_type = "char";
                        break;
                    }
                    case FLOAT: {
                        column_type = "float";
                        break;
                    }
                    case DOUBLE: {
                        column_type = "double";
                        break;
                    }
                    case STRING: {
                        column_type = "string";
                        break;
                    }
                }
                printf("%d. (%s) %s: ", column_nb + 1, column_type, cdataframe->columns[column_nb]->title);
                for (row_nb = 0; row_nb < cdataframe->columns[column_nb]->size; row_nb = row_nb + 1) {
                    if (cdataframe->columns[column_nb]->data[row_nb] == NULL) {
                        printf("NULL");
                    }
                    else {
                        if (cdataframe->columns[column_nb]->column_type == STRING) {
                            printf("%s", (char*)cdataframe->columns[column_nb]->data[row_nb]);
                        }
                        else {
                            char str_value[256];
                            convert_value(cdataframe->columns[column_nb], row_nb, str_value, 256);
                            printf("%s", str_value);
                        }
                    }
                    if (row_nb != cdataframe->columns[0]->size - 1) {
                        printf("; ");
                    }
                    else {
                        printf("\n");
                    }
                }
            }
        }
    }
}

// 3. Usual operations
/**
* @brief: Add a row of values to the cdataframe
* @param1: Pointer to the cdataframe
* @return: 1 if the row as been added 0 otherwise
*/
int add_row_cdataframe(CDATAFRAME *cdataframe) {
    if (cdataframe->size == 0) {
        return 0;
    }
    int column_nb;
    for (column_nb = 0; column_nb < cdataframe->size; column_nb = column_nb + 1) {
        insert_value(cdataframe->columns[column_nb], NULL);
    }
    return 1;
}

/**
* @brief: Delete a row of values from the CDataframe
* @param1: Pointer to the cdataframe
* @param2: Row number to delete
* @return: 1 if the row as been deleted 0 otherwise
*/
int delete_row_cdataframe(CDATAFRAME *cdataframe, int target_row_nb) {
    if (cdataframe->size != 0 && cdataframe->columns[0]->size >= target_row_nb) {
        int column_nb, row_nb;
        for (column_nb = 0; column_nb < cdataframe->size; column_nb = column_nb + 1) {
            for (row_nb = target_row_nb - 1; row_nb < cdataframe->columns[column_nb]->size - 1; row_nb = row_nb + 1) {
                cdataframe->columns[column_nb]->data[row_nb] = cdataframe->columns[column_nb]->data[row_nb + 1];
            }
            cdataframe->columns[column_nb]->size = cdataframe->columns[column_nb]->size - 1;
        }
        return 1;
    }
    return 0;
}

/**
* @brief: Add a column to the cdataframe
* @param1: Pointer to the cdataframe
* @param2: Column type
* @param3: Column title
* @return: 1 if the column as been added 0 otherwise
*/
int add_column_cdataframe(CDATAFRAME *cdataframe, ENUM_TYPE column_type, char *column_title) {
    if (cdataframe->size == cdataframe->max_size) {
        COLUMN **test_alloc = NULL;
        if (cdataframe->columns == NULL) {
            test_alloc = (COLUMN**) malloc(REALOC_SIZE * sizeof(COLUMN*));
        }
        else {
            test_alloc = realloc(cdataframe->columns, (cdataframe->max_size + REALOC_SIZE) * sizeof(COLUMN*));
        }
        if (test_alloc == NULL) {
            return 0;
        }
        cdataframe->columns = test_alloc;
        cdataframe->max_size = cdataframe->max_size + REALOC_SIZE;
    }
    cdataframe->columns[cdataframe->size] = create_column(column_type, column_title);
    int row_nb;
    for (row_nb = 0; row_nb < cdataframe->columns[0]->size; row_nb = row_nb + 1) {
        insert_value(cdataframe->columns[cdataframe->size], NULL);
    }
    cdataframe->size = cdataframe->size + 1;
    return 1;
}

/**
* @brief: Delete a column from the cdataframe
* @param1: Pointer to the cdataframe
* @param2: Column title
* @return: 1 if the column as been deleted 0 otherwise
*/
int delete_column_cdataframe(CDATAFRAME *cdataframe, char *title) {
    if (cdataframe->columns != NULL) {
        int column_nb;
        for (column_nb = 0; column_nb < cdataframe->size; column_nb = column_nb + 1) {
            if (strcmp(cdataframe->columns[column_nb]->title, title) == 0) {
                delete_column(cdataframe->columns[column_nb]);
                for (column_nb = column_nb; column_nb < cdataframe->size - 1; column_nb = column_nb + 1) {
                    cdataframe->columns[column_nb] = cdataframe->columns[column_nb + 1];
                }
                cdataframe->size = cdataframe->size - 1;
                return 1;
            }
        }
    }
    return 0;
}

/**
* @brief: Rename the title of a column in the cdataframe
* @param1: Pointer to the cdataframe
* @param2: Column former title
* @param3: Column new title
* @return: 1 if the column as been renamed 0 otherwise
*/
int rename_column_cdataframe(CDATAFRAME *cdataframe, char *former_title, char *new_title) {
    if (cdataframe->columns != NULL) {
        int column_nb;
        for (column_nb = 0; column_nb < cdataframe->size; column_nb = column_nb + 1) {
            if (strcmp(cdataframe->columns[column_nb]->title, former_title) == 0) {
                cdataframe->columns[column_nb]->title = strdup(new_title);
                return 1;
            }
        }
    }
    return 0;
}

/**
* @brief: Search if a value exist in the cdataframe
* @param1: Pointer to the cdataframe
* @param2: Value type
* @param3: Value to search
* @return: 1 if the value as been found 0 otherwise
*/
int search_value_cdataframe(CDATAFRAME *cdataframe, ENUM_TYPE value_type, COL_TYPE *value) {
    if (cdataframe->size != 0) {
        int column_nb;
        for (column_nb = 0; column_nb < cdataframe->size; column_nb = column_nb + 1) {
            if (value_type == NULLVAL || cdataframe->columns[column_nb]->column_type == value_type) {
                if (nb_occurrences_value(cdataframe->columns[column_nb], value_type, value) != 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

/**
* @brief: Replace the value in the cdataframe cell using its row and column number
* @param1: Pointer to the cdataframe
* @param2: Column number
* @param3: Row number
* @param4: New value type
* @param5: New value
* @return: 1 if the value as been replaced -1 if the type of the column does not correspond 0 otherwise
*/
int replace_value_cdataframe(CDATAFRAME *cdataframe, int column_nb, int row_nb, ENUM_TYPE new_value_type, COL_TYPE *new_value) {
    if (cdataframe->size >= column_nb && cdataframe->columns[0]->size >= row_nb) {
        if (new_value_type == NULLVAL || cdataframe->columns[column_nb - 1]->column_type == new_value_type) {
            free(cdataframe->columns[column_nb - 1]->data[row_nb - 1]);
            switch(cdataframe->columns[column_nb - 1]->column_type) {
                case UINT: {
                    cdataframe->columns[column_nb - 1]->data[row_nb - 1] = (unsigned int*) malloc (sizeof(unsigned int));
                    if (new_value == NULL) {
                        cdataframe->columns[column_nb - 1]->data[row_nb - 1] = new_value;
                    }
                    else {
                        *(unsigned int*)cdataframe->columns[column_nb - 1]->data[row_nb - 1] = *(unsigned int*)new_value;
                    }
                    break;
                }
                case INT: {
                    cdataframe->columns[column_nb - 1]->data[row_nb - 1] = (int*) malloc (sizeof(int));
                    if (new_value == NULL) {
                        cdataframe->columns[column_nb - 1]->data[row_nb - 1] = new_value;
                    }
                    else {
                        *(int*)cdataframe->columns[column_nb - 1]->data[row_nb - 1] = *(int*)new_value;
                    }
                    break;
                }
                case CHAR: {
                    cdataframe->columns[column_nb - 1]->data[row_nb - 1] = (char*) malloc (sizeof(char));
                    if (new_value == NULL) {
                        cdataframe->columns[column_nb - 1]->data[row_nb - 1] = new_value;
                    }
                    else {
                        *(char*)cdataframe->columns[column_nb - 1]->data[row_nb - 1] = *(char*)new_value;
                    }
                    break;
                }
                case FLOAT: {
                    cdataframe->columns[column_nb - 1]->data[row_nb - 1] = (float*) malloc (sizeof(float));
                    if (new_value == NULL) {
                        cdataframe->columns[column_nb - 1]->data[row_nb - 1] = new_value;
                    }
                    else {
                        *(float*)cdataframe->columns[column_nb - 1]->data[row_nb - 1] = *(float*)new_value;
                    }
                    break;
                }
                case DOUBLE: {
                    cdataframe->columns[column_nb - 1]->data[row_nb - 1] = (double*) malloc (sizeof(double));
                    if (new_value == NULL) {
                        cdataframe->columns[column_nb - 1]->data[row_nb - 1] = new_value;
                    }
                    else {
                        *(double*)cdataframe->columns[column_nb - 1]->data[row_nb - 1] = *(double*)new_value;
                    }
                    break;
                }
                case STRING: {
                    cdataframe->columns[column_nb - 1]->data[row_nb - 1] = (char**) malloc (sizeof(char*));
                    if (new_value == NULL) {
                        cdataframe->columns[column_nb - 1]->data[row_nb - 1] = new_value;
                    }
                    else {
                        *(char**)cdataframe->columns[column_nb - 1]->data[row_nb - 1] = *(char**)new_value;
                    }
                    break;
                }
            }
            return 1;
        }
        return -1;
    }
    return 0;
}

/**
* @brief: Display column names
* @param1: Pointer to the cdataframe
*/
void column_names_cdataframe(CDATAFRAME *cdataframe) {
    if (cdataframe->size == 0) {
        printf("CDataframe is empty\n");
    }
    else {
        printf("CDataframe column names: ");
        int column_nb;
        for (column_nb = 0; column_nb < cdataframe->size; column_nb = column_nb + 1) {
            if (column_nb != 0) {
                printf(", ");
            }
            printf("%d. %s", column_nb + 1, cdataframe->columns[column_nb]->title);
        }
        printf("\n");
    }
}

// 4. Analysis and statistics
/**
* @brief: Display the number of rows
* @param1: Pointer to the cdataframe
*/
void nb_rows_cdataframe(CDATAFRAME *cdataframe) {
    if (cdataframe->size == 0) {
        printf("CDataframe is empty\n");
    }
    else {
        printf("%d\n", cdataframe->columns[0]->size);
    }
}

/**
* @brief: Display the number of columns
* @param1: Pointer to the cdataframe
*/
void nb_columns_cdataframe(CDATAFRAME *cdataframe) {
    printf("%d\n", cdataframe->size);
}

/**
* @brief: Display the number of cells equal to x
* @param1: Pointer to the cdataframe
* @param2: Value type
* @param3: Value to compare others to
*/
void nb_equal_cells_cdataframe(CDATAFRAME *cdataframe, ENUM_TYPE x_type, COL_TYPE *x) {
    int nb_equal_cells = 0;
    int column_nb;
    for (column_nb = 0; column_nb < cdataframe->size; column_nb = column_nb + 1) {
        if (x_type == NULLVAL || cdataframe->columns[column_nb]->column_type == x_type) {
            nb_equal_cells = nb_equal_cells + nb_values_equal(cdataframe->columns[column_nb], x_type, x);
        }
    }
    printf("%d\n", nb_equal_cells);
}

/**
* @brief: Display the number of cells containing a value greater than x
* @param1: Pointer to the cdataframe
* @param2: Value type
* @param3: Value to compare others to
*/
void nb_greater_cells_cdataframe(CDATAFRAME *cdataframe, ENUM_TYPE x_type, COL_TYPE *x) {
    int nb_greater_cells = 0;
    int column_nb;
    for (column_nb = 0; column_nb < cdataframe->size; column_nb = column_nb + 1) {
        if (cdataframe->columns[column_nb]->column_type == x_type) {
            nb_greater_cells = nb_greater_cells + nb_values_greater(cdataframe->columns[column_nb], x_type, x);
        }
    }
    printf("%d\n", nb_greater_cells);
}

/**
* @brief: Display the number of cells containing a value less than x
* @param1: Pointer to the cdataframe
* @param2: Value type
* @param3: Value to compare others to
*/
void nb_lower_cells_cdataframe(CDATAFRAME *cdataframe, ENUM_TYPE x_type, COL_TYPE *x) {
    int nb_lower_cells = 0;
    int column_nb;
    for (column_nb = 0; column_nb < cdataframe->size; column_nb = column_nb + 1) {
        if (cdataframe->columns[column_nb]->column_type == x_type) {
            nb_lower_cells = nb_lower_cells + nb_values_lower(cdataframe->columns[column_nb], x_type, x);
        }
    }
    printf("%d\n", nb_lower_cells);
}
