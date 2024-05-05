#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void initialize(int S[], const std::vector<int>& key) {
    for (int i = 0; i < 256; ++i)
        S[i] = i;
    
    int j = 0;
    for (int i = 0; i < 256; ++i) {
        j = (j + S[i] + key[i % key.size()]) % 256;
        swap(S[i], S[j]);
    }
}

int generate(int S[], int& i, int& j) {

    i = (i + 1) % 256;
    j = (j + S[i]) % 256;
    swap(S[i], S[j]);
    int t = (S[i] + S[j]) % 256;
    
    return S[t];
}

int main() {
    // Пример использования
    vector<int> key = {1, 2, 3, 4, 5}; // Пример ключа
    int S[256];
    initialize(S, key);
    
    int i = 0, j = 0;
    for (int k = 0; k < 10; ++k) {
        cout << generate(S, i, j) << " ";
    }
    cout << endl;
    return 0;
}
