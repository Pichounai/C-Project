# C DataFrame Library

## Overview
The C DataFrame Library is a C implementation designed to mimic basic functionalities of Python's pandas library. It provides structures and methods for creating, manipulating, and analyzing structured data. This library is suitable for educational purposes and small-scale data manipulation tasks.

## Features
- Create, delete, and manage columns and dataframes.
- Insert, delete, and modify rows in the dataframe.
- Add and remove columns dynamically.
- Display dataframes and their statistical summaries.
- Search and replace values within the dataframe.

## Components
- 'column.h' and 'column.c': Manage individual data columns, including operations like insertion, deletion, and statistics.
- 'cdataframe.h' and 'cdataframe.c': Handle operations on the entire dataframe, such as adding/removing columns, rows, and performing data analysis.

## Getting Started

### Prerequisites
- C compiler (e.g., GCC)
- Basic knowledge of C programming

### Compilation
Compile the project using:
gcc -o dataframe main.c column.c cdataframe.c

### Running
After compilation, run the program with:
./dataframe

## Example Usage
#include "cdataframe.h"

int main() {
    CDATAFRAME *df = create_cdataframe();
    add_column_cdataframe(df, "Age");
    add_row_cdataframe(df);
    replace_value_cdataframe(df, 0, 0, 25);
    display_cdataframe(df);
    delete_cdataframe(df);
    return 0;
}

PS: this is what we can call an Alpha, so please take into account our mistakes. We misunderstood what we were supposed to do on this first part of the project, we did all the functions. They are not perfect, and we are going to impove it.
