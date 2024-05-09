#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

int rn() {
    random_device rd;
    uniform_int_distribution<int> dist(100, 900);
    return dist(rd);
}

vector<int> f1() {
    int size = 0;
    vector<int> nums;
    cin >> size;
    while(nums.size() != size) {
        nums.push_back(rn());
    }
    return nums;
}

void f2(vector<int> nums) {
    int A;

    cout << "Введите число A: ";
    cin >> A;

    int count_greater_than_A = 0;
    for (int num : nums) {
        if (num > A) {
            count_greater_than_A++;
        }
    }

    cout << "Количество элементов больше A: " << count_greater_than_A << endl;

    int max_abs_index = max_element(nums.begin(), nums.end(), [](int a, int b) {
        return abs(a) < abs(b);
    }) - nums.begin();

    long long product_after_max_abs = 1;
    for (size_t i = max_abs_index + 1; i < nums.size(); ++i) {
        product_after_max_abs *= nums[i];
    }
    cout << "Произведение элементов после максимального по модулю: " << product_after_max_abs << endl;
}

int main() {
    vector<int> nums = f1();

    for (int num : nums) cout << num << " ";

    cout << endl;

    f2(nums);

    return 0;
}