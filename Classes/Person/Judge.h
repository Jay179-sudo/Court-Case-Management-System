
#ifndef JUDGE_H
#define JUDGE_H

# include <iostream>
# include "Person.h"
using namespace std;

class Judge : public Person
{
    // Declaring data member  as private
    int judge_id = -1;

    // Declaring Methods as public
    public:
        // Constructor
        Judge();
        Judge(string input_aadhar , string input_name , int intput_age , string input_address , string input_contact , int input_judge_id);

        // Setters
        void setJudgeId(int input_judge_id);

        // Getters
        int getJudgeId();

        // Display All Details
        void display();
};

#endif
