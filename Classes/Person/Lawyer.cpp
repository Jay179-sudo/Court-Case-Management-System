


# include <iostream>
# include "Lawyer.h"
using namespace std;

// Constructor to initialize values
Lawyer::Lawyer(){}
Lawyer::Lawyer(string input_aadhar , string input_name , int intput_age , string input_address , string input_contact , int input_lawyer_id)
{
    Person(input_aadhar , input_name , intput_age , input_address , input_contact);
    lawyer_id = input_lawyer_id;
}

// Setter for Lawyer ID
void Lawyer::setLawyerId(int input_lawyer_id)
{
    lawyer_id = input_lawyer_id;
}

// Getter for Lawyer ID
int Lawyer::getLawyerId()
{
    return lawyer_id;
}

// Function to display details about the object
void Lawyer::display()
{
    cout << "*****************************************************************************************************" << endl;
    cout << "Lawyer ID : " << lawyer_id << endl;
    cout << "Aadhar Number : " << aadhar << endl;
    cout << "Name : " << name << endl;
    cout << "Age : " << age << endl;
    cout << "Address : " << address << endl;
    cout << "Contact : " << contact << endl;
    cout << "*****************************************************************************************************" << endl;
}

