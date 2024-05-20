# Project CDataFrame

## GitHub Link
https://github.com/Pichounai/C-Project.git

## Overview
In this project our objective was to implement a dataframe in C language with basic functionalities. We could choose from several solutions for this project. Our group chose to have all data types columns, a dynamic array CDataframe and basic functionalities.

## Features
- Create and fill dataframes with dynamic columns and rows.
- Display the entire dataframe or specific rows and columns.
- Perform basic data manipulation (add/delete/rename columns and rows).
- Basic operations on the data.

## Files
- cdataframe.c and cdataframe.h: Implementation and definitions for CDATAFRAME structure and functions.
- column.c and column.h: Implementation and definitions for COLUMN structure and functions.
- main.c: Demonstrates and tests the functionalities.

## Usage
Example Functions
- Create Dataframe: CDATAFRAME *create_cdataframe()
- Add Column: int add_column_cdataframe(CDATAFRAME *cdataframe, char *column_title)
- Add Row: int add_row_cdataframe(CDATAFRAME *cdataframe)
- Display Dataframe: void display_cdataframe(CDATAFRAME *cdataframe)
