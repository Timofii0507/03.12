#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee 
{
public:
    string surname;
    string name;
    int age;
    Employee(const string& surname, const string& name, int age);
};

#endif