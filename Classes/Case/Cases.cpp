#include "Cases.h"
#include <iostream>
using namespace std;

Cases::Cases(){};
// setters
Cases::Cases(string input_case_id, string des, Person *Plain, Person *Def, Person *Wit, Judge *Jg, Lawyer *plw, Lawyer *dlw, Court *c, State stat)
{
    case_id = input_case_id;
    this->Description = des;
    this->Plaintiff = Plain;
    this->Defendant = Def;
    this->Witness.push_back(Wit);
    this->Jdg = Jg;
    this->Crt = c;
    this->Status = stat;
};
void Cases::setCaseId(string input_case_id)
{
    case_id = input_case_id;
}
void Cases::setDescription(string des)
{
    this->Description = des;
};
void Cases::setPlaintiff(Person *Plain)
{
    this->Plaintiff = Plain;
};
void Cases::setDefendant(Person *Def)
{
    this->Defendant = Def;
};
void Cases::addWitness(Person *Wit)
{
    this->Witness.push_back(Wit);
};
void Cases::setJudge(Judge *Jg)
{
    this->Jdg = Jg;
};

void Cases::setPlaintiffLawyer(Lawyer *plw)
{
    this->Plaintiff_Lawyer = plw;
};
void Cases::setDefendantLawyer(Lawyer *dlw)
{
    this->Defendant_Lawyer = dlw;
};
void Cases::setCourt(Court *ct)
{
    this->Crt = ct;
};
void Cases::setStatus(State stat)
{
    this->Status = stat;
};
// getters
string Cases::getCaseId()
{
    return case_id;
}
string Cases::getDescription()
{
    return this->Description;
};
Person *Cases::getPlaintiff()
{
    return this->Plaintiff;
};
Person *Cases::getDefendant()
{
    return this->Defendant;
};
vector<Person *> &Cases::getWitnessList()
{
    return this->Witness;
};
Judge *Cases::getJudge()
{
    return this->Jdg;
};
Lawyer *Cases::get_Plaintiff_Lawyer()
{
    return this->Plaintiff_Lawyer;
};
Lawyer *Cases::get_Defendant_Lawyer()
{
    return this->Defendant_Lawyer;
};
Court *Cases::getCourt()
{
    return this->Crt;
};
State Cases::getState()
{
    return this->Status;
};
void Cases::setFilingDate(string st = "")
{
    this->Filing_Date = st;
};
void Cases::addHearingDate(string st = "")
{
    this->Hearing_Dates.push_back(st);
};

string Cases::getFilingDate()
{
    return this->Filing_Date;
};
vector<string> Cases::getHearingDates()
{
    return this->Hearing_Dates;
};