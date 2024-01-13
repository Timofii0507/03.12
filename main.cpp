#include <iostream>
#include <Windows.h>
#include "employeeDatabase.h"

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string filename = "employee.txt";
    EmployeeDatabase database(filename);
    database.loadFromFile();
    int choice;
    do
    {
        cout << "=== �������ֲ��� ������� \"�ϲ����������\" ===" << endl;
        cout << "1. ������ �����������" << endl;
        cout << "2. �������� �����������" << endl;
        cout << "3. ����� �� ��������" << endl;
        cout << "4. ����� �� ����" << endl;
        cout << "5. ����� �� ������ ������ �������" << endl;
        cout << "6. �������� ������ ����������� � ����" << endl;
        cout << "0. �����" << endl;
        cout << "��� ����: ";
        cin >> choice;
        switch (choice) 
        {
        case 1: 
        {
            string surname, name;
            int age;
            cout << "������ �������: ";
            cin >> surname;
            cout << "������ ��'�: ";
            cin >> name;
            cout << "������ ��: ";
            cin >> age;
            database.addEmployee(Employee(surname, name, age));
            cout << "���������� ������ �������!" << endl;
            break;
        }
        case 2: 
        {
            string surname;
            cout << "������ ������� �����������, ����� ������ ��������: ";
            cin >> surname;
            database.removeEmployee(surname);
            cout << "���������� ������ ���������!" << endl;
            break;
        }
        case 3:
        {
            string surname;
            cout << "������ ������� ��� ������: ";
            cin >> surname;
            Employee* result = database.searchBySurname(surname);
            if (result == nullptr) 
            {
                cout << "����������� � ����� �������� �� ��������." << endl;
            }
            else 
            {
                cout << "���������� ������:" << endl;
                cout << "�������: " << result->surname << ", ��'�: " << result->name << ", ³�: " << result->age << endl;
            }
            break;
        }
        case 4:
        {
            int age;
            cout << "������ �� ��� ������: ";
            cin >> age;
            Employee* result = database.searchByAge(age);
            if (result == nullptr) 
            {
                cout << "����������� � ����� ���� �� ��������." << endl;
            }
            else
            {
                cout << "���������� ������:" << endl;
                cout << "�������: " << result->surname << ", ��'�: " << result->name << ", ³�: " << result->age << endl;
            }
            break;
        }
        case 5:
        {
            char letter;
            cout << "������ ����� ��� ������: ";
            cin >> letter;
            Employee* result = database.searchByFirstLetter(letter);
            if (result == nullptr) 
            {
                cout << "����������� � ���������, �� ����������� �� ������ �����, �� ��������." << endl;
            }
            else 
            {
                cout << "���������� ������:" << endl;
                cout << "�������: " << result->surname << ", ��'�: " << result->name << ", ³�: " << result->age << endl;
            }
            break;
        }
        case 6: 
        {
            database.saveToFile();
            cout << "������ ����������� ������ ���������� � ����!" << endl;
            break;
        }
        case 0:
            break;
        default:
            cout << "������� ����. ��������� �� ���." << endl;
            break;
        }
        cout << endl;
    } while (choice != 0);
    return 0;
}
