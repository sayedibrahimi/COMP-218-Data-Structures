/*
 * Programmer: Sayed Abdul Ahad Ibrahimi
 * Date      : 10/12/22
 * Class     : COMP 218 Fall 2022
 * File      : sibrahimiDS3.cpp

  - A constructor
  - A method to choose the coordinates or uses the default coordinates
  - A method to visualize a map with different colors for elevations and paths
  - A method to find the path with the lowest elevation
  - A method to find the path with the highest elevation
  - A method to find the shortest path between a the start row and ending row
  - A method to display the data
 * Input: coordinates, starting row and ending row
 * Output: visualized map with lowest and highest elevation path and shortest path from
 * starting row to ending row
 *
 * Description: This program visualizes the a map with different colors for elevations and paths
 *
*/
#include "Bridges.h"
#include "DataSource.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include "data_src/ElevationData.h"
#include "Color.h"
#include "ColorGrid.h"

using namespace std;
using namespace bridges;

class Elevation
{
  DataSource ds;                    // Bridges object
  dataset::ElevationData elev_data; // Bridges to store to the object
  ColorGrid myGrid;                 // Bridges object for coloring grid
  int startingRow;                  // to store starting position

public:
  Elevation();
  void getCoordinates();
  void visualizeElev();
  void getStartingRow();
  void findLowestPath();
  void findHighestPath();
  void findShortestPath();
  void displayResult(Bridges);
};
//-------------------------------Constructor-------------------------
/*
 * default constructor
 */
Elevation ::Elevation()
{
  startingRow = 0;
}
//------------------------------getCoordinates method--------------------
/*
 * Method to prompt the user to input their own coordinates otherwise uses default coordinates
 */
void Elevation ::getCoordinates()
{
  float x1 = 0, y1 = 0, x2 = 0, y2 = 0; // stores 4 coordinates
  char own;
  cout << "Do you want to enter your own coordinates? (Y/N)" << endl;
  cin >> own;
  if (own == 'Y' || own == 'y')
  {
    cout << "Enter the minimum latitude: ";
    cin >> x1;
    cout << "Enter the minimum longitude: ";
    cin >> y1;
    cout << "Enter the maximum latitude: ";
    cin >> x2;
    cout << "Enter the maximum longitude: ";
    cin >> y2;
  }

  else
  {
    x1 = 37.5021;
    y1 = -81.8810;
    x2 = 40.1924;
    y2 = -79.3980;
  }

  try
  {
    elev_data = ds.getElevationData(x1, y1, x2, y2, 0.02);
  }
  catch (const std::string &s)
  {
    std::cerr << "Exception: " << s << "\n";
  }

  // print the data dimensions
  cout << "\tWidth: " << elev_data.getCols() << endl
       << "\tHeight: " << elev_data.getRows() << endl
       << "\tCell Size: " << elev_data.getCellSize() << endl
       << "\tLower Left Corner: " << elev_data.getxll() << ", " << elev_data.getyll() << endl;

  ColorGrid grid(elev_data.getRows(), elev_data.getCols(),
                 Color("blue"));
  myGrid = grid;
  visualizeElev(); // call to the visualizing method
}

//-----------------------------------visualizeElev method---------------
/*
 * Method to find the lowest and highest elevations and colors each cell in the grid
 * depending on the range of the values
 */
void Elevation ::visualizeElev()
{
  int lowest = elev_data.getVal(0, 0);
  int highest = elev_data.getVal(0, 0);

  for (int n = 0; n < elev_data.getRows(); n++)
  {
    for (int m = 0; m < elev_data.getCols(); m++)
    {
      if (elev_data.getVal(n, m) > highest)
      {
        highest = elev_data.getVal(n, m);
      }
      if (elev_data.getVal(n, m) < lowest)
      {
        lowest = elev_data.getVal(n, m);
      }
    }
  }

  float range = highest - lowest;

  for (int i = 0; i < elev_data.getRows(); i++)
  {
    for (int j = 0; j < elev_data.getCols(); j++)
    {
      int elev = elev_data.getVal(i, j) - lowest;
      float color = static_cast<float>(elev) / range;
      myGrid.set(i, j, Color(25, static_cast<int>(color * 255), 25));
    }
  }
}
//-----------------------------getStartingRow method-------------------------------
/*
 * Method to prompt the user for the starting row
 */
void Elevation ::getStartingRow()
{
  cout << "Enter a starting position of the row between 0 and " << elev_data.getRows() - 1 << ": ";
  cin >> startingRow;
}
//------------------------------findLowestPath method-------------------------
/*
 * Method to find the lowest path and colors the path with blue color
 */
void Elevation ::findLowestPath()
{
  int row = startingRow;
  int downRow = 0, upRow = 0;

  myGrid.set(row, 0, Color(0, 0, 255));

  for (int col = 1; col < elev_data.getCols(); col++)
  {

    if (row != 0)
    {
      upRow = row - 1;
    }
    else
    {
      upRow = row;
    }
    if (row != elev_data.getRows() - 1)
    {
      downRow = row + 1;
    }
    else
    {
      downRow = row;
    }

    if (elev_data.getVal(row, col) <= elev_data.getVal(downRow, col) && elev_data.getVal(row, col) <= elev_data.getVal(upRow, col))
    {
      myGrid.set(row, col, Color(0, 0, 255));
    }
    else if (elev_data.getVal(downRow, col) < elev_data.getVal(upRow, col))
    {
      myGrid.set(downRow, col, Color(0, 0, 255));
      row = downRow;
    }
    else if (elev_data.getVal(upRow, col) < elev_data.getVal(downRow, col))
    {
      myGrid.set(upRow, col, Color(0, 0, 255));
      row = upRow;
    }

    else
    {
      if (rand() % 2)
      {
        myGrid.set(downRow, col, Color(0, 0, 255));
      }
      else
      {
        myGrid.set(upRow, col, Color(0, 0, 255));
      }
    }
  }
}
//------------------------------------------findHighestPath method--------------------------------
/*
 * Method to find the highest path and colors the path with red color
 */
void Elevation ::findHighestPath()
{
  int row = startingRow;
  int downRow = 0, upRow = 0;

  myGrid.set(row, 0, Color(255, 0, 0));

  for (int col = 1; col < elev_data.getCols(); col++)
  {

    if (row != 0)
    {
      upRow = row - 1;
    }
    else
    {
      upRow = row;
    }
    if (row != elev_data.getRows() - 1)
    {
      downRow = row + 1;
    }
    else
    {
      downRow = row;
    }

    if (elev_data.getVal(row, col) >= elev_data.getVal(downRow, col) &&
        elev_data.getVal(row, col) >= elev_data.getVal(upRow, col))
    {
      myGrid.set(row, col, Color(255, 0, 0));
    }
    else if (elev_data.getVal(downRow, col) > elev_data.getVal(upRow, col))
    {
      myGrid.set(downRow, col, Color(255, 0, 0));
      row = downRow;
    }
    else if (elev_data.getVal(upRow, col) > elev_data.getVal(downRow, col))
    {
      myGrid.set(upRow, col, Color(255, 0, 0));
      row = upRow;
    }
    else
    {
      if (rand() % 2)
      {
        myGrid.set(downRow, col, Color(255, 0, 0));
      }
      else
      {
        myGrid.set(upRow, col, Color(255, 0, 0));
      }
    }
  }
}

//-----------------------------------findShortestPath method----------------------------
/*
 * Method to find the shortest path with the given starting row and ending row
 */
void Elevation ::findShortestPath()
{
  int endingRow;
  cout << "Enter an ending position of the row between 0 and " << elev_data.getRows() - 1 << ": ";
  cin >> endingRow;
  int row = startingRow;
  for (int col = 0; col < elev_data.getCols(); col++)
  {
    myGrid.set(row, col, Color("yellow"));
    row = (float)row - ((float)(startingRow - endingRow) / elev_data.getCols());
  }
}

//---------------------------------displayResult method-----------------------------
/*
 * Methods to diplay the data to the console and visualize the grid with particular colors
 * bridges: in param of the Bridges object
 */
void elevation ::displayResult(Bridges bridges)
{

  cout << "The lowest elevation in the data set is: " << elev_data.getMinVal() << endl;
  cout << "The highest elevation in the data set is: " << elev_data.getMaxVal() << endl;
  int sum = 0;
  float mean = 0;
  for (int i = 0; i < elev_data.getRows(); i++)
  {
    for (int j = 0; j < elev_data.getCols(); j++)
    {
      sum += elev_data.getVal(i, j);
    }
  }
  mean = (float)sum / (elev_data.getCols() * elev_data.getRows());

  cout << "The mean elevation in the data set is: " << mean << endl
       << endl;

  bridges.setDataStructure(&myGrid);

  bridges.visualize();
}

//-----------------------------------main function----------------------------
int main(int argc, char **argv)
{

  // create Bridges object, set credentials
  Bridges bridges(3, "sayed2025", "620126686192");

  elevation elev;

  char code; // input code

  do
  {

    cout << "Menue ----" << endl;
    cout << "c - Enter (c)oordinates of the map" << endl;
    cout << "p - Enter starting (p)osition" << endl;
    cout << "l - Calculate path with (l)east elevation gain" << endl;
    cout << "m - Calculate path with (m)ost elevation gain" << endl;
    cout << "s - Calculate (s)hortest path" << endl;
    cout << "d - (d)isplay result" << endl;
    cout << "q - (q)uit" << endl;
    cin.get(code);
    cin.get();

    // call to getCoordinates method
    if (code == 'c')
    {
      elev.getCoordinates();
      cin.get();
    }
    // call to getStartingRow method
    else if (code == 'p')
    {
      elev.getStartingRow();
      cin.get();
    }
    // call to Lowest Path method
    else if (code == 'l')
    {
      elev.findLowestPath();
    }
    // call to Highest Path method
    else if (code == 'm')
    {
      elev.findHighestPath();
    }
    // call to Shortest Path method
    else if (code == 's')
    {
      elev.findShortestPath();
      cin.get();
    }
    // call to Display method
    else if (code == 'd')
    {
      elev.displayResult(bridges);
      cin.get();
    }
    else if (code != 'q')
    {
      cout << "Invalid input - try again." << endl;
      cout << endl;
    }

  } while (code != 'q');

  return 0;
}
