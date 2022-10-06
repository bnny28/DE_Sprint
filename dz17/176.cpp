#include <iostream>
#include <regex>

using namespace std;

/** Написать программу, которая определяет максимальное число из введённой с клавиатуры
 * последовательности положительных чисел. (длина последовательности неограниченна)
 **/

int main() {
    int x;
    string num;
    bool is_valid;
    int max = 0;

    regex regex_pattern("[0-9]+");

    do
    {
        cout << "input positive integer number (if not - exit):" << endl;
        cin >> num;
        is_valid = regex_match(num, regex_pattern);
        if (!is_valid) {
            break;
        }
        x = stoi(num);
        max = (x < max) ? max : x;

    } while (true);

    cout << "Maximum:" << max << endl;
    return 0;
}
