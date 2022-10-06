#include <iostream>

using namespace std;

/** Написать программу, которая выводит таблицу значений функции y=-2 * x^2 - 5 * x - 8
 * в диапазоне от –4 до +4, с шагом 0,5
**/

int main() {
    cout << "Solve equation y=-2*x^2-5*x-8 from –4 to +4, step 0,5:" << endl;
    float x = -4;

    do {
        cout << -2 * x * x - 5 * x - 8 << endl;
        x += 0.5;
    } while (x <= 4);

    return 0;
}
