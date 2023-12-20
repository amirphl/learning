// https://leetcode.com/problems/3sum-with-multiplicity/
#include "bits/stdc++.h"
using namespace std;

int MOD = 1e9 + 7;

class Solution {
public:
  int threeSumMulti(vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int pairs = 0;
    int temp;
    for (int k = 1; k < n - 1; k++) {
      for (int i = 0, j = n - 1; i < k && k < j;) {
        temp = arr[i] + arr[k] + arr[j];
        if (temp < target) {
          i++;
        } else if (temp == target) {
          int x = i, y = j;
          while (x < k && arr[i] == arr[x]) {
            x++;
          }
          while (k < y && arr[j] == arr[y]) {
            y--;
          }
          pairs = (pairs + (((x - i) * (j - y)) % MOD)) % MOD;
          i = x;
          j = y;
        } else {
          j--;
        }
      }
    }
    return pairs;
  }
};
