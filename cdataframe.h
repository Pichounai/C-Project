//
// Created by MAC ARTHUR on 20/04/2024.
//

#ifndef C_PROJECT_CDATAFRAME_H
#define C_PROJECT_CDATAFRAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "column.h"


typedef struct {
    COLUMN **columns;
    int psize;
    int lsize;
} CDATAFRAME;


// 1. Filling
/**
* @brief: Create a cdataframe
* @return: Pointer to created cdataframe
*/
CDATAFRAME *create_cdataframe();


// 2. Display
/**
* @brief: Display the entire cdataframe
* @param1: Pointer to the cdataframe
*/
void display_cdataframe(CDATAFRAME *cdataframe);



// 3. Usual operations


/**
* @brief: add a column to the cdataframe
* @param1: Pointer to the cdataframe
* @param2: Column title
* @return: 1 if the column is added 0 otherwise
*/
int add_column_cdataframe(CDATAFRAME *cdataframe, char *column_title);

/**
* @brief: Delete a column from the cdataframe
* @param1: Pointer to the cdataframe
* @param2: Column title
* @return: 1 if the column as been deleted 0 otherwise
*/
int delete_column_cdataframe(CDATAFRAME *cdataframe, char *title);

/**
* @brief: Rename the title of a column in the CDataframe
* @param1: Pointer to the cdataframe
* @param2: Column former title
* @param3: Column new title
* @return: 1 if the column as been renamed 0 otherwise
*/
int rename_column_cdataframe(CDATAFRAME *cdataframe, char *former_title, char *new_title);

/**
* @brief: Search if a value exist in the cdataframe
* @param1: Pointer to the cdataframe
* @param2: Value to search
* @return: 1 if the value as been found 0 otherwise
*/
int search_value_cdataframe(CDATAFRAME *cdataframe, int value);

/**
* @brief: Replace the value in the cdataframe cell using its row and column number
* @param1: Pointer to the cdataframe
* @param2: Column number
* @param3: Row number
* @param4: New value
* @return: 1 if the value as been found 0 otherwise
*/
int replace_value_cdataframe(CDATAFRAME *cdataframe, int column_nb, int column_value_nb, int new_value);

/**
* @brief: Display column names
* @param1: Pointer to the cdataframe
*/
void column_names_cdataframe(CDATAFRAME *cdataframe);

// 4. Analysis and statistics


/**
* @brief: Display the number of columns
* @param1: Pointer to the cdataframe
*/
void nb_columns_cdataframe(CDATAFRAME *cdataframe);

/**
* @brief: Display the number of cells equal to x
* @param1: Pointer to the cdataframe
* @param2: Value to compare others to
*/
void nb_equal_cells_cdataframe(CDATAFRAME *cdataframe, int x);

/**
* @brief: Display the number of cells containing a value greater than x
* @param1: Pointer to the cdataframe
* @param2: Value to compare others to
*/
void nb_greater_cells_cdataframe(CDATAFRAME *cdataframe, int x);

/**
* @brief: Display the number of cells containing a value less than x
* @param1: Pointer to the cdataframe
* @param2: Value to compare others to
*/
void nb_lower_cells_cdataframe(CDATAFRAME *cdataframe, int x);





#endif //C_PROJECT_CDATAFRAME_H
