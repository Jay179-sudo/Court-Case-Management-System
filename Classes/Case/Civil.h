
#ifndef CIVIL_H
#define CIVIL_H
#include <string>
#include "Cases.h"


class Civil: public Cases
{
    private:
        string Type;

    public:
        // getters and setters are inherited
        Civil();
        Civil(string input_case_id , string des, Person *Plain, Person *Def, Person *Wit, Judge *Jg, Lawyer *plw, Lawyer *dlw, Court *c, State stat, string ty):Cases(input_case_id , des, Plain, Def, Wit, Jg, plw, dlw, c, stat);
        void setType(string userInput);
        string getType();

        // case report
        void CaseReport();

        
}; 


#endif

