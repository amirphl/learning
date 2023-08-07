// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  string minRemoveToMakeValid(string in) {
    int n = in.length();
    int c = 0;
    int d = 0;

    for (int i = 0; i < n; i++) {
      if (in[i] == '(') {
        c++;
      } else if (in[i] == ')') {
        c--;
        if (c < 0) {
          in[i] = '0';
          d++;
          c = 0;
        }
      }
    }

    int c2 = 0;

    for (int i = n - 1; i >= 0 && c2 < c; i--) {
      if (in[i] == '(') {
        c2++;
        if (c2 > 0) {
          in[i] = '0';
          d++;
          c2 = 0;
        }
      } else if (in[i] == ')') {
        c2--;
      }
    }

    int res_len = n - d;
    string res(res_len, ' ');

    for (int i = 0, j = 0; i < n; i++) {
      if (in[i] == '0') {
        continue;
      }

      res[j++] = in[i];
    }

    return res;
  }
};

int main() {
  string in(
      "lee(t(c)o)de))(((dfg))))(((djfhd)))((())))(fhdfdhf))(((((((((er78df))((("
      "(djfhdjf(((((()))))sdfhjdkfhd(((((((dfjkdfdf(djfhdjfh)(");
  Solution sol;
  cout << sol.minRemoveToMakeValid(in) << "\n";

  return 0;
}
