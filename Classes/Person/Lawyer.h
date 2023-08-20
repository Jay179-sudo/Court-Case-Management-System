
# ifndef LAWYER_H
# define LAWYER_H

# include <iostream>
# include "Person.h"
using namespace std;

class Lawyer : public Person
{
    // Declaring data member  as private
    int lawyer_id = -1;

    // Declaring Methods as public
    public:
        // Constructor
        Lawyer();
        Lawyer(string input_aadhar , string input_name , int intput_age , string input_address , string input_contact , int input_lawyer_id);

        // Setters
        void setLawyerId(int input_lawyer_id);

        // Getters
        int getLawyerId();

        // Display All Details
        void display();
};

#endif