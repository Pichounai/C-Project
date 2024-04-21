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

PS: this is what we can call an Alpha, so please take into account our mistakes. We misunderstood what we were supposed to do on this first part of the project, we did all the functions.
They are not perfect (they are even pretty bad actually), and we are going to improve it.
Also, since we are still unsure about what solutions to use, we used the most basic ones (Columns: Integers only -> CDataframe: Dynamic array -> Functionalities: Basic). Those solutions might be subjects to potential changes in the future.
