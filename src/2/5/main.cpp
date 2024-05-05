#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

// Функция для вычисления суммы элементов массива
int sumArray(const vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}

// Функция для перестановки цифр числа в порядке убывания
int rearrangeDigits(int num) {
    vector<int> digits;
    while (num > 0) {
        digits.push_back(num % 10);
        num /= 10;
    }
    sort(digits.begin(), digits.end(), greater<int>());
    int result = 0;
    for (int digit : digits) {
        result = result * 10 + digit;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "ru");

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    random_device rd;
    uniform_int_distribution<int> dist(1000, 9999);

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = dist(rd);
    }

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Вычисляем сумму элементов исходного массива
    int originalSum = sumArray(arr);
    cout << "Сумма элементов исходного массива: " << originalSum << endl;

    // Меняем местами цифры в элементах массива
    for (int& num : arr) {
        num = rearrangeDigits(num);
    }

    // Сортируем массив в порядке убывания
    sort(arr.begin(), arr.end(), greater<int>());

    // Вычисляем сумму элементов отсортированного массива
    int sortedSum = sumArray(arr);
    cout << "Сумма элементов отсортированного массива: " << sortedSum << endl;

    // Выводим элементы отсортированного массива
    cout << "Отсортированный массив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Сравниваем суммы элементов
    if (originalSum == sortedSum) {
        cout << "Сумма элементов исходного и отсортированного массивов совпадает." << endl;
    } else {
        cout << "Сумма элементов исходного и отсортированного массивов не совпадает." << endl;
    }

    return 0;
}
