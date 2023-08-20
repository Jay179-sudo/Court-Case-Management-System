
#ifndef CASES_H
#define CASES_H


enum State { PENDING, ASSIGNED, DECIDED };

// imports
#include <vector>
#include "../Court/Court.h"
#include "../Person/Person.h"
#include "../Person/Judge.h"
#include "../Person/Lawyer.h"
#include <string>
class Cases
{
    // DATA MEMBERS NOT PUBLIC

    protected:
        string case_id;
        string Description = "N/A";
        Person* Plaintiff = NULL;
        Person* Defendant = NULL;
        vector< Person* > Witness;
        Judge* Jdg = NULL;
        Lawyer* Plaintiff_Lawyer = NULL;
        Lawyer* Defendant_Lawyer = NULL;
        Court* Crt = NULL;
        string Filing_Date;
        vector<string> Hearing_Dates;
        State Status = PENDING;
    public:
        Cases();
        Cases(string input_case_id , string des, Person *Plain, Person *Def, Person *Wit, Judge *Jg, Lawyer *plw, Lawyer *dlw, Court *c, State stat);
        // generate a visual case report
        virtual void CaseReport() = 0;

        // setters
        void setCaseId(string input_case_id);
        void setDescription(string des = "");
        void setPlaintiff(Person *Plain = NULL);
        void setDefendant(Person *Def = NULL);
        void addWitness(Person *Wit = NULL);
        void setJudge(Judge *Jg = NULL);
        void setPlaintiffLawyer(Lawyer *plw = NULL);
        void setDefendantLawyer(Lawyer *dlw = NULL);
        void setCourt(Court *ct = NULL);
        void setStatus(State stat = PENDING);
        void setFilingDate(string st);
        void addHearingDate(string st);
        virtual void setType(string userInput = "") = 0;

        // getters  
        string getCaseId();
        string getDescription();
        Person* getPlaintiff();
        Person* getDefendant();
        vector<Person *>& getWitnessList();
        Judge* getJudge();
        Lawyer* get_Plaintiff_Lawyer();
        Lawyer* get_Defendant_Lawyer();
        Court* getCourt();
        State getState();
        string getFilingDate();
        vector<string> getHearingDates();
        virtual string getType() = 0;

        
};



#endif
