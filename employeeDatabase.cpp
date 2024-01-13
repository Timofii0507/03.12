#include "employeeDatabase.h"
#include <fstream>

EmployeeDatabase::Node::Node(const Employee& employee)
    : employee(employee), next(nullptr) {}

EmployeeDatabase::EmployeeDatabase(const string& filename)
    : head(nullptr), filename(filename) {}

EmployeeDatabase::~EmployeeDatabase()
{
    clearList();
}

void EmployeeDatabase::addEmployee(const Employee& employee)
{
    Node* newNode = new Node(employee);
    newNode->next = head;
    head = newNode;
}

void EmployeeDatabase::removeEmployee(const string& surname) 
{
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr) 
    {
        if (current->employee.surname == surname) 
        {
            if (prev == nullptr) 
            {
                head = current->next;
            }
            else 
            {
                prev->next = current->next;
            }
            delete current;
            break;
        }
        prev = current;
        current = current->next;
    }
}

Employee* EmployeeDatabase::searchBySurname(const string& surname) const 
{
    Node* current = head;
    while (current != nullptr) 
    {
        if (current->employee.surname == surname) 
        {
            return &(current->employee);
        }
        current = current->next;
    }
    return nullptr;
}

Employee* EmployeeDatabase::searchByAge(int age) const 
{
    Node* current = head;
    while (current != nullptr) 
    {
        if (current->employee.age == age) 
        {
            return &(current->employee);
        }
        current = current->next;
    }
    return nullptr;
}

Employee* EmployeeDatabase::searchByFirstLetter(char letter) const 
{
    Node* current = head;
    while (current != nullptr) 
    {
        if (current->employee.surname[0] == letter) 
        {
            return &(current->employee);
        }
        current = current->next;
    }
    return nullptr;
}

void EmployeeDatabase::loadFromFile()
{
    ifstream file(filename);
    if (file.is_open()) 
    {
        clearList();
        string surname, name;
        int age;
        while (file >> surname >> name >> age) 
        {
            addEmployee(Employee(surname, name, age));
        }
        file.close();
    }
}

void EmployeeDatabase::saveToFile() const 
{
    ofstream file(filename);
    if (file.is_open()) 
    {
        Node* current = head;
        while (current != nullptr) 
        {
            file << current->employee.surname << " " << current->employee.name << " " << current->employee.age << endl;
            current = current->next;
        }
        file.close();
    }
}

void EmployeeDatabase::clearList() 
{
    Node* current = head;
    while (current != nullptr) 
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}
