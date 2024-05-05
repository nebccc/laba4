#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <random>

using namespace std;

vector<int> f1() {
    int size = 0;
    vector<int> nums;

    cin >> size;

    random_device rd;
    uniform_int_distribution<int> dist(100, 900);

    while(nums.size() != size) {
        nums.push_back(dist(rd));
    }

    for (int num : nums) cout << num << " ";

    cout << endl;

    return nums;
}

pair<int, int> f2(vector<int> nums) {
    int A = 0;
    cin >> A;

    int count = 0;
    for (int num : nums) {
        if (num > A) {
            count++;
        }
    }

    int index_max = 0;

    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] > nums[index_max]) {
            index_max = i;
        }
    }

    cout << index_max << endl;

    long long product = 1;

    for(int i = index_max + 1; i < nums.size(); i++) {
        product *= nums[i];
    }

    cout << count << endl;
    cout << product << endl;

    return make_pair(count, product);

}

void f3(vector<int> nums) {
    for (int i = 0; i < nums.size() - 1; i += 2) {
        if (i % 2 == 0 && (nums[i] % 100) / 10 > nums[i] / 100) {
            swap(nums[i], nums[i + 1]);
        }
    }

    for (int num : nums) {
        cout << num << " ";
     }

     cout << endl;
}

void f4() {
    int size = 0;
    vector<int> arr;

    cin >> size;

    random_device rd;
    uniform_int_distribution<int> dist(10, 20);

    while(arr.size() != size) {
        arr.push_back(dist(rd));
    }

    vector<int> frequency(11, 0); // Индексы от 0 до 10 соответствуют числам от 10 до 20

    for (int num : arr) {
        frequency[num - 10]++; // Увеличиваем счётчик для соответствующего числа
    }

    int maxFreqIndex = 0;
    for (int i = 1; i < frequency.size(); ++i) {
        if (frequency[i] > frequency[maxFreqIndex]) {
            maxFreqIndex = i;
        }
    }

    int mostRepeatedNumber = maxFreqIndex + 10; 

    for(int num : arr) {
        cout << num << " ";
    }

    cout << endl;

    cout << mostRepeatedNumber;
}



int main() {
    vector<int> nums = f1();

    int count, product;
    tie(count, product) = f2(nums);

    f3(nums);
    f4();
}