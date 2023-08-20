

#ifndef CRIMINAL_H
#define CRIMINAL_H

#include <string>
#include "Cases.h"

class Criminal: public Cases
{
    private:
        string Type;

    public:
        // getters and setters are inherited
        Criminal();
        Criminal(string input_case_id , string des, Person *Plain, Person *Def, Person *Wit, Judge *Jg, Lawyer *plw, Lawyer *dlw, Court *c, State stat,string Type):Cases(input_case_id , des, Plain, Def, Wit, Jg, plw, dlw, c, stat)
        {
            this->Type = Type;
        };
        void setType(string userInput);
        string getType();

        void CaseReport();
};  


#endif