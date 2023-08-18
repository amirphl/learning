// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<int> minOperations(string &boxes) {
    int n = boxes.length();
    int arr[n][2];
    arr[0][0] = 0;
    arr[0][1] = 0;
    for (int i = 1; i < n; i++) {
      arr[i][0] = arr[i - 1][0];
      arr[i][1] = arr[i - 1][1] + arr[i - 1][0];
      if (boxes[i - 1] == '1') {
        arr[i][0]++;
        arr[i][1]++;
      }
    }
    vector<int> res(n);
    int suffix_num = 0;
    int suffix_sum = 0;
    res[n - 1] = arr[n - 1][1] + suffix_sum;
    for (int i = n - 2; i >= 0; i--) {
      // cout << i << " " << arr[i][0] << " " << arr[i][1] << " " << suffix_sum
      // << " " << suffix_num << endl;
      suffix_sum += suffix_num;
      if (boxes[i + 1] == '1') {
        suffix_num++;
        suffix_sum++;
      }
      res[i] = arr[i][1] + suffix_sum;
    }
    return res;
  }
};
