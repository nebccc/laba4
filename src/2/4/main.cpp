#include <iostream>
#include <vector>
#include <map>
#include <random>

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(10, 20);

    int n = 15; // или другое значение n
    vector<int> arr(n);

    // Заполняем массив случайными числами
    for (int i = 0; i < n; ++i) {
        arr[i] = dis(gen);
    }

    // Выводим массив на экран
    cout << "Массив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Подсчитываем количество вхождений каждого числа
    map<int, int> count;
    for (int num : arr) {
        count[num]++;
    }

    // Находим число, которое встречается наибольшее количество раз
    int max_count = 0;
    int most_frequent_num = 0;
    for (const auto& pair : count) {
        if (pair.second > max_count) {
            max_count = pair.second;
            most_frequent_num = pair.first;
        }
    }

    // Выводим результат
    cout << "Наиболее часто встречающееся число: " << most_frequent_num
         << " (встречается " << max_count << " раз)" << endl;

    return 0;
}