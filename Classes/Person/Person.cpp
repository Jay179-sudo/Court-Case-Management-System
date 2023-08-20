
# include <iostream>
# include "Person.h"

using namespace std;

// Constructor to initialize values
Person::Person(){}
Person::Person(string input_aadhar , string input_name , int intput_age , string input_address , string input_contact)
{
    aadhar = input_aadhar;
    name = input_name;
    age = intput_age;
    address = input_address;
    contact = input_contact;
}

// Setter for aadhar
void Person::setAadhar(string input_aadhar)
{
    aadhar = input_aadhar;
}

// Setter for name
void Person::setName(string input_name)
{
    name = input_name;
}

// Setter for age
void Person::setAge(int input_age)
{
    age = input_age;
}

// Setter for address
void Person::setAddress(string input_address)
{
    address = input_address;
}

// Setter for contact
void Person::setContact(string input_contact)
{
    contact = input_contact;
}

// getter for aadhar
string Person::getAadhar()
{
    return aadhar;
}

// getter for name
string Person::getName()
{
    return name;
}

// getter for age
int Person::getAge()
{
    return age;
}

// getter for address
string Person::getAddress()
{
    return address;
}

// getter for contact
string Person::getContact()
{
    return contact;
}

// Function to display details about the object
void Person::display()
{
    cout << "*****************************************************************************************************" << endl;
    cout << "Aadhar Number : " << aadhar << endl;
    cout << "Name : " << name << endl;
    cout << "Age : " << age << endl;
    cout << "Address : " << address << endl;
    cout << "Contact : " << contact << endl;
    cout << "*****************************************************************************************************" << endl;
}

