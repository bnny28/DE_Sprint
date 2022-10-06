#include <iostream>
#include <regex>

using namespace std;

/** Написать программу, которая проверяет, является ли год високосным. **/

bool isLeapYear(int year) {
    return (!(year % 4) && (year % 100)) || (!(year % 400));
}

int inputIntYear(const string &msg) {
    string str;
    bool is_valid;
    regex regex_pattern("[0-9]{4}");
    do {
        cout << msg;
        cin >> str;
        is_valid = regex_match(str, regex_pattern);
        if (!is_valid) {
            cout << "it's wrong. again..." << endl;
        }
    } while (!is_valid);

    return stoi(str);
}

int main() {
    int year;

    year = inputIntYear("input year:");

    if (isLeapYear(year)) {
        cout << "leap year" << endl;
    } else {
        cout << "not leap year" << endl;
    }
    return 0;
}
