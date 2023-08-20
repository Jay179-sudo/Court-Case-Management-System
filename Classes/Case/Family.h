
#ifndef FAMILY_H
#define FAMILY_H

#include <string>
#include "Cases.h"
class Family: public Cases
{
    private:
        string Type;

    public:
        // getters and setters are inherited
        Family();
        Family(string input_case_id , string des, Person *Plain, Person *Def, Person *Wit, Judge *Jg, Lawyer *plw, Lawyer *dlw, Court *c, State stat,string userInput): Cases(input_case_id , des, Plain, Def, Wit, Jg, plw, dlw, c, stat)
        {
            this->Type = userInput;
        };
        void setType(string userInput = "");
        string getType();

        void CaseReport();
        
};  

#endif