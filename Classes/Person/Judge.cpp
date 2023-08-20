

# include <iostream>
# include "Judge.h"
using namespace std;

// Constructor to initialize values
Judge::Judge(){}
Judge::Judge(string input_aadhar , string input_name , int intput_age , string input_address , string input_contact , int input_judge_id)
{
    Person(input_aadhar , input_name , intput_age , input_address , input_contact);
    judge_id = input_judge_id;
}

// Setter for Judge Id
void Judge::setJudgeId(int input_judge_id)
{
    judge_id = input_judge_id;
}

// Getter for Judge Id
int Judge::getJudgeId()
{
    return judge_id;
}

// Function to display details about the object
void Judge::display()
{
    cout << "*****************************************************************************************************" << endl;
    cout << "Judge ID : " << judge_id << endl;
    cout << "Aadhar Number : " << aadhar << endl;
    cout << "Name : " << name << endl;
    cout << "Age : " << age << endl;
    cout << "Address : " << address << endl;
    cout << "Contact : " << contact << endl;
    cout << "*****************************************************************************************************" << endl;
}