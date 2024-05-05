#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Пример 1: Случайный выбор
bool randomStrategy(int round_number, vector<bool>& self_choices, vector<bool>& enemy_choices) {
    return rand() % 2 == 0; // Вернуть true или false случайным образом
}

// Пример 2: Всегда сотрудничать
bool alwaysCooperate(int round_number, vector<bool>& self_choices, vector<bool>& enemy_choices) {
    return true;
}

// Пример 3: Всегда предавать
bool alwaysBetray(int round_number, vector<bool>& self_choices, vector<bool>& enemy_choices) {
    return false;
}

// Имитация игры
void playGame(int rounds, bool (*strategy1)(int, vector<bool>&, vector<bool>&), bool (*strategy2)(int, vector<bool>&, vector<bool>&)) {
    vector<bool> choices1, choices2;
    int score1 = 0, score2 = 0;

    for (int i = 0; i < rounds; ++i) {
        bool choice1 = strategy1(i, choices1, choices2);
        bool choice2 = strategy2(i, choices2, choices1);

        choices1.push_back(choice1);
        choices2.push_back(choice2);

        if (choice1 && choice2) {
            score1 += 24;
            score2 += 24;
        } else if (choice1 && !choice2) {
            score1 += 0;
            score2 += 20;
        } else if (!choice1 && choice2) {
            score1 += 20;
            score2 += 0;
        } else {
            score1 += 4;
            score2 += 4;
        }
    }

    cout << "Результат игры:" << endl;
    cout << "Игрок 1: " << score1 << " очков" << endl;
    cout << "Игрок 2: " << score2 << " очков" << endl;
}

// Пример использования
int main() {
    setlocale(LC_ALL, "ru");

    srand(time(nullptr)); // Инициализация генератора случайных чисел

    // Пример запуска игры
    playGame(150, randomStrategy, alwaysBetray);

    return 0;
}
