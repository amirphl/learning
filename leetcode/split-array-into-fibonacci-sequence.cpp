// https://leetcode.com/problems/split-array-into-fibonacci-sequence/
#include "bits/stdc++.h"
#include <string>
using namespace std;

class Solution {

public:
  vector<int> splitIntoFibonacci(string num) {
    int n = num.length();
    vector<int> res(200);

    for (int i = 0; i < n - 2 && i + 1 <= 10; i++) {
      string s0 = num.substr(0, i + 1);

      if (s0.length() == 10 && "2147483647" < s0) {
        break;
      }

      int f0 = stoi(s0);

      for (int j = i + 1; j < n - 1 && j - i <= 10; j++) {
        string s1 = num.substr(i + 1, j - i);

        if (s1.length() == 10 && "2147483647" < s1) {
          break;
        }

        int f1 = stoi(s1);
        int curr = 0;

        if (rec(num, j + 1, f0, f1, res, curr) && 2 < curr) {
          return vector<int>(res.begin(), res.begin() + curr);
        }

        if (num[i + 1] == '0') {
          break;
        }
      }

      if (num[0] == '0') {
        break;
      }
    }

    return {};
  }

  bool rec(string &num, const int index, const int f0, const int f1,
           vector<int> &res, int &curr) {
    int n = num.length();

    if (n <= index) {
      res[curr++] = f0;
      res[curr++] = f1;
      return 1;
    }

    if (INT_MAX < (uint64_t)f0 + f1) {
      return 0;
    }

    const int f2 = f0 + f1;

    if (num[index] == '0') {
      if (f2 == 0) {
        res[curr++] = f0;
        return rec(num, index + 1, f1, f2, res, curr);
      }
      return 0;
    }

    if (f2 == 0) {
      if (num[index] == '0') {
        res[curr++] = f0;
        return rec(num, index + 1, f1, f2, res, curr);
      }
      return 0;
    }

    const int m = log10(f2);
    int temp = f2;
    int digits = m;

    if (n <= index + m) {
      return 0;
    }

    while (temp) {
      if (temp % 10 == num[index + digits--] - '0') {
        temp /= 10;
      } else {
        return 0;
      }
    }

    res[curr++] = f0;
    return rec(num, index + m + 1, f1, f2, res, curr);
  }
};

int main() {
  Solution sol;
  vector<string> inputs = {
      "1101111", "112358130", "0123", "112358132134",
      "112358132134112358132134112358132134112358132134112358132134112358132134"
      "112358132134112358132134112358132134112358132134112358132134112358132134"
      "112358132134112358132134112358132134112358132134112358132134112358132134"
      "112358132134112358132134"};

  for (auto &s : inputs) {
    vector<int> res = sol.splitIntoFibonacci(s);
    for (auto &x : res) {
      cout << x << " ";
    }
    cout << "\n";
  }

  return 0;
}
