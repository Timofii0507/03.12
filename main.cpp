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
        cout << "=== ІНФОРМАЦІЙНА СИСТЕМА \"СПІВРОБІТНИКИ\" ===" << endl;
        cout << "1. Додати співробітника" << endl;
        cout << "2. Видалити співробітника" << endl;
        cout << "3. Пошук за прізвищем" << endl;
        cout << "4. Пошук за віком" << endl;
        cout << "5. Пошук за першою літерою прізвища" << endl;
        cout << "6. Зберегти список співробітників у файл" << endl;
        cout << "0. Вихід" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;
        switch (choice) 
        {
        case 1: 
        {
            string surname, name;
            int age;
            cout << "Введіть прізвище: ";
            cin >> surname;
            cout << "Введіть ім'я: ";
            cin >> name;
            cout << "Введіть вік: ";
            cin >> age;
            database.addEmployee(Employee(surname, name, age));
            cout << "Співробітник успішно доданий!" << endl;
            break;
        }
        case 2: 
        {
            string surname;
            cout << "Введіть прізвище співробітника, якого бажаєте видалити: ";
            cin >> surname;
            database.removeEmployee(surname);
            cout << "Співробітник успішно видалений!" << endl;
            break;
        }
        case 3:
        {
            string surname;
            cout << "Введіть прізвище для пошуку: ";
            cin >> surname;
            Employee* result = database.searchBySurname(surname);
            if (result == nullptr) 
            {
                cout << "Співробітників з таким прізвищем не знайдено." << endl;
            }
            else 
            {
                cout << "Результати пошуку:" << endl;
                cout << "Прізвище: " << result->surname << ", Ім'я: " << result->name << ", Вік: " << result->age << endl;
            }
            break;
        }
        case 4:
        {
            int age;
            cout << "Введіть вік для пошуку: ";
            cin >> age;
            Employee* result = database.searchByAge(age);
            if (result == nullptr) 
            {
                cout << "Співробітників з таким віком не знайдено." << endl;
            }
            else
            {
                cout << "Результати пошуку:" << endl;
                cout << "Прізвище: " << result->surname << ", Ім'я: " << result->name << ", Вік: " << result->age << endl;
            }
            break;
        }
        case 5:
        {
            char letter;
            cout << "Введіть літеру для пошуку: ";
            cin >> letter;
            Employee* result = database.searchByFirstLetter(letter);
            if (result == nullptr) 
            {
                cout << "Співробітників з прізвищами, що починаються на задану літеру, не знайдено." << endl;
            }
            else 
            {
                cout << "Результати пошуку:" << endl;
                cout << "Прізвище: " << result->surname << ", Ім'я: " << result->name << ", Вік: " << result->age << endl;
            }
            break;
        }
        case 6: 
        {
            database.saveToFile();
            cout << "Список співробітників успішно збережений у файл!" << endl;
            break;
        }
        case 0:
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
            break;
        }
        cout << endl;
    } while (choice != 0);
    return 0;
}
