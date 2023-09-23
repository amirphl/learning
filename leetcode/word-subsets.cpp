// https://leetcode.com/problems/word-subsets/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  // TLE
  vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
    queue<pair<string, int>> q;
    int i = 0;
    for (auto w : words1) {
      sort(w.begin(), w.end());
      q.push({w, i});
      i++;
    }
    for (auto &w : words2) {
      sort(w.begin(), w.end());
    }
    q.push({"", -1});
    for (auto &w2 : words2) {
      int n = w2.length();
      while (q.front().first != "") {
        string w1 = q.front().first;
        int i = 0;
        int j = 0;
        int m = w1.length();
        while (i < n && j < m) {
          if (w2[i] == w1[j]) {
            i++;
            j++;
          } else if (w2[i] < w1[j]) {
            break;
          } else {
            j++;
          }
        }
        if (i == n) {
          q.push(q.front());
        }
        q.pop();
      }
      q.pop();
      q.push({"", -1});
      if (q.size() == 1) {
        break;
      }
    }
    vector<string> res(q.size() - 1);
    i = 0;
    while (q.size() > 1) {
      res[i] = words1[q.front().second];
      i++;
      q.pop();
    }
    return res;
  }
};
