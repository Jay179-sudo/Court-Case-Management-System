
#include "data.h"

void readAdmin()
{
    fstream file;
    file.open("Data/admin.txt", ios::in);
    while (!file.eof())
    {
        vector<string> v;

        string s;
        getline(file, s, '|');
        v.push_back(s);

        getline(file, s);
        v.push_back(s);

        admin[v[0]] = v[1];
    }

    file.close();
}

bool addAdmin(string id, string password)
{
    fstream file;
    file.open("Data/admin.txt", ios::app);
    file << endl;
    file << id;
    file << "|";
    file << password;
    cout << endl;

    file.close();
    admin[id] = password;
    cout << endl;

    return true;
};

void deleteAdmin(string id)
{
    
    fstream file;
    file.open("Data/admin.txt", ios::out);

    if (admin.begin()->first == id)
    {
        // delete the first wala
        file << (++admin.begin())->first;
        file << "|";
        file << (++admin.begin())->second;
        for (auto itr = ++(++admin.begin()); itr != admin.end(); itr++)
        {
            file << endl;
            file << itr->first;
            file << "|";
            file << itr->second;
        }
    }
    else
    {
        file << admin.begin()->first;
        file << "|";
        file << admin.begin()->second;
        for (auto itr = ++admin.begin(); itr != admin.end(); itr++)
        {
            if (itr->first != id)
            {
                file << endl;
                file << itr->first;
                file << "|";
                file << itr->second;
            }
        }
    }
    // maybe first data manually garnu parcha then aaru ma enter hanne tyspachi matra data read garne
    admin.erase(id);

    file.close();
};

void readPerson()
{
    fstream file;
    file.open("Data/person.txt", ios::in);
    while (!file.eof())
    {
        Person p;
        vector<string> v;
        for (int i = 1; i <= 4; i++)
        {
            string s;
            getline(file, s, '|');
            v.push_back(s);
        }
        string s;
        getline(file, s);
        v.push_back(s);

        p.setAadhar(v[0]);
        p.setName(v[1]);
        p.setAge(toInt(v[2]));
        p.setAddress(v[3]);
        p.setContact(v[4]);

        per[p.getAadhar()] = p;
    }
    file.close();
}

void readLawyer()
{
    fstream file;
    file.open("Data/lawyer.txt", ios::in);

    while (!file.eof())
    {
        Lawyer p;
        vector<string> v;
        for (int i = 1; i <= 5; i++)
        {
            string s;
            getline(file, s, '|');
            v.push_back(s);
        }
        string s;
        getline(file, s);
        v.push_back(s);

        p.setAadhar(v[0]);
        p.setName(v[1]);
        p.setAge(toInt(v[2]));
        p.setAddress(v[3]);
        p.setContact(v[4]);
        p.setLawyerId(toInt(v[5]));

        law[p.getAadhar()] = p;
    }
    file.close();
}

void readJudge()
{
    fstream file;
    file.open("Data/judge.txt", ios::in);

    while (!file.eof())
    {
        Judge p;
        vector<string> v;
        for (int i = 1; i <= 5; i++)
        {
            string s;
            getline(file, s, '|');
            v.push_back(s);
        }
        string s;
        getline(file, s);
        v.push_back(s);

        p.setAadhar(v[0]);
        p.setName(v[1]);
        p.setAge(toInt(v[2]));
        p.setAddress(v[3]);
        p.setContact(v[4]);
        p.setJudgeId(toInt(v[5]));

        jud[p.getAadhar()] = p;
    }
    file.close();
}

void readCourt()
{
    fstream file;
    file.open("Data/court.txt", ios::in);

    while (!file.eof())
    {
        Court c;
        vector<string> v;
        for (int i = 1; i <= 2; i++)
        {
            string s;
            getline(file, s, '|');
            v.push_back(s);
        }
        string s;
        getline(file, s);
        v.push_back(s);

        c.setType(v[0]);
        c.setLocation(v[1]);
        c.setCourtId(v[2]);

        crt[c.getCourtId()] = c;
    }
    file.close();
}

void readCivil()
{
    fstream file;
    file.open("Data/civil.txt", ios::in);

    while (!file.eof())
    {
        Civil c;
        vector<string> v;
        for (int i = 1; i <= 11; i++)
        {
            string s;
            getline(file, s, '|');
            v.push_back(s);
        }
        string s;
        getline(file, s);
        v.push_back(s);

        c.setCaseId(v[0]);
        c.setDescription(v[1]);
        c.setPlaintiff(&per[v[2]]);
        c.setDefendant(&per[v[3]]);
        c.setJudge(&jud[v[5]]);
        c.setPlaintiffLawyer(&law[v[6]]);
        c.setDefendantLawyer(&law[v[7]]);
        c.setCourt(&crt[v[8]]);
        if (v[9] == "PENDING")
            c.setStatus(PENDING);
        else if (v[9] == "ASSIGNED")
            c.setStatus(ASSIGNED);
        else
            c.setStatus(DECIDED);
        c.setFilingDate(v[10]);

        if (v[4] != "-1")
        {
            string r = "";
            for (auto i : v[4])
            {
                if (i == ',')
                {
                    if (per[r].getName() != "NA")
                        c.addWitness(&per[r]);
                    else if (law[r].getName() != "NA")
                        c.addWitness(&law[r]);
                    else if (jud[r].getName() != "NA")
                        c.addWitness(&jud[r]);
                    r = "";
                }
                else
                    r.push_back(i);
            }
            if (per[r].getName() != "NA")
                c.addWitness(&per[r]);
            else if (law[r].getName() != "NA")
                c.addWitness(&law[r]);
            else if (jud[r].getName() != "NA")
                c.addWitness(&jud[r]);
        }

        if (v[11] != "-1")
        {
            string r = "";
            for (auto i : v[11])
            {
                if (i == ',')
                {
                    c.addHearingDate(r);
                    r = "";
                }
                else
                    r.push_back(i);
            }
            c.addHearingDate(r);
        }

        civil_cases[v[0]] = c;
    }
    file.close();
}

void readCriminal()
{
    fstream file;
    file.open("Data/criminal.txt", ios::in);

    while (!file.eof())
    {
        Criminal c;
        vector<string> v;
        for (int i = 1; i <= 11; i++)
        {
            string s;
            getline(file, s, '|');
            v.push_back(s);
        }
        string s;
        getline(file, s);
        v.push_back(s);

        c.setCaseId(v[0]);
        c.setDescription(v[1]);
        c.setPlaintiff(&per[v[2]]);
        c.setDefendant(&per[v[3]]);
        c.setJudge(&jud[v[5]]);
        c.setPlaintiffLawyer(&law[v[6]]);
        c.setDefendantLawyer(&law[v[7]]);
        c.setCourt(&crt[v[8]]);
        if (v[9] == "PENDING")
            c.setStatus(PENDING);
        else if (v[9] == "ASSIGNED")
            c.setStatus(ASSIGNED);
        else
            c.setStatus(DECIDED);
        c.setFilingDate(v[10]);

        if (v[4] != "-1")
        {
            string r = "";
            for (auto i : v[4])
            {
                if (i == ',')
                {
                    if (per[r].getName() != "NA")
                        c.addWitness(&per[r]);
                    else if (law[r].getName() != "NA")
                        c.addWitness(&law[r]);
                    else if (jud[r].getName() != "NA")
                        c.addWitness(&jud[r]);
                    r = "";
                }
                else
                    r.push_back(i);
            }
            if (per[r].getName() != "NA")
                c.addWitness(&per[r]);
            else if (law[r].getName() != "NA")
                c.addWitness(&law[r]);
            else if (jud[r].getName() != "NA")
                c.addWitness(&jud[r]);
        }

        if (v[11] != "-1")
        {
            string r = "";
            for (auto i : v[11])
            {
                if (i == ',')
                {
                    c.addHearingDate(r);
                    r = "";
                }
                else
                    r.push_back(i);
            }
            c.addHearingDate(r);
        }

        criminal_cases[v[0]] = c;
        // civil_cases.push_back(c);
    }
    file.close();
}

void readFamily()
{
    fstream file;
    file.open("Data/family.txt", ios::in);

    while (!file.eof())
    {
        Family c;
        vector<string> v;
        for (int i = 1; i <= 11; i++)
        {
            string s;
            getline(file, s, '|');
            v.push_back(s);
        }
        string s;
        getline(file, s);
        v.push_back(s);

        c.setCaseId(v[0]);
        c.setDescription(v[1]);
        c.setPlaintiff(&per[v[2]]);
        c.setDefendant(&per[v[3]]);
        c.setJudge(&jud[v[5]]);
        c.setPlaintiffLawyer(&law[v[6]]);
        c.setDefendantLawyer(&law[v[7]]);
        c.setCourt(&crt[v[8]]);
        if (v[9] == "PENDING")
            c.setStatus(PENDING);
        else if (v[9] == "ASSIGNED")
            c.setStatus(ASSIGNED);
        else
            c.setStatus(DECIDED);
        c.setFilingDate(v[10]);

        if (v[4] != "-1")
        {
            string r = "";
            for (auto i : v[4])
            {
                if (i == ',')
                {
                    if (per[r].getName() != "NA")
                        c.addWitness(&per[r]);
                    else if (law[r].getName() != "NA")
                        c.addWitness(&law[r]);
                    else if (jud[r].getName() != "NA")
                        c.addWitness(&jud[r]);
                    r = "";
                }
                else
                    r.push_back(i);
            }
            if (per[r].getName() != "NA")
                c.addWitness(&per[r]);
            else if (law[r].getName() != "NA")
                c.addWitness(&law[r]);
            else if (jud[r].getName() != "NA")
                c.addWitness(&jud[r]);
        }

        if (v[11] != "-1")
        {
            string r = "";
            for (auto i : v[11])
            {
                if (i == ',')
                {
                    c.addHearingDate(r);
                    r = "";
                }
                else
                    r.push_back(i);
            }
            c.addHearingDate(r);
        }

        family_cases[v[0]] = c;
        // civil_cases.push_back(c);
    }
    file.close();
}

void writePerson(Person p)
{
    fstream file;
    file.open("Data/person.txt", ios::app);
    file << endl;
    file << p.getAadhar();
    file << "|";
    file << p.getName();
    file << "|";
    file << p.getAge();
    file << "|";
    file << p.getAddress();
    file << "|";
    file << p.getContact();

    file.close();
}

void writeLawyer(Lawyer l)
{
    fstream file;
    file.open("Data/lawyer.txt", ios::app);
    file << endl;
    file << l.getAadhar();
    file << "|";
    file << l.getName();
    file << "|";
    file << l.getAge();
    file << "|";
    file << l.getAddress();
    file << "|";
    file << l.getContact();
    file << "|";
    file << l.getLawyerId();

    file.close();
}

void writeJudge(Judge j)
{
    fstream file;
    file.open("Data/judge.txt", ios::app);
    file << endl;
    file << j.getAadhar();
    file << "|";
    file << j.getName();
    file << "|";
    file << j.getAge();
    file << "|";
    file << j.getAddress();
    file << "|";
    file << j.getContact();
    file << "|";
    file << j.getJudgeId();

    file.close();
}

void writeCourt(Court c)
{
    fstream file;
    file.open("Data/court.txt", ios::app);
    file << endl;
    file << c.getType();
    file << "|";
    file << c.getLocation();
    file << "|";
    file << c.getCourtId();

    file.close();
}

void writeCriminal(Criminal c)
{
    fstream file;
    file.open("Data/criminal.txt", ios::app);
    file << endl;
    file << c.getCaseId();
    file << "|";
    file << c.getDescription();
    file << "|";
    file << c.getPlaintiff()->getAadhar();
    file << "|";
    file << c.getDefendant()->getAadhar();
    file << "|";
    vector<Person *> v(c.getWitnessList());
    for (int i = 1; i < v.size(); i++)
    {
        file << v[i - 1]->getAddress();
        file << ",";
    }
    if (v.size() != 0)
        file << v[v.size() - 1]->getAadhar();
    else
        file << "-1";
    file << "|";
    file << c.getJudge()->getAadhar();
    file << "|";
    file << c.get_Plaintiff_Lawyer()->getAadhar();
    file << "|";
    file << c.get_Defendant_Lawyer()->getAadhar();
    file << "|";
    file << c.getCourt()->getCourtId();
    file << "|";
    State s = c.getState();
    if (s == ASSIGNED)
        file << "ASSIGNED";
    else if (s == DECIDED)
        file << "DECIDED";
    else
        file << "PENDING";
    file << "|";
    file << c.getFilingDate();
    file << "|";
    vector<string> v2(c.getHearingDates());
    for (int i = 1; i < v2.size(); i++)
    {
        file << v2[i - 1];
        file << ",";
    }
    if (v2.size() != 0)
        file << v2[v2.size() - 1];
    else
        file << "-1";
}

void writeCivil(Civil c)
{
    fstream file;
    file.open("Data/civil.txt", ios::app);
    file << endl;
    file << c.getCaseId();
    file << "|";
    file << c.getDescription();
    file << "|";
    file << c.getPlaintiff()->getAadhar();
    file << "|";
    file << c.getDefendant()->getAadhar();
    file << "|";
    vector<Person *> v(c.getWitnessList());
    for (int i = 1; i < v.size(); i++)
    {
        file << v[i - 1]->getAddress();
        file << ",";
    }
    if (v.size() != 0)
        file << v[v.size() - 1]->getAadhar();
    else
        file << "-1";
    file << "|";
    file << c.getJudge()->getAadhar();
    file << "|";
    file << c.get_Plaintiff_Lawyer()->getAadhar();
    file << "|";
    file << c.get_Defendant_Lawyer()->getAadhar();
    file << "|";
    file << c.getCourt()->getCourtId();
    file << "|";
    State s = c.getState();
    if (s == ASSIGNED)
        file << "ASSIGNED";
    else if (s == DECIDED)
        file << "DECIDED";
    else
        file << "PENDING";
    file << "|";
    file << c.getFilingDate();
    file << "|";
    vector<string> v2(c.getHearingDates());
    for (int i = 1; i < v2.size(); i++)
    {
        file << v2[i - 1];
        file << ",";
    }
    if (v2.size() != 0)
        file << v2[v2.size() - 1];
    else
        file << "-1";
}

void writeFamily(Family c)
{
    fstream file;
    file.open("Data/family.txt", ios::app);
    file << endl;
    file << c.getCaseId();
    file << "|";
    file << c.getDescription();
    file << "|";
    file << c.getPlaintiff()->getAadhar();
    file << "|";
    file << c.getDefendant()->getAadhar();
    file << "|";
    vector<Person *> v(c.getWitnessList());
    for (int i = 1; i < v.size(); i++)
    {
        file << v[i - 1]->getAddress();
        file << ",";
    }
    if (v.size() != 0)
        file << v[v.size() - 1]->getAadhar();
    else
        file << "-1";
    file << "|";
    file << c.getJudge()->getAadhar();
    file << "|";
    file << c.get_Plaintiff_Lawyer()->getAadhar();
    file << "|";
    file << c.get_Defendant_Lawyer()->getAadhar();
    file << "|";
    file << c.getCourt()->getCourtId();
    file << "|";
    State s = c.getState();
    if (s == ASSIGNED)
        file << "ASSIGNED";
    else if (s == DECIDED)
        file << "DECIDED";
    else
        file << "PENDING";
    file << "|";
    file << c.getFilingDate();
    file << "|";
    vector<string> v2(c.getHearingDates());
    for (int i = 1; i < v2.size(); i++)
    {
        file << v2[i - 1];
        file << ",";
    }
    if (v2.size() != 0)
        file << v2[v2.size() - 1];
    else
        file << "-1";
}

void deleteCriminal(string id)
{
    fstream file;
    file.open("Data/criminal.txt", ios::out);
    int flag = 0;
    for (auto itr = criminal_cases.begin(); itr != criminal_cases.end(); itr++)
    {
        // check if id matches
        
        if ((itr->second.getCaseId()) != id)
        {

            if (flag!=0)
            {
                file << endl;
            }
            flag++;
            
            file << itr->second.getCaseId();
            file << "|";
            file << itr->second.getDescription();
            file << "|";
            file << itr->second.getPlaintiff()->getAadhar();
            file << "|";
            file << itr->second.getDefendant()->getAadhar();
            file << "|";
            vector<Person *> v(itr->second.getWitnessList());
            for (int i = 1; i < v.size(); i++)
            {
                file << v[i - 1]->getAddress();
                file << ",";
            }
            if (v.size() != 0)
                file << v[v.size() - 1]->getAadhar();
            else
                file << "-1";
            file << "|";
            file << itr->second.getJudge()->getAadhar();
            file << "|";
            file << itr->second.get_Plaintiff_Lawyer()->getAadhar();
            file << "|";
            file << itr->second.get_Defendant_Lawyer()->getAadhar();
            file << "|";
            file << itr->second.getCourt()->getCourtId();
            file << "|";
            State s = itr->second.getState();
            if (s == ASSIGNED)
                file << "ASSIGNED";
            else if (s == DECIDED)
                file << "DECIDED";
            else
                file << "PENDING";
            file << "|";
            file << itr->second.getFilingDate();
            file << "|";
            vector<string> v2(itr->second.getHearingDates());
            for (int i = 1; i < v2.size(); i++)
            {
                file << v2[i - 1];
                file << ",";
            }
            if (v2.size() != 0)
                file << v2[v2.size() - 1];
            else
                file << "-1";

            
        }
    }
    criminal_cases.erase(id);
    file.close();
};

void deleteFamily(string id)
{
    fstream file;
    file.open("Data/family.txt", ios::out);
    int flag = 0;
    for (auto itr = family_cases.begin(); itr != family_cases.end(); itr++)
    {
        // check if id matches
        if ((itr->second.getCaseId()) != id)
        {
            if (flag!=0)
            {
                file << endl;
            }
            flag++;

            file << itr->second.getCaseId();
            file << "|";
            file << itr->second.getDescription();
            file << "|";
            file << itr->second.getPlaintiff()->getAadhar();
            file << "|";
            file << itr->second.getDefendant()->getAadhar();
            file << "|";
            vector<Person *> v(itr->second.getWitnessList());
            for (int i = 1; i < v.size(); i++)
            {
                file << v[i - 1]->getAddress();
                file << ",";
            }
            if (v.size() != 0)
                file << v[v.size() - 1]->getAadhar();
            else
                file << "-1";
            file << "|";
            file << itr->second.getJudge()->getAadhar();
            file << "|";
            file << itr->second.get_Plaintiff_Lawyer()->getAadhar();
            file << "|";
            file << itr->second.get_Defendant_Lawyer()->getAadhar();
            file << "|";
            file << itr->second.getCourt()->getCourtId();
            file << "|";
            State s = itr->second.getState();
            if (s == ASSIGNED)
                file << "ASSIGNED";
            else if (s == DECIDED)
                file << "DECIDED";
            else
                file << "PENDING";
            file << "|";
            file << itr->second.getFilingDate();
            file << "|";
            vector<string> v2(itr->second.getHearingDates());
            for (int i = 1; i < v2.size(); i++)
            {
                file << v2[i - 1];
                file << ",";
            }
            if (v2.size() != 0)
                file << v2[v2.size() - 1];
            else
                file << "-1";

        }
    }
    family_cases.erase(id);
    file.close();
};

void deleteCivil(string id)
{
    fstream file;
    file.open("Data/civil.txt", ios::out);
    int flag = 0;
    for (auto itr = civil_cases.begin(); itr != civil_cases.end(); itr++)
    {
        // check if id matches
        if ((itr->second.getCaseId()) != id)
        {
            if (flag!=0)
            {
                file << endl;
            }
            flag++;

            file << itr->second.getCaseId();
            file << "|";
            file << itr->second.getDescription();
            file << "|";
            file << itr->second.getPlaintiff()->getAadhar();
            file << "|";
            file << itr->second.getDefendant()->getAadhar();
            file << "|";
            vector<Person *> v(itr->second.getWitnessList());
            for (int i = 1; i < v.size(); i++)
            {
                file << v[i - 1]->getAddress();
                file << ",";
            }
            if (v.size() != 0)
                file << v[v.size() - 1]->getAadhar();
            else
                file << "-1";
            file << "|";
            file << itr->second.getJudge()->getAadhar();
            file << "|";
            file << itr->second.get_Plaintiff_Lawyer()->getAadhar();
            file << "|";
            file << itr->second.get_Defendant_Lawyer()->getAadhar();
            file << "|";
            file << itr->second.getCourt()->getCourtId();
            file << "|";
            State s = itr->second.getState();
            if (s == ASSIGNED)
                file << "ASSIGNED";
            else if (s == DECIDED)
                file << "DECIDED";
            else
                file << "PENDING";
            file << "|";
            file << itr->second.getFilingDate();
            file << "|";
            vector<string> v2(itr->second.getHearingDates());
            for (int i = 1; i < v2.size(); i++)
            {
                file << v2[i - 1];
                file << ",";
            }
            if (v2.size() != 0)
                file << v2[v2.size() - 1];
            else
                file << "-1";

        }
    }
    civil_cases.erase(id);
    file.close();
};

int toInt(string s)
{
    int i = 1;
    int flag = 0;
    if (s[0] == '-')
    {
        flag = 1;
        i++;
    }

    int result = 0;
    for (; i <= s.length(); i++)
        result = result * 10 + (s[i - 1] - '0');

    if (flag == 1)
        return result * -1;
    return result;
}
