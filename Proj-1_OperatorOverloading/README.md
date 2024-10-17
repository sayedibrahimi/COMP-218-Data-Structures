# Timer Class Project

## Overview

This C++ project demonstrates the implementation of a `timer` class with operator overloading. The class represents time in hours, minutes, and seconds, and provides various operations for time manipulation and display.

## Features

- Time representation in hh:mm:ss format
- Addition of two time objects
- Addition of seconds to a time object
- Deep copy of time objects
- Formatted input and output of time

## Class Structure

### timer

- Private members:
  - `int hour`
  - `int minute`
  - `int second`
- Public methods:
  - Default constructor
  - Overloaded operators:
    - `+` (time + time, time + int)
    - `=` (deep copy)
    - `+=` (time += time, time += int)
    - `<<` (output)
    - `>>` (input)

## Operator Overloading

1. `+`: Add two times or add seconds to a time
2. `=`: Perform a deep copy of one time to another
3. `+=`: Add and assign (for both time and seconds)
4. `<<`: Output time in hh:mm:ss format
5. `>>`: Input time in hh:mm:ss format

## Usage

1. Compile the program:
   ```
   g++ -o timer_program sibrahimiDS1.cpp
   ```
2. Run the compiled program:
   ```
   ./timer_program
   ```
3. Follow the prompts to input time values and see the results of various operations.

## Example Operations

- Adding two time objects
- Adding seconds to a time object
- Copying time objects
- Displaying time in formatted output

## Input Format

Time should be entered in the format hh:mm:ss (e.g., 12:30:45)

## Error Handling

The program includes basic error checking for invalid minute and second values (must be between 0 and 59).

## Author

Sayed Abdul Ahad Ibrahimi

## Date

September 11, 2022

## Class

COMP 218 Fall 2022

## Notes

- This project is designed to demonstrate operator overloading in C++.
- The main function includes various test cases to showcase the functionality of the timer class.
