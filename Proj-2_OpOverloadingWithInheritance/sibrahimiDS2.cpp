/*
 * Programmer: Sayed Abdul Ahad Ibrahimi
 * Date      : 9/27/22
 * Class     : COMP 218 Fall 2022
 * File      : sibrahimiDS2.cpp
 *
 * Program to show overloading operators with inheritance. The program includes:
 *
 *  - a base class Number with a data member 'number' of type: string which can store
 *    any number
 *  - the class Number has a default constructor and two methods which are 'our friend'
 *  - an overloaded operator for << to output different types (Lint, Int, Float)
 *  - an overloaded operator for >> to input any number
 *
 *  - a derived class Lint which can store a 30-digit number
 *  - the class Lint has a default constructor and four methods
 *  - an overloaded operator for + to add two Lint
 *  - an overloaded operator for = to deep copy a Lint to another Lint (instance)
 *  - an overloaded operator for ++ to increment the number by 1
 *  - an overloaded operator for = to deep copy an int to an instance of Lint
 *
 *  - a derived class Int which can store maximum value of 2147483647
 *  - the class Int has a default constructor, one method of its own,
 *    and three inherited methods
 *  - an inherited method from Lint which can add two Int
 *  - an inherited method from Lint which can deep copy an Int to another Int (instance)
 *  - an overloaded operator for += to add an int to an Int (instance)
 *    and deep copy to Int on left side of =
 *  - an inherited method from Lint which can increment the number by 1
 *
 *  - a derived class Float which can store the machine defined size
 *  - the class Float has a default constructor and two methods
 *  - an overloaded operator for = to deep copy a Float to another Float (instance)
 *  - an overloaded operator for + to add two Float
 *
 *  Description: This program is designed to demonstrate the hierarchy of classes (inheritance)
 *               with operator overloading
 *  Input      : any number
 *  Output     : number in form of types Lint, Int or Float
 */

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

const int MAX_LINT_SIZE = 30;

//-------------------------------------Number Class-----------------------------------------
class Number
{

public:
    Number() { number = ""; };                             // default constructor
    friend ostream &operator<<(ostream &, const Number &); // output number
    friend istream &operator>>(istream &, Number &);       // input number
protected:
    string number; // to store the number
};
/*
 * Method to overload << operator to output number
 * outputNum : in param of the number
 * co : in-out param output stream
 * Returns output data
 */
ostream &operator<<(ostream &co, const Number &outputNum)
{
    bool isfloat = false;
    for (int i = 0; i < outputNum.number.size(); i++)
    {
        if (outputNum.number[i] == '.')
        {
            co << "Float number: " << outputNum.number;
            isfloat = true;
        }
    }
    if (isfloat == false)
    {
        co << outputNum.number;
    }

    return co;
}
/*
 * Method to overload >> operator to input number
 * inputNum : in-out param of the number
 * ci : in-out param input stream
 * Returns input data
 */
istream &operator>>(istream &ci, Number &inputNum)
{
    ci >> inputNum.number;

    return ci;
}

//----------------------------------------Lint Class--------------------------------
class Lint : public Number
{

public:
    Lint() : Number() {}                // default constructor
    Lint operator+(const Lint &) const; // add two Lint
    Lint &operator=(const Lint &);      // deep copy the right side of = to the left side of =
    Lint &operator++(int);              // increment the number of type Lint by 1
    Lint &operator=(int);               // deep copy an int to an instance of Lint
};

/*
 * Method to overload = operator using deep copy
 * rightSide: const in-out param of the number on right side of =
 * Returns pointer to left side of = (implied)
 */
Lint &Lint ::operator=(const Lint &rightSide)
{
    number = rightSide.number;
    return *this;
}
/*
 * Method to overload + operator to add the two Lint
 * rightSide: in param of the time on right side of =
 * Returns the sum of the two Lint
 */
Lint Lint ::operator+(const Lint &rightSide) const
{

    // we should make sure the number is below the max

    assert(number.size() < 30 && rightSide.number.size() < MAX_LINT_SIZE);

    Lint sum;
    sum.number = "";

    string left = number;
    string right = rightSide.number;

    reverse(left.begin(), left.end());
    reverse(right.begin(), right.end());
    if (left.size() < right.size())
    {
        swap(left, right);
    }

    int n = left.size(), m = right.size();
    int i = 0, j = 0, carry = 0;
    for (int i = 0; i < n; ++i)
    {
        carry += (left[i] - '0') + (i < m ? (right[i] - '0') : 0);
        sum.number += '0' + (carry % 10);
        carry /= 10;
    }

    while (carry)
    {
        sum.number += '0' + (carry % 10);
        carry /= 10;
    }

    std::reverse(sum.number.begin(), sum.number.end());

    if (sum.number.empty())
    {
        sum.number = '0';
    }

    return sum;
}
/*
 * Method to overload ++ operator to increment by 1
 * none
 * Return pointer to left side of = (implied)
 */
Lint &Lint ::operator++(int)
{
    Lint temp;
    temp.number = "";

    std::reverse(number.begin(), number.end());
    int carry = 1;

    for (char &digit : number)
    {
        carry += digit - '0';
        temp.number += '0' + (carry % 10);
        carry /= 10;
    }

    while (carry)
    {
        temp.number += '0' + (carry % 10);
        carry /= 10;
    }

    std::reverse(temp.number.begin(), temp.number.end());
    number = temp.number;

    return *this;
}
/*
 * Method to overload = operator using deep copy
 * rightSide: in param of the number on right side of =
 * Returns pointer to left side of = (implied)
 */
Lint &Lint::operator=(int rightSide)
{
    number = to_string(rightSide);
    return *this;
}

//-------------------------------------Int Class------------------------------------
class Int : public Lint
{

public:
    Int() : Lint() {};       // default constructor
    using Lint::operator+;   // inherited method to add two Int
    using Lint::operator=;   // inherited method to deep copy the right side of = to the left side of =
    Int &operator+=(int);    // add Int + int and deep copy to the left side of =
    using Lint ::operator++; // inherited method to increment by 1
};

/*
 * Method to overload += operator to add an instance and int and deep copy to left side of =
 * rightSide: in param of the time on right side of =
 * Returns pointer to left side of = (implied)
 */

Int &Int ::operator+=(int rightSide)
{

    string right = to_string(rightSide);

    std::reverse(number.begin(), number.end());
    std::reverse(right.begin(), right.end());
    if (number.size() < right.size())
    {
        swap(number, right);
    }
    int n = number.size(), m = right.size();
    int carry = 0;

    for (int i = 0; i < n; ++i)
    {
        carry += (number[i] - '0') + (i < m ? (right[i] - '0') : 0);
        number[i] = '0' + (carry % 10);
        carry /= 10;
    }

    while (carry)
    {
        number += '0' + (carry % 10);
        carry /= 10;
    }

    std::reverse(number.begin(), number.end());

    if (number.empty())
    {
        number = '0';
    }

    return *this;
}

//------------------------------------Float Class----------------------------------------
class Float : public Number
{
public:
    Float() { number = ""; }              // default constructor
    Float &operator=(const Float &);      // deep copy the right side of = to the left side of =
    Float operator+(const Float &) const; // add two Float
};

/*
 * Method to overload = operator using deep copy
 * rightSide: const in-out param of the number on right side of =
 * Returns pointer to left side of = (implied)
 */
Float &Float ::operator=(const Float &rightSide)
{

    number = rightSide.number;
    return *this;
}
/*
 * Method to overload + operator to add the two Float
 * rightSide: in param of the time on right side of =
 * Returns the sum of the two Float
 */
Float Float ::operator+(const Float &rightSide) const
{
    Float sum;
    float floatLeftSide = stof(number);
    float floatRightSide = stof(rightSide.number);
    sum.number = to_string(floatLeftSide + floatRightSide);
    return sum;
}
//------------------------------------------Main--------------------------------------------

int main()
{

    Lint Lint_num1, Lint_num2;

    cout << "Enter number1: ";
    cin >> Lint_num1;

    cout << "Enter number2: ";
    cin >> Lint_num2;

    cout << "Sum of number1 and number2: " << Lint_num1 + Lint_num2 << endl;

    Lint_num1 = Lint_num2;
    cout << "After assignment, Lint_num1: " << Lint_num1 << endl;

    cout << "After incrementing Lint_num1: " << Lint_num1++ << endl;
    Lint_num1 = 99;
    cout << "After assigning 99 to Lint_num1: " << Lint_num1 << endl;

    //------------------------------Int testing--------------------------------------
    /*
        Int Int_num1, Int_num2;

        cout << "Enter number1: ";
        cin >> Int_num1;

        cout << "Enter number2: ";
        cin >> Int_num2;

        cout << Int_num1 + Int_num2 << endl;

        Int_num1 = Int_num2;
        cout << Int_num1;

        cout<< Int_num1++ << endl;

        Int_num1 += 99;
        cout << Int_num1 << endl;
    */
    //-------------------------------Float testing------------------------------------

    /*
    Float Float_num1, Float_num2;

    cout << "Enter number1: ";
    cin >> Float_num1;

    cout << "Enter number2: ";
    cin >> Float_num2;

    cout << Float_num1 + Float_num2 << endl;

    Float_num1 = Float_num2;
    cout << Float_num1;
    */

    return 0;
};