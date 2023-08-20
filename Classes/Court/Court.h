#ifndef COURT_H
#define COURT_H

#include <iostream>
using namespace std;
class Court
{
public:
    // Declaring Data Members
    string court_ID = "NA";
    string type = "NA";
    string location = "NA";

    // Declaring Methods

    // Constructor
    Court();
    Court(string , string , string);
    // Setters
    void setCourtId(string);
    void setType(string);
    void setLocation(string);

    // Getters
    string getCourtId();
    string getType();
    string getLocation();

    // Display
    void display();
};

#endif