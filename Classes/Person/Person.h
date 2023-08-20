
# ifndef PERSON_H
# define PERSON_H

# include <iostream>
using namespace std;

class Person
{
    // Declaring data member  as protected
    protected:
        string aadhar;
        string name = "NA";
        int age = -1;
        string address = "NA";
        string contact = "NA";

    // Declaring Methods as public
    public:
        // Constructor
        Person();
        Person(string input_aadhar , string input_name , int intput_age , string input_address , string input_contact);

        // Setters
        void setAadhar(string input_aadhar);
        void setName(string input_name);
        void setAge(int input_age);
        void setAddress(string input_address);
        void setContact(string input_contact);

        // Getters
        string getAadhar();
        string getName();
        int getAge();
        string getAddress();
        string getContact();

        // Display
        void display();
};

# endif


