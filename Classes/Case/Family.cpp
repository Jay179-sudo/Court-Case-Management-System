#include "Family.h"

#include <iostream>
using namespace std;

Family::Family(){};
void Family::setType(string userInput)
{
    this->Type = userInput;
};
string Family::getType()
{
    return this->Type;
};

void Family::CaseReport()
{
    cout << "*****************************************************************************************************" << endl;
    cout << "\t\tCASE REPORT" << endl << endl;
    cout << "Type: Family" << endl;

   

    cout << "The Judge is: " << this->getJudge()->getName()  << endl << endl;
    cout << "This Case is being held at " << this->getCourt()->getLocation() << " " << this->getCourt()->getType() << endl;    
    cout << "This Case's status is ";
    if(this->getState() == 0)
    {
        cout << "Pending" << endl;
    }
    else if(this->getState() == 1)
    {
        cout << "Assigned " << endl;
    }
    else
    {
        cout << "Decided" << endl;
    }
    cout << "This Case was filed in " << this->getFilingDate() << endl;
    cout << "Plaintiff: " <<  this->getPlaintiff()->getName() << endl;
    cout << "The Plaintiff's Lawyer is " << this->get_Plaintiff_Lawyer()->getName() << endl << endl;
    cout << "Defendant: " << this->getDefendant()->getName() << endl;
    cout << "The Defendant's Lawyer is " << this->get_Defendant_Lawyer()->getName() << endl << endl;
    cout << "The Witnesses are : " << endl;
    vector<Person*> temp = getWitnessList(); 
    for (auto i : temp)
        cout << "\t" << i->getName() << endl;
    cout << endl;
    
    cout << "The Hearing dates were in "  << endl;
    for(auto str: this->getHearingDates())
    {
        cout << "\t" << str << endl;
    }
    cout << "Description: " << this->getDescription() << endl << endl;
    cout << "*****************************************************************************************************" << endl << endl;
}