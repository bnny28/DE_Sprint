#include <iostream>
#include <regex>

using namespace std;

/** Написать программу, которая сравнивает два введённых с клавиатуры числа.
 *  Программа должна указать, какое число больше или, если числа равны, вывести соответствующее сообщение.
**/

int inputIntNumber(const string &msg) {
    string str;
    bool is_valid;
    regex regex_pattern("[-]?[0-9]+");
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
    int a, b;

    a = inputIntNumber("input integer a:");
    b = inputIntNumber("input integer b:");

    if (a > b) {
        cout << "a > b" << endl;
    } else if (a < b) {
        cout << "a < b" << endl;
    } else {
        cout << "a == b" << endl;
    }
    return 0;
}
