#include <iostream>
#include "Court.h"
using namespace std;

// Default Constructor to initialize values
Court::Court(){};

// Parameterised Constructor
Court::Court(string input_court_id , string input_type, string input_location)
{
    court_ID = input_court_id;
    type = input_type;
    location = input_location;
}

// Setter for Court Id
void Court::setCourtId(string input_court_id)
{
    court_ID = input_court_id;
}

// Setter for Type
void Court::setType(string input_type)
{
    type = input_type;
}

// setter for Location
void Court::setLocation(string input_location)
{
    location = input_location;
}

// getter for Court Id
string Court::getCourtId()
{
    return court_ID;
}

// getter for Type
string Court::getType()
{
    return type;
}

// getter for Location
string Court::getLocation()
{
    return location;
}

// Display
void Court::display()
{
    cout << "*****************************************************************************************************" << endl;
    cout << "Court ID : " << court_ID << endl;
    cout << "Court Type : " << type << endl;
    cout << "Court Location : " << location << endl;
    cout << "*****************************************************************************************************" << endl;
}
