

# include <bits/stdc++.h>
# include "Classes/Case/Cases.h"
# include "Classes/Case/Civil.h"
# include "Classes/Case/Criminal.h"
# include "Classes/Case/Family.h"

# include "Classes/Case/Cases.cpp"
# include "Classes/Case/Civil.cpp"
# include "Classes/Case/Criminal.cpp"
# include "Classes/Case/Family.cpp"

# include "Classes/Person/Person.h"
# include "Classes/Person/Lawyer.h"
# include "Classes/Person/Judge.h"

# include "Classes/Person/Person.cpp"
# include "Classes/Person/Lawyer.cpp"
# include "Classes/Person/Judge.cpp"

# include "Classes/Court/Court.h"
# include "Classes/Court/Court.cpp"

# include "Utils/data.h"
# include "Utils/data.cpp"

# include "Menu/menu.cpp"
using namespace std;

int main()
{
    readPerson();
    readJudge();
    readLawyer();
    readCourt();
    readCivil();
    readCriminal();
    readFamily();
    readAdmin();

    
    displayMenu();
}

