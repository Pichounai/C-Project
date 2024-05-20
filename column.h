//
// Created by MAC ARTHUR on 29/03/2024.
//

#ifndef C_PROJECT_COLUMN_H
#define C_PROJECT_COLUMN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum enum_type
{
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum enum_type ENUM_TYPE;

union column_type{
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
};
typedef union column_type COL_TYPE;

struct column {
    char *title;
    unsigned int size; //logical size
    unsigned int max_size; //physical size
    ENUM_TYPE column_type;
    COL_TYPE **data; // array of pointers to stored data
    unsigned long long int *index; // array of integers
};
typedef struct column COLUMN;


/**
* Create a new column
* @param1 : Column type
* @param2 : Column title
* @return : Pointer to the created column
*/
COLUMN *create_column(ENUM_TYPE type, char *title);

/**
* @brief: Add a new value to a column
* @param1: Pointer to a column
* @param2: Pointer to the value to insert
* @return: 1 if the value is correctly inserted 0 otherwise
*/
int insert_value(COLUMN *col, void *value);

/**
* @brief: Free the space allocated by a column
* @param1: Pointer to the column
*/
void delete_column(COLUMN *col);

/**
* @brief: Convert a value into a string
* @param1: Pointer to the column
* @param2: Position of the value in the data array
* @param3: The string in which the value will be written
* @param4: Maximum size of the string
*/
void convert_value(COLUMN *col, unsigned long long int i, char *str, int size);

/**
* @brief: Display the content of a column
* @param1: Pointer to the column to display
*/
void print_col(COLUMN* col);

/**
* @brief: Return the number of occurrences of a value x
* @param1: Pointer to a column
* @param2: Value type
* @param3: Value to search
* @return: The number of occurrences of the value
*/
int nb_occurrences_value(COLUMN *col, ENUM_TYPE x_type, COL_TYPE *x);

/**
* @brief: Return the value present at position x
* @param1: Pointer to a column
* @param2: Position to search
* @param3: The string in which the value will be written
* @return: The value present at position x
*/
char *value_at_position(COLUMN *col, int x, char *str);

/**
* @brief: Return the number of values that are greater than x
* @param1: Pointer to a column
* @param2: Value type
* @param3: Value to compare the others to
* @return: The number of values that are greater than x
*/
int nb_values_greater(COLUMN *col, ENUM_TYPE x_type, COL_TYPE *x);

/**
* @brief: Return the number of values that are less than x
* @param1: Pointer to a column
* @param2: Value type
* @param3: Value to compare the others to
* @return: The number of values that are less than x
*/
int nb_values_lower(COLUMN *col, ENUM_TYPE x_type, COL_TYPE *x);

/**
* @brief: Return the number of values which are equal to x (literally the same as the occurrence)
* @param1: Pointer to a column
* @param2: Value type
* @param3: Value to compare the others to
* @return: The number of values that are equal to x
*/
int nb_values_equal(COLUMN *col, ENUM_TYPE x_type, COL_TYPE *x);


#endif //C_PROJECT_COLUMN_H
