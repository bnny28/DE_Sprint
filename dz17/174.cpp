#include <iostream>
#include <regex>

using namespace std;

/** Проверить на чётность введённое с клавиатуры число **/

int inputCheck(const string &msg, const string &reg) {
    string str;
    bool is_valid;
    regex regex_pattern(reg);
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
    int a;

    cout << "input (a, b, c) to solve the quadratic equation ax^2 + bx + c = 0" << endl;
    a = inputCheck("input integer a:", "[-]?[0-9]+");
    cout << "" << endl;

    if (a % 2) {
        cout << "odd" << endl;
    } else {
        cout << "even" << endl;
    }
    return 0;
}
