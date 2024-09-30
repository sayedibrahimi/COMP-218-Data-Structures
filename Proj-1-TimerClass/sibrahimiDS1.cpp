/*
 * Programmer: Sayed Abdul Ahad Ibrahimi
 * Date      : 9/11/22
 * Class     : COMP 218 Fall 2022
 * File      : sibrahimiDS1.cpp
 *
 * Program to show overloading operators. The program includes:
 *  - a class timer with hour, minute and second elements
 *  - the class also includes a default constructor
 *  - There are 7 methods in our class timer under public , 2 of which are 'our friend'
 *  - an overloaded operator for + to add two times
 *  - an overloaded operator for + to add an integer to a time (seconds)
 *  - an overloaded operator for = to deep copy a time to another time (instance)
 *  - an overloaded operator for += to add two times and deep copy to the time on left side of =
 *  - an overloaded operator for += to add an integer to a time (seconds) and deep copy it
 *  - an overloaded operator for << to output a time in a nice format
 *  - an overloaded operator for >> to input a time including colons
 *
 *  Description: To ask for input (time), add any two times including an integer, and then
 *               output the time in a nice format.
 *  Input      : Time in form of hh:mm:ss
 *  Output     : Time in form of hh:mm:ss
 */


#include <iostream>
using namespace std;

class timer {
    int hour;       // to store the hour
    int minute;     // to store the minute
    int second;     // to store the second
public:
    timer() : hour(0), minute(0), second(0) {};  // Initializing with default values

    timer operator+ (timer);             // add time1 + time2
    timer operator+ (int);               // add time + int
    timer& operator= (const timer&);     // deep copy the right side of = to the left side of =
    timer& operator+= (int);             // add a time + int and deep copy to the left side of =
    timer& operator+= (timer);           // add time1 + time2 and deep copy to the left side of =
    friend ostream& operator<< (ostream&, timer);   // output time
    friend istream& operator>> (istream&, timer&);  // input time
    
};

/*
 * Method to overload << operator to output time
 * t  : in param of the time
 * co : in-out param output stream
 * Returns output data
 */
ostream& operator<< (ostream& co, const timer t) {

    if (t.minute < 10 && t.second < 10) {
        co << t.hour << ":" "0" << t.minute << ":" "0" << t.second << endl;
    }
    else if (t.minute > 10 && t.second < 10) {
        co << t.hour << ":" << t.minute << ":" "0" << t.second << endl;
    }
    else if (t.minute < 10 && t.second > 10) {
        co << t.hour << ":" "0"<< t.minute << ":" << t.second << endl;
    }
    else if (t.minute >= 10 && t.second >= 10) {
        co << t.hour << ":" << t.minute << ":" << t.second << endl;
    }

    return co;
}

/*
 * Method to overload >> operator to input time
 * t  : in-out param of the time
 * co : in-out param input stream
 * Returns input data
 */
istream& operator>> (istream& ci, timer& t) {

        ci >> t.hour;
        ci.get();
        ci >> t.minute;
        ci.get();
        ci >> t.second;

    if (t.minute < 0 || t.minute >= 60) {
        cerr << "Error: Invalid minute value. Must be between 0 and 59." << endl;
    }

    if (t.second < 0 || t.second >= 60) {
        cerr << "Error: Invalid second value. Must be between 0 and 59." << endl;
    }

    return ci;
}

/*
 * Method to overload + operator to add the two times
 * right: in param of the time on right side of =
 * Returns the sum of the two times
 */
timer timer :: operator+ (const timer right) {

    timer sum;

    sum.second = second + right.second;
    sum.minute = minute + right.minute;
    sum.hour = hour + right.hour;

    if (sum.second > 59) {
        sum.minute = sum.minute + (sum.second / 60);
        sum.second = sum.second % 60;
    }

    if (sum.minute > 59) {
        sum.hour = sum.hour + (sum.minute / 60);
        sum.minute = sum.minute % 60;
    }

    return sum;

}

/*
 * Method to overload = operator using deep copy
 * right: const in-out param of the time on right side of =
 * Returns pointer to left side of = (implied)
 */
timer& timer :: operator= (const timer &right) {

    hour = right.hour;
    minute = right.minute;
    second = right.second;

    return *this;

}

/*
 * Method to overload + operator to add an instance and int
 * right: in param of the int on right side of =
 * Returns the sum of the instance + int
 */
timer timer :: operator+ (const int right) {

    timer sum;

    sum.second = second + right;
    sum.minute = minute;
    sum.hour = hour;

    if (sum.second > 59) {
        sum.minute = sum.minute + (sum.second / 60);
        sum.second = sum.second % 60;
    }

    if (sum.minute > 59) {
        sum.hour = sum.hour + (sum.minute / 60);
        sum.minute = sum.minute % 60;
    }

    return sum;

}

/*
 * Method to overload += operator to add an instance and int and deep copy to left side of =
 * right: in param of the time on right side of =
 * Returns pointer to left side of = (implied)
 */
timer& timer :: operator+= (timer right) {

    second = second + right.second;
    minute = minute + right.minute;
    hour = hour + right.hour;

    if (second > 59) {
        minute = minute + (second / 60);
        second = second % 60;
    }

    if (minute > 59) {
        hour = hour + (minute / 60);
        minute = minute % 60;
    }

    return *this;
}

/*
 * Method to overload += operator to add an instance and int and deep copy to left side of =
 * right: in param of the int on right side of =
 * Returns pointer to left side of = (implied)
 */
timer& timer :: operator+= (int right) {

    second = second + right;
    minute = minute;
    hour = hour;

    if (second > 59) {
        minute = minute + (second / 60);
        second = second % 60;
    }

    if (minute > 59) {
        hour = hour + (minute / 60);
        minute = minute % 60;
    }

    return *this;

}

int main() {
    timer timeA, timeB, timeC;

    cout << "Enter a time value: ";
    cin >> timeA;                                   // to test overloaded input >> operator
    timeB = timeA;
    cout << "timeA is: " << timeA;                  // to test overloaded output << operator
    cout << "timeB is: " << timeB << endl;          // to test = overloaded operator

    // to test overloaded = operator (Deep copy?) and overloaded + operator for a time + integer
    cout << "timeA is: " << timeA;
    cout << "timeA + 1000 is: " << timeA + 1000;
    cout << "timeB is: " << timeB << endl;

    // to test + operator for two instances
    cout << "timeA is: " << timeA;
    cout << "timeB is: " << timeB;
    cout << "timeA + timeB is: " << timeA + timeB << endl;

    // to test a combination of + and = overloaded operator of two instances
    cout << "timeA is: " << timeA;
    cout << "timeB is: " << timeB;
    timeC = timeA + timeB;
    cout << "timeC = timeA + timeB is: " << timeC << endl;

    // to test += overloaded operator of adding two instances and copying to left side of =
    cout << "timeA is: " << timeA;
    cout << "timeB is: " << timeB;
    timeB += timeA;
    cout << "timeB += timeA is: " << timeB << endl;

    // to test += overloaded operator of adding instance + integer and copying to left side of =
    cout << "timeB is: " << timeB;
    timeB += 1000;
    cout << "timeB += 1000 is: " << timeB << endl;

    return 0;
};
