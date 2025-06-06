#include <iostream>
#include <string>
#include <map>
#include <functional>
using namespace std;

// Глобальные переменные для хранения введенных данных
char ch1, ch2;

// Проверка корректности ввода
bool isValidCharInput(const string& input) {
    return input.length() == 1;
}

// Функция ввода первого символа
void enterChar1() {
    string input;
    cout << "Введите первый символ: ";
    getline(cin, input);
    
    while (!isValidCharInput(input)) {
        cout << "Ошибка! Введите ровно один символ: ";
        getline(cin, input);
    }
    
    ch1 = input[0];
    cout << "Первый символ сохранен: " << ch1 << endl;
}

// Функция ввода второго символа
void enterChar2() {
    string input;
    cout << "Введите второй символ: ";
    getline(cin, input);
    
    while (!isValidCharInput(input)) {
        cout << "Ошибка! Введите ровно один символ: ";
        getline(cin, input);
    }
    
    ch2 = input[0];
    cout << "Второй символ сохранен: " << ch2 << endl;
}
// Функция вывода символов и их кодов ASCII
void printCharsAndCodes() {
    if (ch1 == '\0' || ch2 == '\0') {
        cout << "Ошибка! Сначала введите оба символа." << endl;
        return;
    }
    
    cout << "Символ 1: " << ch1 << " (код ASCII: " << static_cast<int>(ch1) << ")" << endl;
    cout << "Символ 2: " << ch2 << " (код ASCII: " << static_cast<int>(ch2) << ")" << endl;
}

// Функция вывода суммы кодов ASCII
void printSumOfCodes() {
    if (ch1 == '\0' || ch2 == '\0') {
        cout << "Ошибка! Сначала введите оба символа." << endl;
        return;
    }
    
    int sum = static_cast<int>(ch1) + static_cast<int>(ch2);
    cout << "Сумма кодов ASCII: " << sum << endl;
}

// Структура пункта меню
struct MenuItem {
    string title;
    function<void()> action;
};

int main() {
    map<int, MenuItem> menu = {
        {1, {"Ввод первого символа", enterChar1}},
        {2, {"Ввод второго символа", enterChar2}},
        {3, {"Вывести символы и их коды ASCII", printCharsAndCodes}},
        {4, {"Вывести сумму кодов ASCII", printSumOfCodes}}
    };

    int choice = 0;
    while (true) {
        cout << "Меню:" << endl;
        for (const auto& item : menu) {
            cout << item.first << ". " << item.second.title << endl;
        }
        cout << "0. Выход" << endl;
        cout << "Выберите пункт меню: ";
        cin >> choice;
        cin.ignore(); // Очистка буфера ввода
        
        if (choice == 0) {
            cout << "Работа программы завершена." << endl;
            break;
        }
        
        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        } else {
            cout << "Неверный пункт меню!" << endl;
        }
        cout << endl;
    }
    return 0;
}