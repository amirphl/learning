// https://leetcode.com/problems/generate-parentheses/
#include "bits/stdc++.h"
using namespace std;

vector<vector<string> *> dp(9, 0);
class Solution {
public:
  vector<string> generateParenthesis(int n) { return *rec(n); }

  vector<string> *rec(int n) {
    if (dp[n] != 0) {
      return dp[n];
    }
    if (n == 0) {
      vector<string> *ans = new vector<string>(1);
      ans->at(0) = "";
      return dp[0] = ans;
    }
    if (n == 1) {
      vector<string> *ans = new vector<string>(1);
      ans->at(0) = "()";
      return dp[1] = ans;
    }
    vector<string> *ans = new vector<string>();
    for (int i = 0; i < n; i++) {
      vector<string> *left_sub = rec(i);
      vector<string> *right_sub = rec(n - i - 1);
      for (int i = 0; i < left_sub->size(); i++) {
        for (int j = 0; j < right_sub->size(); j++) {
          ans->push_back("(" + left_sub->at(i) + ")" + right_sub->at(j));
        }
      }
    }
    return dp[n] = ans;
  }
};
