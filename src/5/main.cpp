#include <iostream>
#include <vector>
#include <algorithm>

void initialize(int S[], const std::vector<int>& key) {
    // Инициализация таблицы замен S
    for (int i = 0; i < 256; ++i)
        S[i] = i;
    
    // Перемешивание таблицы замен S
    int j = 0;
    for (int i = 0; i < 256; ++i) {
        j = (j + S[i] + key[i % key.size()]) % 256;
        std::swap(S[i], S[j]);
    }
}

int generate(int S[], int& i, int& j) {
    // Генерация псевдослучайного числа
    i = (i + 1) % 256;
    j = (j + S[i]) % 256;
    std::swap(S[i], S[j]);
    int t = (S[i] + S[j]) % 256;
    return S[t];
}

int main() {
    // Пример использования
    std::vector<int> key = {1, 2, 3, 4, 5}; // Пример ключа
    int S[256];
    initialize(S, key);
    
    int i = 0, j = 0;
    for (int k = 0; k < 10; ++k) {
        std::cout << generate(S, i, j) << " ";
    }
    std::cout << std::endl;
    return 0;
}
