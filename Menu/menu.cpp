#include <bits/stdc++.h>
#include <unistd.h>
#include <conio.h>
using namespace std;

void displayMenu()
{
    system("CLS");
    cout << "\t\t\t\tLogin Page" << endl;
    int count = 0;
    bool login = false;
    bool result;
    while (count < 3 && login == false)
    {
        cout << endl;
        cout << "Enter user id : ";
        string adminId;
        cin >> adminId;

        cout << "Enter password : ";
        string password;
        cin >> password;
        cout << endl;
        if (admin.find(adminId) != admin.end())
        {
            if (password == admin[adminId])
            {
                login = true;
                system("CLS");
            }
            else
            {
                cout << password << " " << admin[adminId] << endl;
                count++;
                cout << "Incorrect password!" << endl;
                cout << "You have " << 3 - count << " trials remaining" << endl;
            }
        }
        else
        {
            count++;
            cout << "User ID not found!" << endl;
            cout << "You have " << 3 - count << " trials remaining" << endl;
        }
    }

    if (login == false)
    {
        cout << endl;
        cout << "Sorry, you have had many invalid attempts to login. Exiting the program now!" << endl;
        return;
    }
    cout << "Welcome! Choose one the options below to get started" << endl
         << endl;
    while (true)
    {
    home:
        cout << "0. Create A New Case " << endl;
        cout << "1. View Case Details" << endl;
        cout << "2. View Court Details" << endl;
        cout << "3. Show Lawyers" << endl;
        cout << "4. Show Judges" << endl;
        cout << "5. Delete a Case " << endl;
        cout << "6. Add Administrator" << endl;
        cout << "7. Delete Administrator" << endl;
        cout << "-1. Exit Program" << endl;
        cout << "Enter : ";
        int mainMenu;
        cin >> mainMenu;
        cout << endl;

        string location;
        string s;
        string id;
        switch (mainMenu)
        {
        case 1:
            system("CLS");
        show_cases:
            cout << "What would you like to see " << endl;
            cout << "1. Criminal cases" << endl;
            cout << "2. Civil Cases " << endl;
            cout << "3. Family Cases" << endl;
            cout << "4. Go Back" << endl;
            cout << "Enter : ";
            cin >> s;
            cout << endl;
            if (s == "4")
            {
                system("CLS");
                goto home;
            }

            if (s == "1")
            {
                system("CLS");
                cout << "Enter case id : ";
                cin >> id;
                cout << endl;
                cout << "Searching..." << endl;
                sleep(1.5);

                if (criminal_cases.find(id) != criminal_cases.end())
                {
                    // found
                    criminal_cases[id].CaseReport();
                    cout << "press any key to continue...";
                    getch();
                    cout << endl;
                }
                else
                {
                    // not found
                    cout << "Sorry! We couldn't find any case by those credentials" << endl;
                    cout << "press any key to continue...";
                    getch();
                    cout << endl;
                }
            }
            else if (s == "2")
            {
                system("CLS");
                cout << "Enter case id : ";
                cin >> id;
                cout << endl;
                cout << "Searching..." << endl;
                sleep(1.5);

                if (civil_cases.find(id) != civil_cases.end())
                {
                    // found
                    system("CLS");
                    civil_cases[id].CaseReport();
                    cout << "press any key to continue...";
                    getch();
                    cout << endl;
                }
                else
                {
                    // not found
                    cout << "Sorry! We couldn't find any case by those credentials" << endl;
                    cout << "press any key to continue...";
                    getch();
                    cout << endl;
                }
            }
            else if (s == "3")
            {
                system("CLS");
                cout << "Enter case id : ";
                cin >> id;
                cout << endl;
                cout << "Searching..." << endl;
                sleep(1.5);

                if (family_cases.find(id) != family_cases.end())
                {
                    // found
                    system("CLS");
                    family_cases[id].CaseReport();
                    cout << "press any key to continue...";
                    getch();
                    cout << endl;
                }
                else
                {
                    // not found
                    cout << "Sorry! We couldn't find any case by those credentials" << endl
                         << endl;
                    cout << "press any key to continue...";
                    getch();
                    cout << endl;
                }
            }
            else
            {
                cout << "Invalid Input...\nTry Again" << endl;
                goto show_cases;
            }

            system("CLS");
            break;
        case 2:
            system("CLS");
            cout << "Enter court ID : ";
            cin >> s;
            cout << endl;
            cout << "Searching..." << endl;
            sleep(1.5);

            if (crt.find(s) != crt.end())
            {
                // found
                crt[s].display();
            }
            else
            {
                // not found
                cout << "Sorry! We couldn't find any courts by that Id" << endl
                     << endl;
            }
            break;
        case 3:
            // lawyer details
            // cout << "All the lawyer details are being displayed now" << endl;
            system("CLS");
            cout << "Aadhar Card Number | Lawyer Names " << endl;
            for (auto itr : law)
            {
                if (itr.second.getAadhar() != "NA")
                {
                    cout << itr.first << "       | ";
                    cout << itr.second.getName();
                    cout << endl;
                }
            }
            cout << endl;
        invalid_lawyer_input:
            cout << "Do you want to see specific details for a lawyer? (Y/N) ";
            cin >> id;
            if (id == "Y" || id == "y")
            {
                cout << endl;
                cout << "Enter Aadhar Card Number : ";
                cin >> s;
                cout << endl;
                if (law.find(s) != law.end())
                {
                    system("CLS");
                    // found
                    law[s].display();
                    cout << endl;
                    cout << "press any key to continue...";
                    getch();
                    cout << endl;
                }
                else
                {
                    // not found
                    cout << "Sorry! We couldn't find any lawyers by that aadhar card number" << endl;
                    cout << "press any key to continue...";
                    getch();
                    cout << endl;
                }
            }

            else if (id != "N" && id != "n")
            {
                cout << "Invalid Input...\nTry Again" << endl;
                goto invalid_lawyer_input;
            }
            system("CLS");
            break;
        case 4:
            // judge details
            // cout << "All the judge details are being displayed now" << endl;
            system("CLS");
            cout << "Aadhar Card Number | Judge Names " << endl;
            for (auto itr : jud)
            {
                if (itr.second.getAadhar() != "NA")
                {
                    cout << itr.first << "       | ";
                    cout << itr.second.getName();
                    cout << endl;
                }
            }
            cout << endl;
        invalid_judge_input:
            cout << "Do you want to see specific details for a Judge? (Y/N) ";
            cin >> id;

            if (id == "Y" || id == "y")
            {
                cout << endl;
                cout << "Enter Aadhar Card Number : ";
                cin >> s;
                cout << endl;
                if (jud.find(s) != jud.end())
                {
                    // found
                    system("CLS");
                    jud[s].display();
                    cout << endl;
                    cout << "press any key to continue...";
                    getch();
                    cout << endl;
                }
                else
                {
                    // not found
                    cout << "Sorry! We couldn't find any judges by that aadhar card number" << endl;
                    cout << "press any key to continue...";
                    getch();
                    cout << endl;
                }
            }

            else if (id != "N" && id != "n")
            {
                cout << "Invalid Input...\nTry Again" << endl;
                goto invalid_judge_input;
            }
            system("CLS");
            break;
        case 5:
            system("CLS");
        delete_case_menu:
            cout << "1. Criminal Case " << endl;
            cout << "2. Civil Case" << endl;
            cout << "3. Family Case" << endl;
            cout << "4. Go Back" << endl;
            cout << "Enter : ";
            cin >> s;

            if (s == "4")
            {
                system("CLS");
                goto home;
            }

            if (s == "1")
            {
                system("CLS");
                cout << "Enter Case Id : ";
                cin >> id;
                cout << endl
                     << "Deleting Case...";
                sleep(1.5);
                if (criminal_cases[id].getCaseId() == "")
                {
                    cout << endl
                         << endl
                         << "Deletion Error..." << endl;
                    cout << "Criminal Case with Case ID-" << id << " does not exist" << endl
                         << endl;
                }
                else
                {
                    deleteCriminal(id);
                    cout << endl
                         << endl
                         << "Criminal Case with Case ID-" << id << " has been successfully deleted" << endl;
                }
                cout << "Press any key to continue...";
                getch();
            }
            else if (s == "2")
            {
                system("CLS");
                cout << "Enter Case Id : ";
                cin >> id;
                cout << endl
                     << "Deleting Case...";
                sleep(1.5);
                if (civil_cases[id].getCaseId() == "")
                {
                    cout << endl
                         << endl
                         << "Deletion Error..." << endl;
                    cout << "Civil Case with Case ID-" << id << " does not exist" << endl
                         << endl;
                }
                else
                {
                    deleteCivil(id);
                    cout << endl
                         << endl
                         << "Civil Case with Case ID-" << id << " has been successfully deleted" << endl;
                }
                cout << "Press any key to continue...";
                getch();
            }
            else if (s == "3")
            {
                system("CLS");
                cout << "Enter Case Id : ";
                cin >> id;
                cout << endl
                     << "Deleting Case...";
                sleep(1.5);
                if (family_cases[id].getCaseId() == "")
                {
                    cout << endl
                         << endl
                         << "Deletion Error..." << endl;
                    cout << "Family Case with Case ID-" << id << " does not exist" << endl
                         << endl;
                }
                else
                {
                    deleteFamily(id);
                    cout << endl
                         << endl
                         << "Family Case with Case ID-" << id << " has been successfully deleted" << endl;
                }
                cout << "Press any key to continue...";
                getch();
            }
            else
            {
                cout << "Invalid Input...\nTry Again..." << endl;
                goto delete_case_menu;
            }
            system("CLS");
            break;
        case 6:
            // ____________ADD ADMINISTRATOR____________
            system("CLS");
        add_admin_menu:
            cout << "Enter id : ";
            cin >> id;
            cout << "Enter password : ";
            cin >> s;

            if (admin.find(id) != admin.end())
            {
                cout << "A user by that id already exists!" << endl
                     << endl;
                    cout << "press any key to continue...";
                    getch();
                    goto add_admin_menu;

            }
            addAdmin(id, s);
            system("CLS");
            goto home;
        case 7:
            // _____________DELETE ADMINISTRATOR___________
            system("CLS");
        delete_admin_menu:
            if (admin.size() == 1)
            {
                cout << "Cannot delete. At least one administrator is required!" << endl;
                sleep(2);
                system("CLS");
                goto home;
            }
            cout << "Enter id : ";
            cin >> id;

            if (admin.find(id) != admin.end())
                deleteAdmin(id);
            else
            {
                for (auto itr = admin.begin(); itr != admin.end(); itr++)
                    cout << itr->first << " " << itr->second << endl;
                cout << "Enter valid credentials " << endl
                     << endl;
                goto delete_admin_menu;
            }
            cout << "Deletion successful!" << endl;
            cout << "press any key to continue...";
            getch();
            system("CLS");
            goto home;
        case -1:
            system("CLS");
            cout << "Thank you for using our program!" << endl;
            return;
        case 0:
        {
            string desc;
            Person ptif;
            Person def;
            Judge jdge;
            Lawyer pLaw;
            Lawyer dLaw;
            Court cort;
            string stat;
            string fDate;

            int case_type;
            string case_id;
            string aad;
            string nme;
            string id;
            string adre;
            string cntct;
            string loc;
            string typ;
            int ag;

            // ___________Case Type_________________
        input_case_type:
            int inpt2;
            system("CLS");
            cout << "Enter Type of Case" << endl;
            cout << "1. Criminal Case" << endl;
            cout << "2. Civil Case" << endl;
            cout << "3. Family Case" << endl;
            cout << "4. Go Back" << endl;
            cout << "Enter : ";
            cin >> inpt2;
            cout << endl;
            if (inpt2 == 4)
            {
                system("CLS");
                goto home;
            }

            if (inpt2 != 1 && inpt2 != 2 && inpt2 != 3)
            {
                cout << "Invalid Input...\nTry Again" << endl
                     << endl;
                goto input_case_type;
            }

            // ___________Case ID_________________
            system("CLS");
            cout << "Enter Case Id : ";
            cin >> case_id;
            int val1 = (inpt2 == 1) && (criminal_cases[case_id].getCaseId() != "");
            int val2 = (inpt2 == 2) && (civil_cases[case_id].getCaseId() != "");
            int val3 = (inpt2 == 3) && (family_cases[case_id].getCaseId() != "");
            if (val1 || val2 || val3)
            {
                cout << "Case is already registered" << endl
                     << endl;
                cout << "press any key to continue...";
                getch();
                cout << endl;
                break;
            }
            cout << endl;

            // ___________Plaintiff_________________
            cout << "Enter details of plaintiff" << endl;
            cout << "Enter Aadhar Number : ";
            cin >> aad;
            if (per[aad].getName() == "NA")
            {
                cout << "Enter Name : ";
                cin.ignore();
                getline(cin, nme);
                cout << "Enter Age : ";
                cin >> ag;
                cout << "Enter Address : ";
                cin.ignore();
                getline(cin, adre);
                cout << "Enter Contact : ";
                cin >> cntct;

                ptif.setAadhar(aad);
                ptif.setName(nme);
                ptif.setAge(ag);
                ptif.setAddress(adre);
                ptif.setContact(cntct);
            }
            else
                ptif = per[aad];
            cout << endl;

            // ___________defendant_________________
            cout << "Enter details of defendant" << endl;
            cout << "Enter Aadhar Number : ";
            cin >> aad;
            if (per[aad].getName() == "NA")
            {
                cout << "Enter Name : ";
                cin.ignore();
                getline(cin, nme);
                cout << "Enter Age : ";
                cin >> ag;
                cout << "Enter Address : ";
                cin.ignore();
                getline(cin, adre);
                cout << "Enter Contact : ";
                cin >> cntct;

                def.setAadhar(aad);
                def.setName(nme);
                def.setAge(ag);
                def.setAddress(adre);
                def.setContact(cntct);
            }
            else
                def = per[aad];
            cout << endl;

            // ___________Judge_________________
            cout << "Enter details of judge" << endl;
            cout << "Enter Aadhar Number : ";
            cin >> aad;
            if (jud[aad].getName() == "NA")
            {
                cout << "Enter Judge ID : ";
                cin >> id;
                cout << "Enter Name : ";
                cin.ignore();
                getline(cin, nme);
                cout << "Enter Age : ";
                cin >> ag;
                cout << "Enter Address : ";
                cin.ignore();
                getline(cin, adre);
                cout << "Enter Contact : ";
                cin >> cntct;

                jdge.setAadhar(aad);
                jdge.setJudgeId(toInt(id));
                jdge.setName(nme);
                jdge.setAge(ag);
                jdge.setAddress(adre);
                jdge.setContact(cntct);
            }
            else
                jdge = jud[aad];
            cout << endl;

            // ___________Plaintiff Lawyer_________________
            cout << "Enter details of Plaintiff Lawyer" << endl;
            cout << "Enter Aadhar Number : ";
            cin >> aad;
            if (law[aad].getName() == "NA")
            {
                cout << "Enter Lawyer ID : ";
                cin >> id;
                cout << "Enter Name : ";
                cin.ignore();
                getline(cin, nme);
                cout << "Enter Age : ";
                cin >> ag;
                cout << "Enter Address : ";
                cin.ignore();
                getline(cin, adre);
                cout << "Enter Contact : ";
                cin >> cntct;

                pLaw.setAadhar(aad);
                pLaw.setLawyerId(toInt(id));
                pLaw.setName(nme);
                pLaw.setAge(ag);
                pLaw.setAddress(adre);
                pLaw.setContact(cntct);
            }
            else
                pLaw = law[aad];
            cout << endl;

            // ___________Defendant Lawyer_________________
            cout << "Enter details of Defendant Lawyer" << endl;
            cout << "Enter Aadhar Number : ";
            cin >> aad;
            if (law[aad].getName() == "NA")
            {
                cout << "Enter Lawyer ID : ";
                cin >> id;
                cout << "Enter Name : ";
                cin.ignore();
                getline(cin, nme);
                cout << "Enter Age : ";
                cin >> ag;
                cout << "Enter Address : ";
                cin.ignore();
                getline(cin, adre);
                cout << "Enter Contact : ";
                cin >> cntct;

                dLaw.setAadhar(aad);
                dLaw.setLawyerId(toInt(id));
                dLaw.setName(nme);
                dLaw.setAge(ag);
                dLaw.setAddress(adre);
                dLaw.setContact(cntct);
            }
            else
                dLaw = law[aad];
            cout << endl;

            // ___________Court_________________
            cout << "Enter Details of Court" << endl;
            cout << "Enter Court ID : ";
            cin >> id;
            if (crt[id].court_ID == "NA")
            {
                cout << "Enter Location : ";
                cin.ignore();
                getline(cin, loc);
                cout << "Enter Type : ";
                cin.ignore();
                getline(cin, typ);

                cort.setCourtId(id);
                cort.setLocation(loc);
                cort.setType(typ);
            }
            else
                cort = crt[id];
            cout << endl;

        // ___________Status_________________
        status_input:
            cout << "Enter Status of the case" << endl;
            cout << "1. Pending" << endl;
            cout << "2. Assigned" << endl;
            cout << "3. Decided" << endl;
            cout << "Enter : ";
            int inpt;
            cin >> inpt;
            cout << endl;
            if (inpt == 1)
                stat = "p";
            else if (inpt == 2)
                stat = "a";
            else if (inpt == 3)
                stat = "d";
            else
            {
                cout << "Invalid Input...\nTry Again" << endl;
                goto status_input;
            }
            cout << endl;

            // ___________Filing Date_________________
            cout << "Enter Filing Date : ";
            cin >> fDate;

            // ___________Description_________________
            cout << "Enter description about the case : ";
            cin.ignore();
            getline(cin, desc);

            // ___________Witness_________________
            int nWit;
            cout << "Enter Number of Witnesses : ";
            cin >> nWit;
            vector<Person> witVec;
            for (int i = 1; i <= nWit; i++)
            {
                Person p;
                cout << "Enter details of Witness-" << i << endl;
                cout << "Enter Aadhar Number : ";
                cin >> aad;
                if (per[aad].getName() == "NA")
                {
                    cout << "Enter Name : ";
                    cin.ignore();
                    getline(cin, nme);
                    cout << "Enter Age : ";
                    cin >> ag;
                    cout << "Enter Address : ";
                    cin.ignore();
                    getline(cin, adre);
                    cout << "Enter Contact : ";
                    cin >> cntct;

                    p.setAadhar(aad);
                    p.setName(nme);
                    p.setAge(ag);
                    p.setAddress(adre);
                    p.setContact(cntct);
                }
                else
                    p = per[aad];
                witVec.push_back(p);
                cout << endl;
            }

            // ___________Hearing Dates_________________
            int nDat;
            cout << "Number of Hearing Dates : ";
            cin >> nDat;
            vector<string> dat_vec;
            for (int i = 1; i <= nDat; i++)
            {
                string s;
                cout << "Enter Hearing Date-" << i << " : ";
                cin >> s;
                dat_vec.push_back(s);
            }
            cout << endl;
            // ___________CRIMINAL_________________
            if (inpt2 == 1)
            {
                Criminal c;
                c.setCaseId(case_id);
                c.setCourt(&cort);
                c.setDefendant(&def);
                c.setDefendantLawyer(&dLaw);
                c.setDescription(desc);
                c.setFilingDate(fDate);
                c.setJudge(&jdge);
                c.setPlaintiff(&ptif);
                c.setPlaintiffLawyer(&pLaw);
                if (stat == "p")
                    c.setStatus(PENDING);
                else if (stat == "a")
                    c.setStatus(ASSIGNED);
                else
                    c.setStatus(DECIDED);
                c.setType("Criminal");
                for (auto i : witVec)
                    c.addWitness(&i);
                for (auto i : dat_vec)
                    c.addHearingDate(i);

                cout << "Adding New Case..." << endl;
                sleep(1.5);
                if (per[ptif.getAadhar()].getName() == "NA")
                {
                    writePerson(ptif);
                    per[ptif.getAadhar()] = ptif;
                }
                if (per[def.getAadhar()].getName() == "NA")
                {
                    writePerson(def);
                    per[def.getAadhar()] = def;
                }
                if (law[pLaw.getAadhar()].getName() == "NA")
                {
                    writeLawyer(pLaw);
                    law[pLaw.getAadhar()] = pLaw;
                }
                if (law[dLaw.getAadhar()].getName() == "NA")
                {
                    writeLawyer(dLaw);
                    law[dLaw.getAadhar()] = dLaw;
                }
                if (jud[jdge.getAadhar()].getName() == "NA")
                {
                    writeJudge(jdge);
                    jud[jdge.getAadhar()] = jdge;
                }
                if (crt[cort.getCourtId()].getCourtId() == "NA")
                {
                    writeCourt(cort);
                    crt[cort.getCourtId()] = cort;
                }

                writeCriminal(c);
                criminal_cases[c.getCaseId()] = c;

                cout << "Case has been added" << endl
                     << endl;
            }

            // ___________CIVIL_________________
            else if (inpt2 == 2)
            {
                Civil c;
                c.setCaseId(case_id);
                c.setCourt(&cort);
                c.setDefendant(&def);
                c.setDefendantLawyer(&dLaw);
                c.setDescription(desc);
                c.setFilingDate(fDate);
                c.setJudge(&jdge);
                c.setPlaintiff(&ptif);
                c.setPlaintiffLawyer(&pLaw);
                if (stat == "p")
                    c.setStatus(PENDING);
                else if (stat == "a")
                    c.setStatus(ASSIGNED);
                else
                    c.setStatus(DECIDED);
                c.setType("Civil");
                for (auto i : witVec)
                    c.addWitness(&i);
                for (auto i : dat_vec)
                    c.addHearingDate(i);

                cout << "Adding New Case..." << endl;
                sleep(1.5);
                if (per[ptif.getAadhar()].getName() == "NA")
                {
                    writePerson(ptif);
                    per[ptif.getAadhar()] = ptif;
                }
                if (per[def.getAadhar()].getName() == "NA")
                {
                    writePerson(def);
                    per[def.getAadhar()] = def;
                }
                if (law[pLaw.getAadhar()].getName() == "NA")
                {
                    writeLawyer(pLaw);
                    law[pLaw.getAadhar()] = pLaw;
                }
                if (law[dLaw.getAadhar()].getName() == "NA")
                {
                    writeLawyer(dLaw);
                    law[dLaw.getAadhar()] = dLaw;
                }
                if (jud[jdge.getAadhar()].getName() == "NA")
                {
                    writeJudge(jdge);
                    jud[jdge.getAadhar()] = jdge;
                }
                if (crt[cort.getCourtId()].getCourtId() == "NA")
                {
                    writeCourt(cort);
                    crt[cort.getCourtId()] = cort;
                }

                writeCivil(c);
                civil_cases[c.getCaseId()] = c;

                cout << "Case has been added" << endl
                     << endl;
            }

            // ___________FAMILY_________________
            else
            {
                Family c;
                c.setCaseId(case_id);
                c.setCourt(&cort);
                c.setDefendant(&def);
                c.setDefendantLawyer(&dLaw);
                c.setDescription(desc);
                c.setFilingDate(fDate);
                c.setJudge(&jdge);
                c.setPlaintiff(&ptif);
                c.setPlaintiffLawyer(&pLaw);
                if (stat == "p")
                    c.setStatus(PENDING);
                else if (stat == "a")
                    c.setStatus(ASSIGNED);
                else
                    c.setStatus(DECIDED);
                c.setType("Family");
                for (auto i : witVec)
                    c.addWitness(&i);
                for (auto i : dat_vec)
                    c.addHearingDate(i);

                cout << "Adding New Case..." << endl;
                sleep(1.5);
                if (per[ptif.getAadhar()].getName() == "NA")
                {
                    writePerson(ptif);
                    per[ptif.getAadhar()] = ptif;
                }
                if (per[def.getAadhar()].getName() == "NA")
                {
                    writePerson(def);
                    per[def.getAadhar()] = def;
                }
                if (law[pLaw.getAadhar()].getName() == "NA")
                {
                    writeLawyer(pLaw);
                    law[pLaw.getAadhar()] = pLaw;
                }
                if (law[dLaw.getAadhar()].getName() == "NA")
                {
                    writeLawyer(dLaw);
                    law[dLaw.getAadhar()] = dLaw;
                }
                if (jud[jdge.getAadhar()].getName() == "NA")
                {
                    writeJudge(jdge);
                    jud[jdge.getAadhar()] = jdge;
                }
                if (crt[cort.getCourtId()].getCourtId() == "NA")
                {
                    writeCourt(cort);
                    crt[cort.getCourtId()] = cort;
                }

                writeFamily(c);
                family_cases[c.getCaseId()] = c;

                cout << "Case has been added" << endl
                     << endl;
            }

            break;
        }
        default:
            cout << "Enter a valid choice! Redirecting to the main menu" << endl
                 << endl;
            break;
        }
    }
}