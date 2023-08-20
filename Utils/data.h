#ifndef DATA_H
#define DATA_H

# include <bits/stdc++.h>

using namespace std;

map<string , Person> per;
map<string , Lawyer> law;
map<string , Judge> jud;
map<string , Court> crt;
map<string , Civil> civil_cases;
map<string , Criminal> criminal_cases;
map<string , Family> family_cases;
map<string, string>admin;

int toInt(string s);
void readPerson();
void readLawyer();
void readJudge();
void readCourt();
void readCases();
void readCivil();
void readCriminal();
void readFamily();
void readAdmin();

void writePerson(Person p);
void writeLawyer(Lawyer l);
void writeJudge(Judge j);
void writeCourt(Court c);
void writeCriminal(Criminal c);
void writeCivil(Civil c);
void writeFamily(Family c);
bool addAdmin(string, string);

void deleteCriminal(int);
void deleteFamily(int);
void deleteCivil(int);
void deleteAdmin(string);
#endif