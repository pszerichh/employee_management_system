#ifndef FUNCTION_H
#define FUNCTION_H
# include <bits/stdc++.h>
using namespace std;
chrono::seconds ser(8);
chrono::seconds sho(2);
class Employee{
    string name, num, dob, id, gen, sal, add;
    public:
    Employee(string& ID, string& NAME, string& NUM, string& GEN, string& DOB, string& SAL, string& ADD){
        this->name = NAME;
        this->num = NUM;
        this->dob = DOB;
        this->sal = SAL;
        this->gen = GEN;
        this->id = ID;
        this->add = ADD;
    }
    friend void upload(Employee*);
};
#endif