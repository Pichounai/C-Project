d//
// Created by MAC ARTHUR on 29/03/2024.
//

#define REALOC_SIZE 256

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "column.h"


/**
* Create a new column
* @param1 : Column type
* @param2 : Column title
* @return : Pointer to the created column
*/
COLUMN *create_column(ENUM_TYPE type, char *title) {
    COLUMN *column = (COLUMN*) malloc(sizeof(COLUMN));
    column->title = (char*) malloc(strlen(title) * sizeof(char));
    column->title = strdup(title);
    column->size = 0;
    column->max_size = 0;
    column->column_type = type;
    column->data = NULL;
    return column;
}

/**
* @brief: Add a new value to a column
* @param1: Pointer to a column
* @param2: Pointer to the value to insert
* @return: 1 if the value is correctly inserted 0 otherwise
*/
int insert_value(COLUMN *col, void *value) {
    switch(col->column_type) {
        case UINT: {
            if (col->size == col->max_size) {
                COL_TYPE **test_alloc;
                if (col->data == NULL) {
                    test_alloc = (COL_TYPE**) malloc(REALOC_SIZE * sizeof(unsigned int*));
                }
                else {
                    test_alloc = realloc(col->data, (col->max_size + REALOC_SIZE) * sizeof(unsigned int*));
                }
                if (test_alloc == NULL) {
                    return 0;
                }
                col->data = test_alloc;
                col->max_size = col->max_size + REALOC_SIZE;
            }
            col->data[col->size] = (unsigned int*) malloc (sizeof(unsigned int));
            if (value == NULL) {
                col->data[col->size] = value;
            }
            else {
                *(unsigned int*)col->data[col->size] = *(unsigned int*)value;
            }
            break;
        }
        case INT: {
            if (col->size == col->max_size) {
                COL_TYPE **test_alloc;
                if (col->data == NULL) {
                        test_alloc = (COL_TYPE**) malloc(REALOC_SIZE * sizeof(int*));
                }
                else {
                    test_alloc = realloc(col->data, (col->max_size + REALOC_SIZE) * sizeof(int*));
                }
                if (test_alloc == NULL) {
                    return 0;
                }
                col->data = test_alloc;
                col->max_size = col->max_size + REALOC_SIZE;
            }
            col->data[col->size] = (int*) malloc (sizeof(int));
            if (value == NULL) {
                col->data[col->size] = value;
            }
            else {
                *(int*)col->data[col->size] = *(int*)value;
            }
            break;
        }
        case CHAR: {
            if (col->size == col->max_size) {
                COL_TYPE **test_alloc;
                if (col->data == NULL) {
                    test_alloc = (COL_TYPE**) malloc(REALOC_SIZE * sizeof(char*));
                }
                else {
                    test_alloc = realloc(col->data, (col->max_size + REALOC_SIZE) * sizeof(char*));
                }
                if (test_alloc == NULL) {
                    return 0;
                }
                col->data = test_alloc;
                col->max_size = col->max_size + REALOC_SIZE;
            }
            col->data[col->size] = (char*) malloc (sizeof(char));
            if (value == NULL) {
                col->data[col->size] = value;
            }
            else {
                *(char*)col->data[col->size] = *(char*)value;
            }
            break;
        }
        case FLOAT: {
            if (col->size == col->max_size) {
                COL_TYPE **test_alloc;
                if (col->data == NULL) {
                    test_alloc = (COL_TYPE**) malloc(REALOC_SIZE * sizeof(float*));
                }
                else {
                    test_alloc = realloc(col->data, (col->max_size + REALOC_SIZE) * sizeof(float*));
                }
                if (test_alloc == NULL) {
                    return 0;
                }
                col->data = test_alloc;
                col->max_size = col->max_size + REALOC_SIZE;
            }
            col->data[col->size] = (float*) malloc (sizeof(float));
            if (value == NULL) {
                col->data[col->size] = value;
            }
            else {
                *(float*)col->data[col->size] = *(float*)value;
            }
            break;
        }
        case DOUBLE: {
            if (col->size == col->max_size) {
                COL_TYPE **test_alloc;
                if (col->data == NULL) {
                    test_alloc = (COL_TYPE**) malloc(REALOC_SIZE * sizeof(double*));
                }
                else {
                    test_alloc = realloc(col->data, (col->max_size + REALOC_SIZE) * sizeof(double*));
                }
                if (test_alloc == NULL) {
                    return 0;
                }
                col->data = test_alloc;
                col->max_size = col->max_size + REALOC_SIZE;
            }
            col->data[col->size] = (double*) malloc (sizeof(double));
            if (value == NULL) {
                col->data[col->size] = value;
            }
            else {
                *(double*)col->data[col->size] = *(double*)value;
            }
            break;
        }
        case STRING: {
            if (col->size == col->max_size) {
                COL_TYPE **test_alloc;
                if (col->data == NULL) {
                    test_alloc = (COL_TYPE**) malloc(REALOC_SIZE * sizeof(char*));
                }
                else {
                    test_alloc = realloc(col->data, (col->max_size + REALOC_SIZE) * sizeof(char*));
                }
                if (test_alloc == NULL) {
                    return 0;
                }
                col->data = test_alloc;
                col->max_size = col->max_size + REALOC_SIZE;
            }
            col->data[col->size] = (char**) malloc(sizeof(char*));
            if (value == NULL) {
                col->data[col->size] = value;
            }
            else {
                *(char**)col->data[col->size] = *(char**)value;
            }
            break;
        }
    }
    col->size = col->size + 1;
    return 1;
}

/**
* @brief: Free the space allocated by a column
* @param1: Pointer to the column
*/
void delete_column(COLUMN *col) {
    free(col->title);
    int row_nb;
    for (row_nb = 0; row_nb < col->size; row_nb = row_nb + 1) {
        free(col->data[row_nb]);
    }
    free(col->data);
    free(col);
}

/**
* @brief: Convert a value into a string
* @param1: Pointer to the column
* @param2: Position of the value in the data array
* @param3: The string in which the value will be written
* @param4: Maximum size of the string
*/
void convert_value(COLUMN *col, unsigned long long int i, char *str, int size) {
    switch(col->column_type) {
        case UINT: {
            snprintf(str, size, "%u", *((unsigned int*)col->data[i]));
            break;
        }
        case INT: {
            snprintf(str, size, "%d", *((int*)col->data[i]));
            break;
        }
        case CHAR: {
            snprintf(str, size, "%c", *((char*)col->data[i]));
            break;
        }
        case FLOAT: {
            snprintf(str, size, "%f", *((float*)col->data[i]));
            break;
        }
        case DOUBLE: {
            snprintf(str, size, "%lf", *((double*)col->data[i]));
            break;
        }
    }
}

/**
* @brief: Display the content of a column
* @param1: Pointer to the column to display
*/
void print_col(COLUMN* col) {
    int value_nb;
    for (value_nb = 0; value_nb < col->size; value_nb = value_nb + 1) {
        if (col->data[value_nb] == NULL) {
            printf("%d) NULL\n", value_nb + 1);
        }
        else {
            if (col->column_type == STRING) {
                printf("%d) %s\n", value_nb + 1, (char*)col->data[value_nb]);
            }
            else {
                char str_value[256];
                convert_value(col, value_nb, str_value, 256);
                printf("%d) %s\n", value_nb + 1, str_value);
            }
        }
    }
}

/**
* @brief: Return the number of occurrences of a value x
* @param1: Pointer to a column
* @param2: Value type
* @param3: Value to search
* @return: The number of occurrences of the value
*/
int nb_occurrences_value(COLUMN *col, ENUM_TYPE x_type, COL_TYPE *x) {
    int nb_occurrences = 0;
    int value_nb;
    for (value_nb = 0; value_nb < col->size; value_nb = value_nb + 1) {
        switch(x_type) {
            case NULLVAL: {
                if (col->data[value_nb] == x) {
                    nb_occurrences = nb_occurrences + 1;
                }
                break;
            }
            case UINT: {
                if (col->data[value_nb] != NULL && *((unsigned int*)col->data[value_nb]) == *((unsigned int*)x)) {
                    nb_occurrences = nb_occurrences + 1;
                }
                break;
            }
            case INT: {
                if (col->data[value_nb] != NULL && *((int*)col->data[value_nb]) == *((int*)x)) {
                    nb_occurrences = nb_occurrences + 1;
                }
                break;
            }
            case CHAR: {
                if (col->data[value_nb] != NULL && *((char*)col->data[value_nb]) == *((char*)x)) {
                    nb_occurrences = nb_occurrences + 1;
                }
                break;
            }
            case FLOAT: {
                if (col->data[value_nb] != NULL && *((float*)col->data[value_nb]) == *((float*)x)) {
                    nb_occurrences = nb_occurrences + 1;
                }
                break;
            }
            case DOUBLE: {
                if (col->data[value_nb] != NULL && *((double*)col->data[value_nb]) == *((double*)x)) {
                    nb_occurrences = nb_occurrences + 1;
                }
                break;
            }
            case STRING: {
                if (col->data[value_nb] != NULL && strcmp((char*)col->data[value_nb], (char*)x) == 0) {
                    nb_occurrences = nb_occurrences + 1;
                }
                break;
            }
        }
    }
    return nb_occurrences;
}

/**
* @brief: Return the value present at position x
* @param1: Pointer to a column
* @param2: Position to search
* @param3: The string in which the value will be written
* @return: The value present at position x
*/
char *value_at_position(COLUMN *col, int x, char *str) {
    if (x > col->size || col->data[x - 1] == NULL) {
        str = NULL;
    }
    else {
        if (col->column_type == STRING) {
            str = (char*)col->data[x - 1];
        }
        else {
            convert_value(col, x - 1, str, 256);
        }
    }
    return str;
}

/**
* @brief: Return the number of values that are greater than x
* @param1: Pointer to a column
* @param2: Value type
* @param3: Value to compare the others to
* @return: The number of values that are greater than x
*/
int nb_values_greater(COLUMN *col, ENUM_TYPE x_type, COL_TYPE *x) {
    int nb_greater_values = 0;
    int value_nb;
    for (value_nb = 0; value_nb < col->size; value_nb = value_nb + 1) {
        switch(x_type) {
            case UINT: {
                if (col->data[value_nb] != NULL && *((unsigned int*)col->data[value_nb]) > *((unsigned int*)x)) {
                    nb_greater_values = nb_greater_values + 1;
                }
                break;
            }
            case INT: {
                if (col->data[value_nb] != NULL && *((int*)col->data[value_nb]) > *((int*)x)) {
                    nb_greater_values = nb_greater_values + 1;
                }
                break;
            }
            case CHAR: {
                if (col->data[value_nb] != NULL && *((char*)col->data[value_nb]) > *((char*)x)) {
                    nb_greater_values = nb_greater_values + 1;
                }
                break;
            }
            case FLOAT: {
                if (col->data[value_nb] != NULL && *((float*)col->data[value_nb]) > *((float*)x)) {
                    nb_greater_values = nb_greater_values + 1;
                }
                break;
            }
            case DOUBLE: {
                if (col->data[value_nb] != NULL && *((double*)col->data[value_nb]) > *((double*)x)) {
                    nb_greater_values = nb_greater_values + 1;
                }
                break;
            }
            case STRING: {
                if (col->data[value_nb] != NULL && strcmp((char*)col->data[value_nb], (char*)x) > 0) {
                    nb_greater_values = nb_greater_values + 1;
                }
                break;
            }
        }
    }
    return nb_greater_values;
}

/**
* @brief: Return the number of values that are less than x
* @param1: Pointer to a column
* @param2: Value type
* @param3: Value to compare the others to
* @return: The number of values that are less than x
*/
int nb_values_lower(COLUMN *col, ENUM_TYPE x_type, COL_TYPE *x) {
    int nb_lower_values = 0;
    int value_nb;
    for (value_nb = 0; value_nb < col->size; value_nb = value_nb + 1) {
        switch(x_type) {
            case UINT: {
                if (col->data[value_nb] != NULL && *((unsigned int*)col->data[value_nb]) < *((unsigned int*)x)) {
                    nb_lower_values = nb_lower_values + 1;
                }
                break;
            }
            case INT: {
                if (col->data[value_nb] != NULL && *((int*)col->data[value_nb]) < *((int*)x)) {
                    nb_lower_values = nb_lower_values + 1;
                }
                break;
            }
            case CHAR: {
                if (col->data[value_nb] != NULL && *((char*)col->data[value_nb]) < *((char*)x)) {
                    nb_lower_values = nb_lower_values + 1;
                }
                break;
            }
            case FLOAT: {
                if (col->data[value_nb] != NULL && *((float*)col->data[value_nb]) < *((float*)x)) {
                    nb_lower_values = nb_lower_values + 1;
                }
                break;
            }
            case DOUBLE: {
                if (col->data[value_nb] != NULL && *((double*)col->data[value_nb]) < *((double*)x)) {
                    nb_lower_values = nb_lower_values + 1;
                }
                break;
            }
            case STRING: {
                if (col->data[value_nb] != NULL && strcmp((char*)col->data[value_nb], (char*)x) < 0) {
                    nb_lower_values = nb_lower_values + 1;
                }
                break;
            }
        }
    }
    return nb_lower_values;
}

/**
* @brief: Return the number of values which are equal to x (literally the same as the occurrence)
* @param1: Pointer to a column
* @param2: Value type
* @param3: Value to compare the others to
* @return: The number of values that are equal to x
*/
int nb_values_equal(COLUMN *col, ENUM_TYPE x_type, COL_TYPE *x) {
    int nb_equal_values = 0;
    int value_nb;
    for (value_nb = 0; value_nb < col->size; value_nb = value_nb + 1) {
        switch(x_type) {
            case NULLVAL: {
                if (col->data[value_nb] == x) {
                    nb_equal_values = nb_equal_values + 1;
                }
                break;
            }
            case UINT: {
                if (col->data[value_nb] != NULL && *((unsigned int*)col->data[value_nb]) == *((unsigned int*)x)) {
                    nb_equal_values = nb_equal_values + 1;
                }
                break;
            }
            case INT: {
                if (col->data[value_nb] != NULL && *((int*)col->data[value_nb]) == *((int*)x)) {
                    nb_equal_values = nb_equal_values + 1;
                }
                break;
            }
            case CHAR: {
                if (col->data[value_nb] != NULL && *((char*)col->data[value_nb]) == *((char*)x)) {
                    nb_equal_values = nb_equal_values + 1;
                }
                break;
            }
            case FLOAT: {
                if (col->data[value_nb] != NULL && *((float*)col->data[value_nb]) == *((float*)x)) {
                    nb_equal_values = nb_equal_values + 1;
                }
                break;
            }
            case DOUBLE: {
                if (col->data[value_nb] != NULL && *((double*)col->data[value_nb]) == *((double*)x)) {
                    nb_equal_values = nb_equal_values + 1;
                }
                break;
            }
            case STRING: {
                if (col->data[value_nb] != NULL && strcmp((char*)col->data[value_nb], (char*)x) == 0) {
                    nb_equal_values = nb_equal_values + 1;
                }
                break;
            }
        }
    }
    return nb_equal_values;
}
