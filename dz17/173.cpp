#include <iostream>
#include <regex>
#include <cmath>

using namespace std;

/** Написать программу решения квадратного уравнения.
 * Программа должна проверять правильность исходных данных и в случае,
 * если коэффициент при второй степени неизвестного равен нулю, выводить соответствующее сообщение.
**/

float inputCheck(const string &msg, const string &reg) {
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

    return stof(str);
}

int main() {
    float a, b, c, D;

    cout << "input (a, b, c) to solve the quadratic equation ax^2 + bx + c = 0" << endl;
    a = inputCheck("a != 0:", "([+-]?([0-9]*[.])?[0-9]+)?[^0]+");
    b = inputCheck("b:", "[+-]?([0-9]*[.])?[0-9]+");
    c = inputCheck("c:", "[+-]?([0-9]*[.])?[0-9]+");
    cout << "" << endl;

    D = b * b - 4 * a * c;
    if (D == 0) {
        cout << "x = " << -b / (2 * a) << endl;
    } else if (D < 0) {
        cout << "not solve"<< endl;
    } else {
        cout << "x1 = " << (-b + sqrt(D)) / (2 * a) << endl;
        cout << "x2 = " << (-b - sqrt(D)) / (2 * a) << endl;
    }
    return 0;
}
