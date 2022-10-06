#include <iostream>
#include <algorithm>
#include <array>

/** Создайте структуру с именем train, содержащую поля: название пункта назначения, номер поезда, время отправления.
 * Ввести данные в массив из пяти элементов типа train, упорядочить элементы по номерам поездов.
 * Добавить возможность вывода информации о поезде, номер которого введен пользователем.
 * Добавить возможность сортировки массив по пункту назначения, причем поезда с одинаковыми пунктами назначения
 * должны быть упорядочены по времени отправления
**/

using namespace std;

string gen_random_string(int len);

void print(const string &str);

void println(const string &str);

struct DepartureTime {
    int hour, min;
};

class Train {
public:
    string destination;
    int number{};
    DepartureTime time{};

    Train() = default;

    Train(string dest, int num, DepartureTime &t);

    void println() const;
};

Train::Train(string dest, int num, DepartureTime &t) {
    destination = move(dest);
    number = num;
    time = t;
}

void Train::println() const {
    string hour = to_string(time.hour);
    hour = hour.length() == 1 ? "0" + hour : hour;
    string min = to_string(time.min);
    min = min.length() == 1 ? "0" + min : min;
    printf("Train: %d destination %s on %s:%s\n",
           number,
           destination.c_str(),
           hour.c_str(),
           min.c_str());
}

using Train5 = array<Train, 5>;

void generateTrains(Train5 &trains);

void sortTrains(Train5 &trains);

void sortTrainsByDestByDepTime(Train5 &trains);

void printTrains(Train5 &trains, const string &msg);

void printTrainByNum(Train5 &trains, int num);

int main() {
    Train5 trains;
    // Генерируем случайные поезда
    generateTrains(trains);

    // Сортируем поезда по номеру
    sortTrains(trains);

    // Выводим поезда
    printTrains(trains, "Train by numbers:");

    // Выводим поезд по номеру - 1
    printTrainByNum(trains, 1);

    // Сортируем поезда по пункту назначения + время отправления
    sortTrainsByDestByDepTime(trains);

    // Выводим поезда
    printTrains(trains, "Train by destination and departure time:");
    return 0;
}

void sortTrains(Train5 &trains) {
    sort(trains.begin(), trains.end(), [](Train const &a, Train const &b) -> bool {
        return a.number < b.number;
    });
}

void sortTrainsByDestByDepTime(Train5 &trains) {
    sort(trains.begin(), trains.end(), [](Train const &a, Train const &b) -> bool {
        if (a.destination == b.destination) {
            if (a.time.hour == b.time.hour) {
                return a.time.min < b.time.min;
            } else {
                return a.time.hour < b.time.hour;
            }
        }
        return a.destination < b.destination;
    });
}

void printTrains(Train5 &trains, const string &msg) {
    println("\nmsg");
    for (const Train &train: trains) {
        train.println();
    }
}

void printTrainByNum(Train5 &trains, int num) {
    println("\nTrain:");
    for (const Train &train: trains) {
        if (train.number == num) {
            train.println();
            break;
        }
    }
}

void generateTrains(Train5 &trains) {
    srand(time(nullptr));
    int num_train = 1;
    for (auto &train: trains) {
        struct DepartureTime dt{rand() % 24, rand() % 60};
        train = *new Train(
                gen_random_string(10),
//                "Moscow", // Destination only Moscow for sort test
                num_train,
                dt
        );
        num_train++;
    }
}

string gen_random_string(const int len) {
    static const char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alpha[rand() % (sizeof(alpha) - 1)];
    }
    return tmp_s;
}

void print(const string &str) {
    cout << str;
}

void println(const string &str) {
    print(str);
    cout << endl;
}
