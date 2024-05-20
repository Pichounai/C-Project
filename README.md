# C DataFrame Library

## Overview
The C DataFrame Library is a C implementation designed to mimic basic functionalities of Python's pandas library. It provides structures and methods for creating, manipulating, and analyzing structured data. This library is suitable for educational purposes and small-scale data manipulation tasks.

## Features
- Create and fill dataframes with dynamic columns and rows.
- Display the entire dataframe or specific rows and columns.
- Perform basic data manipulation (add/delete/rename columns and rows).
- Basic statistical operations on the data.

## Compilation
To compile the project, use the following command:

"gcc -o cdataframe main.c cdataframe.c column.c"

# CDataframe Project

## Overview
The CDataframe project implements a simple dataframe structure in C, allowing for dynamic creation, manipulation, and analysis of tabular data.

## Files
- cdataframe.c and cdataframe.h: Implementation and definitions for CDATAFRAME structure and functions.
- column.c and column.h: Implementation and definitions for COLUMN structure and functions.
- main.c: Demonstrates and tests the functionalities.

## Usage
Run the compiled executable:

"./cdataframe"

Follow on-screen instructions to interact with the dataframe.

Example Functions
- Create Dataframe: CDATAFRAME *create_cdataframe()
- Add Column: int add_column_cdataframe(CDATAFRAME *cdataframe, char *column_title)
- Add Row: int add_row_cdataframe(CDATAFRAME *cdataframe)
- Display Dataframe: void display_cdataframe(CDATAFRAME *cdataframe)

## Components
- 'column.h' and 'column.c': Manage individual data columns, including operations like insertion, deletion, and statistics.
- 'cdataframe.h' and 'cdataframe.c': Handle operations on the entire dataframe, such as adding/removing columns, rows, and performing data analysis.
