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

/**
* @brief: Filling in the CDataframe with user input
* @param1: Pointer to the cdataframe
*/
void filling_cdataframe(CDATAFRAME *cdataframe) {
    if (cdataframe->lsize != 0) {
        printf("The CDataframe is already filled\n");
    }
    else {
        int nb_columns_to_add;
        printf("Enter the number of the columns you want to add :");
        scanf("%d", &nb_columns_to_add);
        printf("\n");
        int nb_rows_to_add;
        printf("Enter the number of the rows you want to add :");
        scanf("%d", &nb_rows_to_add);
        printf("\n");
        int column_nb, row_nb;
        for (column_nb = 0; column_nb < nb_columns_to_add; column_nb = column_nb + 1) {
            if (column_nb == 0) {
                add_column_cdataframe(cdataframe, "1st column");
            }
            else {
                if (column_nb == 1) {
                    add_column_cdataframe(cdataframe, "2nd column");
                }
                else {
                    if (column_nb == 2) {
                        add_column_cdataframe(cdataframe, "3rd column");
                    }
                    else {
                        char column_name[12];
                        sprintf(column_name, "%dth column", column_nb + 1);
                        add_column_cdataframe(cdataframe, column_name);
                    }
                }
            }
            printf("%s :\n", cdataframe->columns[column_nb]->title);
            for (row_nb = 0; row_nb < nb_rows_to_add; row_nb = row_nb + 1) {
                int value_to_add;
                printf("Enter a value :");
                scanf("%d", &value_to_add);
                if (column_nb == 0) {
                    insert_value(cdataframe->columns[column_nb], value_to_add);
                }
                else {
                    replace_value_cdataframe(cdataframe, column_nb + 1, row_nb + 1, value_to_add);
                }
                printf("\n");
            }
        }
        printf("CDataframe is filled\n");
    }
}

/**
* @brief: Hard filling of the cdataframe
* @param1: Pointer to the cdataframe
* @return: 1 if the cdataframe as been filled 0 if the cdataframe already contained things
*/
int hard_filling_cdataframe(CDATAFRAME *cdataframe) {
    if (cdataframe->psize != 0) {
        return 0;
    }
    int column_nb, column_value_nb;
    for (column_nb = 0; column_nb < REALOC_SIZE; column_nb = column_nb + 1) {
        if (column_nb == 0) {
            add_column_cdataframe(cdataframe, "1st column");
        }
        else {
            if (column_nb == 1) {
                add_column_cdataframe(cdataframe, "2nd column");
            }
            else {
                if (column_nb == 2) {
                    add_column_cdataframe(cdataframe, "3rd column");
                }
                else {
                    char column_name[12];
                    sprintf(column_name, "%dth column", column_nb + 1);
                    add_column_cdataframe(cdataframe, column_name);
                }
            }
        }
        for (column_value_nb = 0; column_value_nb < REALOC_SIZE; column_value_nb = column_value_nb + 1) {
            insert_value(cdataframe->columns[column_nb], 0);
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

/**
* @brief: Dispalay a part of the CDataframe rows according to a user-provided limit
* @param1: Pointer to the cdataframe
*/
void display_rows_cdataframe(CDATAFRAME *cdataframe) {
    if (cdataframe->lsize == 0) {
        printf("CDataframe is empty\n");
    }
    else {
        int first_row_display, last_row_display;
        printf("From witch row do you want to begin to display :");
        scanf("%d", &first_row_display);
        printf("\n");
        printf("At witch row do you want to end to display :");
        scanf("%d", &last_row_display);
        printf("\n");
        if (first_row_display -1 > cdataframe->columns[0]->lsize || last_row_display - 1 > cdataframe->columns[0]->lsize || first_row_display > last_row_display) {
            printf("Not possible\n");
        }
        else {
            int row_nb, column_nb;
            for (row_nb = first_row_display - 1; row_nb < last_row_display; row_nb = row_nb + 1) {
                printf("%d. ", row_nb + 1);
                for (column_nb = 0; column_nb < cdataframe->lsize; column_nb = column_nb + 1) {
                    printf("%d", cdataframe->columns[column_nb]->data[row_nb]);
                    if (column_nb != cdataframe->lsize - 1) {
                        printf(" ");
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
    if (cdataframe->lsize == 0) {
        printf("CDataframe is empty\n");
    }
    else {
        int first_column_display, last_column_display;
        printf("From witch column do you want to begin to display :");
        scanf("%d", &first_column_display);
        printf("\n");
        printf("At witch column do you want to end to display :");
        scanf("%d", &last_column_display);
        printf("\n");
        if (first_column_display -1 > cdataframe->lsize || last_column_display - 1 > cdataframe->lsize || first_column_display > last_column_display) {
            printf("Not possible\n");
        }
        else {
            int column_nb, row_nb;
            for (column_nb = first_column_display - 1; column_nb < last_column_display; column_nb = column_nb + 1) {
                printf("%d. %s : ", column_nb + 1, cdataframe->columns[column_nb]->title);
                for (row_nb = 0; row_nb < cdataframe->columns[column_nb]->lsize; row_nb = row_nb + 1) {
                    printf("%d", cdataframe->columns[column_nb]->data[row_nb]);
                    if (row_nb != cdataframe->columns[column_nb]->lsize - 1) {
                        printf(" ");
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
    if (cdataframe->lsize == 0) {
        return 0;
    }
    int column_nb;
    for (column_nb = 0; column_nb < cdataframe->lsize; column_nb = column_nb + 1) {
        insert_value(cdataframe->columns[column_nb], 0);
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
    if (cdataframe->lsize != 0 && cdataframe->columns[0]->lsize >= target_row_nb) {
        int column_nb, row_nb;
        for (column_nb = 0; column_nb < cdataframe->lsize; column_nb = column_nb + 1) {
            for (row_nb = target_row_nb - 1; row_nb < cdataframe->columns[column_nb]->lsize - 1; row_nb = row_nb + 1) {
                cdataframe->columns[column_nb]->data[row_nb] = cdataframe->columns[column_nb]->data[row_nb + 1];
            }
            cdataframe->columns[column_nb]->lsize = cdataframe->columns[column_nb]->lsize - 1;
        }
        return 1;
    }
    return 0;
}

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
    int row_nb;
    for (row_nb = 0; row_nb < cdataframe->columns[0]->lsize; row_nb = row_nb + 1) {
        insert_value(cdataframe->columns[cdataframe->lsize], 0);
    }
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
* @return: 1 if the value as been replaced 0 otherwise
*/
int replace_value_cdataframe(CDATAFRAME *cdataframe, int column_nb, int row_nb, int new_value) {
    if (cdataframe->lsize > column_nb - 1 && cdataframe->columns[column_nb - 1]->lsize > row_nb - 1) {
        cdataframe->columns[column_nb - 1]->data[row_nb - 1] = new_value;
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
* @brief: Display the number of rows
* @param1: Pointer to the cdataframe
*/
void nb_rows_cdataframe(CDATAFRAME *cdataframe) {
    if (cdataframe->lsize == 0) {
        printf("CDataframe is empty\n");
    }
    else {
        printf("%d\n", cdataframe->columns[0]->lsize);
    }
}

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
