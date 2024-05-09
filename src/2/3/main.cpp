#include <iostream>
#include <vector>
#include <random>

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

int main() {
    vector<int> nums = f1();

    for (int num : nums) {
        cout << num << " ";
    }

     cout << endl;

    f3(nums);
}