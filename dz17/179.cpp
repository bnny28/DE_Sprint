#include <iostream>
#include <algorithm>
#include <array>

/** Создайте структуру с именем Student, содержащую поля: фамилия и инициалы, номер группы,
 * успеваемость (массив из пяти элементов). Создать массив из десяти элементов такого типа,
 * упорядочить записи по возрастанию среднего балла. Добавить возможность вывода фамилий и номеров групп студентов,
 * имеющих оценки, равные только 4 или 5.
**/

using namespace std;
using Ints5 = array<int, 5>;

string gen_random_string(int len);

void print(const string &str);

void println(const string &str);

class Student {
public:
    string surname;
    string initials;
    int num_group{};
    Ints5 marks{};
    float avg_mark{};

    Student() = default;

    Student(string surName, string inits, int numGroup, Ints5 &marks);

    bool isGoodMarks();

    void println() const;
};

Student::Student(string surName, string inits, int numGroup, Ints5 &marks) {
    surname = move(surName);
    initials = move(inits);
    num_group = numGroup;
    this->marks = marks;
    float tmp = 0;
    for (int i = 0; i < 5; i++) {
        tmp += (float) this->marks[i];
    }
    avg_mark = tmp / 5;
}

void Student::println() const {
    printf("Student: %s %s, group: %d, average mark: %.2f\n",
           surname.c_str(),
           initials.c_str(),
           num_group,
           avg_mark);
}

bool Student::isGoodMarks() {
    for (int i = 0; i < 5; i++) {
        if (marks[i] != 4 and marks[i] != 5) {
            return false;
        }
    }
    return true;
}

using Students10 = array<Student, 10>;

void generateStudents(Students10 &students);

void printSortStudents(Students10 &students);

void printGoodStudents(Students10 &students);

int main() {
    Students10 students;

    // Генерируем случайных студентов
    generateStudents(students);

    // Выводим студентов отсортированных по среднему баллу
    printSortStudents(students);

    // Выводим только хороших студентов
    printGoodStudents(students);
    return 0;
}

void printGoodStudents(Students10 &students) {
    bool is_good = false;
    for (Student student: students) {
        if (student.isGoodMarks()) {
            if (!is_good) println("\nGood students:");
            student.println();
            is_good = true;
        }
    }
    if (!is_good) println("\nThere are no good students");
}

void printSortStudents(Students10 &students) {
    println("\nAll students sort by average mark:");
    sort(students.begin(), students.end(), [](Student const &a, Student const &b) -> bool {
        return a.avg_mark < b.avg_mark;
    });
    for (const Student &student: students) {
        student.println();
    }
}

void generateStudents(Students10 &students) {
    srand(time(nullptr));
    for (auto &student: students) {
        Ints5 marks;
        for (auto &mark: marks) {
            mark = rand() % 5 + 1;
//            mark = rand() % 2 + 4; // only good students with marks 4 and 5
        }
        student = *new Student(
                gen_random_string(10),
                gen_random_string(2),
                rand() % 4 + 1,
                marks
        );
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
