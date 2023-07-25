// https://leetcode.com/problems/multiply-strings/
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) { return rec(num1, num2, 0); }
  string rec(string num1, string num2, int tens) {
    int m = num2.length();

    if (m == 1) {
      return prune_lead(mul(num1, num2[0])) + string(tens, '0');
    }

    return prune_lead(plus(rec(num1, num2.substr(0, m - 1), 1),
                           mul(num1, num2[m - 1]))) +
           string(tens, '0');
  }

  string mul(string num, char ch) {
    int n = num.length();
    string res(n + 1, '0');
    int c = 0;

    for (int i = n - 1, j = n; i >= 0; i--, j--) {
      int t = (ch - '0') * (num[i] - '0') + c;
      res[j] = (t % 10) + '0';
      c = t / 10;
    }
    if (c) {
      res[0] = c + '0';
    }
    return prune_lead(res);
  }

  string plus(string num1, string num2) {
    int n = num1.size();
    int m = num2.size();
    int p = max(n, m);
    string res(p + 1, '0');
    int i = n - 1, j = m - 1, k = p;
    int c = 0;

    while (i >= 0 || j >= 0) {
      int t = (i >= 0 ? num1[i] - '0' : 0) + (j >= 0 ? num2[j] - '0' : 0) + c;
      res[k] = (t % 10) + '0';
      c = t / 10;
      i--;
      j--;
      k--;
    }
    if (c)
      res[0] = c + '0';
    return prune_lead(res);
  }

  string prune_lead(string num) {
    int n = num.length();
    int i = 0;
    for (; i < n; i++) {
      if (num[i] != '0') {
        break;
      }
    }
    string res = num.substr(i, n - i);
    return res == "" ? "0" : res;
  }
};

int main() {
  string num1 = "003894673865";
  string num2 = "0003847004384001";
  Solution sol;
  cout << sol.multiply(num1, num2) << endl;
}
