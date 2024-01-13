#ifndef EMPLOYEEDATABASE_H
#define EMPLOYEEDATABASE_H

#include "employee.h"

class EmployeeDatabase 
{
private:
    struct Node
    {
        Employee employee;
        Node* next;
        Node(const Employee& employee);
    };

    Node* head;
    string filename;

public:
    EmployeeDatabase(const string& filename);
    ~EmployeeDatabase();

    void addEmployee(const Employee& employee);
    void removeEmployee(const string& surname);
    Employee* searchBySurname(const string& surname) const;
    Employee* searchByAge(int age) const;
    Employee* searchByFirstLetter(char letter) const;
    void loadFromFile();
    void saveToFile() const;

private:
    void clearList();
};

#endif 