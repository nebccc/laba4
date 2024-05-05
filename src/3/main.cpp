#include <chrono>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <random>
#include <vector>

#define s1 50
#define s2 100
#define s3 1000
#define interval 5.

using namespace std;

vector<int> init(int size);
double chi_sqr(vector<int> arr);

int main() {
  cout << "50 nums: " << chi_sqr(init(s1)) << endl;
  cout << "100 nums: " << chi_sqr(init(s2)) << endl;
  cout << "1000 nums: " << chi_sqr(init(s3)) << endl;
  return 0;
}

double chi_sqr(vector<int> arr) {
  double chi_sqr = 0.;
  size_t size = arr.size();
  double Vexp = size / interval;

  vector<int> elements(interval, 0);

  for (auto el : arr)
    elements[int(el * interval / 101)]++;

  for (auto Vn : elements)
    chi_sqr += pow(Vn - Vexp, 2) / Vexp;

  return chi_sqr;
}

vector<int> init(int size) {
  vector<int> arr;

  random_device rd;
  uniform_int_distribution<int> dist(1, 100);

  while (arr.size() != size) {
    arr.push_back(dist(rd));
  }

  return arr;
}
