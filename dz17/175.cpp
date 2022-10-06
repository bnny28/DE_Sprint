#include <iostream>
#include <regex>

using namespace std;

/** Написать программу, которая выводит таблицу квадратов десяти первых положительных чисел. **/

int main() {
    for (int i = 1; i < 11; i++) {
        cout << (i * i) << endl;
    }
    return 0;
}
