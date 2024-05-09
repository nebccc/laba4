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

int main() {
    vector<int> nums = f1();

    for (int num : nums) cout << num << " ";

    cout << endl;

    return 0;
}