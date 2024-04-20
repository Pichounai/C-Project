//
// Created by MAC ARTHUR on 29/03/2024.
//

#define REALOC_SIZE 256

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "column.h"


/**
* @brief: Create a column
* @param1: Column title
* @return: Pointer to created column
*/
COLUMN *create_column(char *title) {
    COLUMN *pointer_column = (COLUMN*) malloc(sizeof(COLUMN));
    pointer_column->title = (char*) malloc(strlen(title) * sizeof(char));
    pointer_column->title = strdup(title);
    pointer_column->data = NULL;
    pointer_column->psize = 0;
    pointer_column->lsize = 0;
    return pointer_column;
}

/**
* @brief: Add a new value to a column
* @param1: Pointer to a column
* @param2: Value to be added
* @return: 1 if the value is added 0 otherwise
*/
int insert_value(COLUMN *col, int value) {
    if (col->lsize == col->psize) {
        int *test_alloc = NULL;
        if (col->data == NULL) {
            test_alloc = (int*) malloc(REALOC_SIZE * sizeof(int));
        }
        else {
            test_alloc = realloc(col->data, (col->psize + REALOC_SIZE) * sizeof(int));
        }
        if (test_alloc == NULL) {
            return 0;
        }
        free(col->data);
        col->data = test_alloc;
        col->psize = col->psize + REALOC_SIZE;
    }
    col->data[col->lsize] = value;
    col->lsize = col->lsize + 1;
    return 1;
}

/**
* @brief: Free allocated memory
* @param1: Pointer to a column
*/
void delete_column(COLUMN *col) {
    free(col->title);
    free(col->data);
    free(col);
}

/**
* @brief: Print a column content
* @param1: Pointer to a column
*/
void print_col(COLUMN *col) {
    int value_nb;
    for (value_nb = 0; value_nb < col->lsize; value_nb = value_nb + 1) {
        printf("[%d] %d\n", value_nb, col->data[value_nb]);
    }
}

/**
* @brief: Return the number of occurrences of a value x
* @param1: Pointer to a column
* @param2: Value to search
* @return: The number of occurrences of the value
*/
int nb_occurrences_value(COLUMN *col, int x) {
    int nb_occurrences = 0;
    int value_nb;
    for (value_nb = 0; value_nb < col->lsize; value_nb = value_nb + 1) {
        if (col->data[value_nb] == x) {
            nb_occurrences = nb_occurrences + 1;
        }
    }
    return nb_occurrences;
}

/**
* @brief: Return the value present at position x
* @param1: Pointer to a column
* @param2: Position to search
* @return: The value present at position x or -1 if the column is not long enough
*/
int value_at_position(COLUMN *col, int x) {
    if (x > col->lsize) {
        return -1;
    }
    return col->data[x-1];
}

/**
* @brief: Return the number of values that are greater than x
* @param1: Pointer to a column
* @param2: Value to compare the others to
* @return: The number of values that are greater than x
*/
int nb_values_greater(COLUMN *col, int x) {
    int nb_greater_values = 0;
    int value_nb;
    for (value_nb = 0; value_nb < col->lsize; value_nb = value_nb + 1) {
        if (col->data[value_nb] > x) {
            nb_greater_values = nb_greater_values + 1;
        }
    }
    return nb_greater_values;
}

/**Return the number of values that are less than x*/
/**
* @brief: Return the number of values that are less than x
* @param1: Pointer to a column
* @param2: Value to compare the others to
* @return: The number of values that are less than x
*/
int nb_values_lower(COLUMN *col, int x) {
    int nb_lower_values = 0;
    int value_nb;
    for (value_nb = 0; value_nb < col->lsize; value_nb = value_nb + 1) {
        if (col->data[value_nb] < x) {
            nb_lower_values = nb_lower_values + 1;
        }
    }
    return nb_lower_values;
}

/**
* @brief: Return the number of values which are equal to x
* @param1: Pointer to a column
* @param2: Value to compare the others to
* @return: The number of values that are equal to x
*/
int nb_values_equal(COLUMN *col, int x) {
    int nb_equal_values = 0;
    int value_nb;
    for (value_nb = 0; value_nb < col->lsize; value_nb = value_nb + 1) {
        if (col->data[value_nb] == x) {
            nb_equal_values = nb_equal_values + 1;
        }
    }
    return nb_equal_values;
}
