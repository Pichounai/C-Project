//
// Created by MAC ARTHUR on 29/03/2024.
//

#ifndef C_PROJECT_COLUMN_H
#define C_PROJECT_COLUMN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char *title;
    int *data;
    int psize;
    int lsize;
} COLUMN;


/**
* @brief: Create a column
* @param1 : Column title
* @return : Pointer to created column
*/
COLUMN *create_column(char *title);

/**
* @brief : Add a new value to a column
* @param1 : Pointer to a column
* @param2 : The value to be added
* @return : 1 if the value is added 0 otherwise
*/
int insert_value(COLUMN *col, int value);

/**
* @brief : Free allocated memory
* @param1 : Pointer to a column
*/
void delete_column(COLUMN *col);

/**
* @brief: Print a column content
* @param: Pointer to a column
*/
void print_col(COLUMN *col);

/**
* @brief: Return the number of occurrences of a value
* @param1: Pointer to a column
* @param2: Value to search
* @return: Number of occurrences of the value
*/
int nb_occurrences_value(COLUMN *col, int x);

/**
* @brief: Return the value present at position x
* @param1: Pointer to a column
* @param2: Position to search
* @return: The value present at position x
*/
int value_at_position(COLUMN *col, int x);

/**
* @brief: Return the number of values that are greater than x
* @param1: Pointer to a column
* @param2: Value to compare others to
* @return: The number of values that are greater than x
*/
int nb_values_greater(COLUMN *col, int x);

/**
* @brief: Return the number of values that are less than x
* @param1: Pointer to a column
* @param2: Value to compare others to
* @return: The number of values that are less than x
*/
int nb_values_lower(COLUMN *col, int x);

/**
* @brief: Return the number of values which are equal to x
* @param1: Pointer to a column
* @param2: Value to compare others to
* @return: The number of values that are equal to x
*/
int nb_values_equal(COLUMN *col, int x);


#endif //C_PROJECT_COLUMN_H
