#include <iostream>
#include <ctime>

using namespace std;

/** Необходимо создать двумерный массив 5 х 5. Далее написать функцию,
 * которая заполнит его случайными числами от 30 до 60. Создать еще две функции,
 * которые находят максимальный и минимальный элементы этого двумерного массива.
**/

int get_min_int_array(int **arr, const int size_x, const int size_y) {
    int min = arr[0][0];

    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            min = (arr[i][j] < min) ? arr[i][j] : min;
        }
    }
    return min;
}

int get_max_int_array(int **arr, const int size_x, const int size_y) {
    int max = arr[0][0];

    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            max = (arr[i][j] > max) ? arr[i][j] : max;
        }
    }
    return max;
}

void fill_array(int **arr, const int size_x, const int size_y, const int min, const int max) {
    srand(time(nullptr));
    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            arr[i][j] = rand() % (max - min + 1) + min;
        }
    }
}

void print_array(int **arr, const int size_x, const int size_y) {
    srand(time(nullptr));
    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }
}


int main() {
    const int SIZE_X = 5;
    const int SIZE_Y = 5;
    const int MIN = 30;
    const int MAX = 60;

    int **arr = new int *[SIZE_X];
    for (int i = 0; i < SIZE_Y; ++i) {
        arr[i] = new int[SIZE_Y];
    }

    fill_array(arr, SIZE_X, SIZE_Y, MIN, MAX);
    print_array(arr, SIZE_X, SIZE_Y);
    cout << endl;
    cout << "Minimum: " << get_min_int_array(arr, SIZE_X, SIZE_Y) << endl;
    cout << "Maximum: " << get_max_int_array(arr, SIZE_X, SIZE_Y) << endl;

    return 0;
}
