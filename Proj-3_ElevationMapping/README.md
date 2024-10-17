# Elevation Mapping Project

## Overview

This C++ project demonstrates the use of the Bridges API to visualize elevation data and find various paths through a terrain. It allows users to input coordinates, visualize the elevation data, and calculate different paths based on elevation.

## Features

- Visualization of elevation data using color-coded grid
- Calculation of the path with the lowest elevation gain
- Calculation of the path with the highest elevation gain
- Calculation of the shortest path between two points
- Interactive menu for user input and control

## Prerequisites

- This project is designed to run on the Repl.it platform
- Bridges API access (API key required)

## Setup

1. Create a new C++ project on Repl.it
2. Replace the main.cpp content with the provided code
3. Install the Bridges library on Repl.it (this may require additional setup steps specific to Repl.it)
4. Replace the Bridges credentials in the main function with your own:
   ```cpp
   Bridges bridges(3, "YOUR_USERNAME", "YOUR_API_KEY");
   ```

## Usage

1. Run the program on Repl.it
2. Use the interactive menu to perform the following actions:
   - 'c': Enter coordinates for the map
   - 'p': Enter starting position
   - 'l': Calculate path with least elevation gain
   - 'm': Calculate path with most elevation gain
   - 's': Calculate shortest path
   - 'd': Display results
   - 'q': Quit the program

## Class Structure

### Elevation

- Private members:
  - `DataSource ds`
  - `dataset::ElevationData elev_data`
  - `ColorGrid myGrid`
  - `int startingRow`
- Public methods:
  - Constructor
  - `getCoordinates()`
  - `visualizeElev()`
  - `getStartingRow()`
  - `findLowestPath()`
  - `findHighestPath()`
  - `findShortestPath()`
  - `displayResult(Bridges)`

## Note on Running the Code

This code is specifically designed to work with the Bridges API and on the Repl.it platform. It cannot be run as a standalone C++ program without the proper setup and API access.

## Author

Sayed Abdul Ahad Ibrahimi

## Date

October 12, 2022

## Class

COMP 218 Fall 2022

## Disclaimer

This README assumes that the user has access to Repl.it and the necessary Bridges API credentials. The code may require modifications to run in other environments.
