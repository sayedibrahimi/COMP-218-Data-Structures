# Timer Class with Operator Overloading

This project is an implementation of a `timer` class in C++ that supports various operator overloading functions. The class allows for manipulation of time values (hours, minutes, and seconds) and can perform arithmetic operations on times (e.g., adding two times together or adding seconds to a time).

## Features

- Overloaded `+` operator to add two time instances or add seconds to a time.
- Overloaded `+=` operator for in-place addition of time or seconds.
- Overloaded `=` operator for deep copying of time objects.
- Overloaded `<<` and `>>` operators for input and output in the format `hh:mm:ss`.
- Proper handling of time values, ensuring that minutes and seconds wrap correctly (e.g., 60 seconds equals 1 minute).

## Code Example

```cpp
#include <iostream>
using namespace std;

int main() {
    timer timeA, timeB, timeC;

    // Input timeA
    cout << "Enter a time value (hh:mm:ss): ";
    cin >> timeA;

    // Copy timeA to timeB using overloaded assignment operator
    timeB = timeA;
    cout << "timeA is: " << timeA << endl;
    cout << "timeB is: " << timeB << endl;

    // Add 1000 seconds to timeA using overloaded + operator
    cout << "timeA + 1000 is: " << timeA + 1000 << endl;

    // Add timeA and timeB
    cout << "timeA + timeB is: " << timeA + timeB << endl;

    // Combine two time objects
    timeC = timeA + timeB;
    cout << "timeC = timeA + timeB is: " << timeC << endl;

    // Use += operator to add timeA to timeB
    timeB += timeA;
    cout << "timeB += timeA is: " << timeB << endl;

    // Use += operator to add 1000 seconds to timeB
    timeB += 1000;
    cout << "timeB += 1000 is: " << timeB << endl;

    return 0;
}
```

## Input/Output Example
Input:
```
Enter a time value (hh:mm:ss): 12:3:55
```

Output:
```
timeA is: 12:03:55
timeB is: 12:03:55

timeA is: 12:03:55
timeA + 1000 is: 12:20:35
timeB is: 12:03:55

timeA is: 12:03:55
timeB is: 12:03:55
timeA + timeB is: 24:07:50

timeA is: 12:03:55
timeB is: 12:03:55
timeC = timeA + timeB is: 24:07:50

timeA is: 12:03:55
timeB is: 12:03:55
timeB += timeA is: 24:07:50

timeB is: 24:07:50
timeB += 1000 is: 24:24:30
```

## How to Run

1. Clone the repository or download the project files.
2. Compile the program using a C++ compiler. For example, with g++:
```
g++ -o timer_program sibrahimiDS1.cpp
./timer_program
```

3. Follow the on-screen instructions to enter time values and observe the output.

## Key Concepts
1. Operator Overloading: This project demonstrates how to overload operators (+, +=, =, <<, and >>) in C++ to provide intuitive functionality for user-defined types.
2. Time Arithmetic: The project deals with adding time values in hours, minutes, and seconds, and ensures correct overflow behavior (e.g., 60 seconds equals 1 minute).
