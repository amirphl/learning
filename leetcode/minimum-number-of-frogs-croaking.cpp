// https://leetcode.com/problems/minimum-number-of-frogs-croaking/
#include "bits/stdc++.h"
using namespace std;

class Solution {
  string croak = "croak";
  int arr[5];

public:
  int minNumberOfFrogs(string &s) {
    memset(arr, 0, sizeof(arr));
    int ans = 0, f = 0;
    bool ok = rec(s, 0, ans, f);
    if (!ok) {
      return -1;
    }
    for (int i = 0; i < 4; i++) {
      if (arr[i]) {
        return -1;
      }
    }
    return ans;
  }

  bool rec(string &s, int i, int &ans, int &f) {
    int n = s.length();
    if (n <= i) {
      return 1;
    }
    int j = 0;
    while (j < 5) {
      if (croak[j] == s[i]) {
        break;
      }
      j++;
    }
    if (j == 5) {
      return 0;
    }
    int k = 0;
    while (j + k < 5 && i + k < n && croak[j + k] == s[i + k]) {
      k++;
    }
    if (j == 0) {
      if (k == 5) {
        if (f == 0) {
          ans++;
          f++;
        }
        return rec(s, i + k, ans, f);
      }
      if (f == 0) {
        ans++;
      } else {
        f--;
      }
      arr[j + k - 1]++;
      return rec(s, i + k, ans, f);
    }
    if (arr[j - 1] == 0) {
      return 0;
    }
    arr[j - 1]--;
    arr[j + k - 1]++;
    if (j + k == 5) {
      f++;
    }
    return rec(s, i + k, ans, f);
  }
};
