//
// Created by MAC ARTHUR on 29/03/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "column.h"


int main() {
    // create_column test:
    COLUMN *mycol = create_column("My column\0");
    /**printf("%s", mycol->title);*/

    // insert_value test:
    /**int val = 5;
    if (insert_value(mycol, val))
        printf("%d", mycol->data[0]);
    else
        printf("Error adding value to my column\n");*/

    // delete_column test:
    /**delete_column(&mycol);*/

    // print_col test:
    /**insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 15);
    print_col(mycol);*/

    // nb_occurrences_value test:
    /**insert_value(mycol, 52);
    insert_value(mycol, 52);
    insert_value(mycol, 52);
    printf("%d", nb_occurrences_value(mycol, 52));*/

    // value_at_position test:
    /**insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 15);
    printf("%d", value_at_position(mycol, 2));*/

    // nb_values_greater test:
    /**insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 44);
    insert_value(mycol, 15);
    printf("%d", nb_values_greater(mycol, 44));*/

    // nb_values_lower test:
    /**insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 44);
    insert_value(mycol, 15);
    printf("%d", nb_values_lower(mycol, 44));*/

    // nb_values_equal test:
    /**insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 44);
    insert_value(mycol, 15);
    printf("%d", nb_values_equal(mycol, 44));*/

    // free mycol:
    free(mycol->title);
    free(mycol->data);
    return 0;
}
