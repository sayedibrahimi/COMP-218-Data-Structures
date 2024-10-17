# Number Classes Project

## Overview

This C++ project demonstrates the use of operator overloading with inheritance. It includes a base class `Number` and derived classes `Lint`, `Int`, and `Float`, each representing different types of numbers with specific functionalities.

## Class Structure

### Number (Base Class)

- Stores any number as a string
- Overloaded operators:
  - `<<` for output
  - `>>` for input

### Lint (Derived from Number)

- Stores numbers up to 30 digits
- Overloaded operators:
  - `+` for addition
  - `=` for deep copy
  - `++` for increment
  - `=` for assigning an int

### Int (Derived from Lint)

- Stores integers up to 2,147,483,647
- Inherits methods from Lint
- Additional overloaded operator:
  - `+=` for adding an int and deep copying

### Float (Derived from Number)

- Stores floating-point numbers
- Overloaded operators:
  - `=` for deep copy
  - `+` for addition

## Features

- Input and output of different number types
- Arithmetic operations on large integers (Lint)
- Inheritance demonstration with specialized number classes
- Operator overloading for intuitive usage

## Usage

1. Compile the program using a C++ compiler (e.g., g++):
   ```
   g++ -o number_classes sibrahimiDS2.cpp
   ```
2. Run the compiled program:
   ```
   ./number_classes
   ```
3. Follow the prompts to input numbers and see the results of various operations.

## Example Operations

- Adding two Lint numbers
- Assigning one Lint to another
- Incrementing a Lint
- Assigning an int to a Lint
- (Commented out) Operations with Int and Float classes

## Notes

- The main function currently demonstrates Lint operations. Int and Float operations are commented out but can be uncommented for testing.
- Ensure input numbers for Lint do not exceed 30 digits.
- The program includes assertions to check for valid input sizes.

## Author

Sayed Abdul Ahad Ibrahimi

## Date

September 27, 2022

## Class

COMP 218 Fall 2022
