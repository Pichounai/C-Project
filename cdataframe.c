//
// Created by MAC ARTHUR on 20/04/2024.
//

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
    CDATAFRAME *pointer_cdataframe = (CDATAFRAME*) malloc(sizeof(CDATAFRAME));
    pointer_cdataframe->columns = NULL;
    pointer_cdataframe->psize = 0;
    pointer_cdataframe->lsize = 0;
    return pointer_cdataframe;
}

// 2. Display
/**
* @brief: Display the entire cdataframe
* @param1: Pointer to the cdataframe
*/
void display_cdataframe(CDATAFRAME *cdataframe) {
    if (cdataframe->lsize == 0) {
        printf("CDataframe is empty\n");
    }
    else {
        printf("CDataframe:\n");
        int column_nb;
        for (column_nb = 0; column_nb < cdataframe->lsize; column_nb = column_nb + 1) {
            printf("%d. %s:\n", column_nb + 1, cdataframe->columns[column_nb]->title);
            print_col(cdataframe->columns[column_nb]);
        }
    }
}


// 3. Usual operations

/**
* @brief: Add a column to the cdataframe
* @param1: Pointer to the cdataframe
* @param2: Column title
* @return: 1 if the column as been added 0 otherwise
*/
int add_column_cdataframe(CDATAFRAME *cdataframe, char *column_title) {
    if (cdataframe->lsize == cdataframe->psize) {
        COLUMN **test_alloc = NULL;
        if (cdataframe->columns == NULL) {
            test_alloc = (COLUMN**) malloc(REALOC_SIZE * sizeof(COLUMN*));
        }
        else {
            test_alloc = realloc(cdataframe->columns, (cdataframe->psize + REALOC_SIZE) * sizeof(COLUMN*));
        }
        if (test_alloc == NULL) {
            return 0;
        }
        free(cdataframe->columns);
        cdataframe->columns = NULL;
        cdataframe->columns = test_alloc;
        cdataframe->psize = cdataframe->psize + REALOC_SIZE;
    }
    cdataframe->columns[cdataframe->lsize] = create_column(column_title);
    cdataframe->lsize = cdataframe->lsize + 1;
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
        int column_nb, character_nb, target;
        for (column_nb = 0; column_nb < cdataframe->lsize; column_nb = column_nb + 1) {
            target = 1;
            character_nb = 0;
            while (character_nb < strlen(cdataframe->columns[column_nb]->title) && target == 1) {
                if (cdataframe->columns[column_nb]->title[character_nb] != title[character_nb]) {
                    target = 0;
                }
                character_nb = character_nb + 1;
            }
            if (target == 1) {
                delete_column(cdataframe->columns[column_nb]);
                for (column_nb = column_nb; column_nb < cdataframe->lsize - 1; column_nb = column_nb + 1) {
                    cdataframe->columns[column_nb] = cdataframe->columns[column_nb + 1];
                }
                cdataframe->lsize = cdataframe->lsize - 1;
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
        int column_nb, character_nb, target;
        for (column_nb = 0; column_nb < cdataframe->lsize; column_nb = column_nb + 1) {
            target = 1;
            character_nb = 0;
            while (character_nb < strlen(cdataframe->columns[column_nb]->title) && target == 1) {
                if (cdataframe->columns[column_nb]->title[character_nb] != former_title[character_nb]) {
                    target = 0;
                }
                character_nb = character_nb + 1;
            }
            if (target == 1) {
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
* @param2: Value to search
* @return: 1 if the value as been found 0 otherwise
*/
int search_value_cdataframe(CDATAFRAME *cdataframe, int value) {
    if (cdataframe->columns != NULL) {
        int column_nb, column_value_nb;
        for (column_nb = 0; column_nb < cdataframe->lsize; column_nb = column_nb + 1) {
            for (column_value_nb = 0; column_value_nb < cdataframe->columns[column_nb]->lsize; column_value_nb = column_value_nb + 1) {
                if (cdataframe->columns[column_nb]->data[column_value_nb] == value) {
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
* @param4: New value
* @return: 1 if the value as been found 0 otherwise
*/
int replace_value_cdataframe(CDATAFRAME *cdataframe, int column_nb, int column_value_nb, int new_value) {
    if (cdataframe->lsize >= column_nb && cdataframe->columns[column_nb]->lsize >= column_value_nb) {
        cdataframe->columns[column_nb - 1]->data[column_value_nb - 1] = new_value;
        return 1;
    }
    return 0;
}

/**
* @brief: Display column names
* @param1: Pointer to the cdataframe
*/
void column_names_cdataframe(CDATAFRAME *cdataframe) {
    if (cdataframe->lsize == 0) {
        printf("CDataframe is empty\n");
    }
    else {
        printf("CDataframe column names: ");
        int column_nb;
        for (column_nb = 0; column_nb < cdataframe->lsize; column_nb = column_nb + 1) {
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
* @brief: Display the number of columns
* @param1: Pointer to the cdataframe
*/
void nb_columns_cdataframe(CDATAFRAME *cdataframe) {
    printf("%d\n", cdataframe->lsize);
}

/**
* @brief: Display the number of cells equal to x
* @param1: Pointer to the cdataframe
* @param2: Value to compare others to
*/
void nb_equal_cells_cdataframe(CDATAFRAME *cdataframe, int x) {
    int nb_equal_cells = 0;
    int column_nb;
    for (column_nb = 0; column_nb < cdataframe->lsize; column_nb = column_nb + 1) {
        nb_equal_cells = nb_equal_cells + nb_values_equal(cdataframe->columns[column_nb], x);
    }
    printf("%d\n", nb_equal_cells);
}

/**
* @brief: Display the number of cells containing a value greater than x
* @param1: Pointer to the cdataframe
* @param2: Value to compare others to
*/
void nb_greater_cells_cdataframe(CDATAFRAME *cdataframe, int x) {
    int nb_greater_cells = 0;
    int column_nb;
    for (column_nb = 0; column_nb < cdataframe->lsize; column_nb = column_nb + 1) {
        nb_greater_cells = nb_greater_cells + nb_values_greater(cdataframe->columns[column_nb], x);
    }
    printf("%d\n", nb_greater_cells);
}

/**
* @brief: Display the number of cells containing a value less than x
* @param1: Pointer to the cdataframe
* @param2: Value to compare others to
*/
void nb_lower_cells_cdataframe(CDATAFRAME *cdataframe, int x) {
    int nb_lower_cells = 0;
    int column_nb;
    for (column_nb = 0; column_nb < cdataframe->lsize; column_nb = column_nb + 1) {
        nb_lower_cells = nb_lower_cells + nb_values_lower(cdataframe->columns[column_nb], x);
    }
    printf("%d\n", nb_lower_cells);
}





