// https://leetcode.com/problems/nth-digit/

#include "bits/stdc++.h"
#include <algorithm>
using namespace std;

const int N = 11;
uint64_t arr[N];
uint64_t brr[N];
class Solution {
public:
  int findNthDigit(int n) {
    arr[0] = 9;
    brr[0] = 9;
    for (int i = 1; i < N; i++) {
      arr[i] = 10 * arr[i - 1];
      brr[i] = brr[i - 1] + (i + 1) * arr[i];
    }
    int index = lower_bound(brr, brr + N, n) - brr;
    // cout << index << endl;
    if (index > 0) {
      n -= brr[index - 1];
    }
    // cout << " n " << n << endl;
    n--;
    // cout << " n " << n << endl;
    int m = index - (n % (index + 1));
    // cout << " m " << m << endl;
    n /= (index + 1);
    // cout << " n " << n << endl;
    int x = pow(10, index) + n;
    // cout << " x " << x << endl;
    while (m) {
      x /= 10;
      m--;
    }
    return x % 10;
  }
};
