// https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/
#include "bits/stdc++.h";

using namespace std;

class Solution {
public:
  string robotWithString(string in) {
    int n = in.length();
    int f[n][26];
    memset(f, 0, sizeof(f));
    f[n - 1][in[n - 1] - 'a']++;

    for (int i = n - 2; i >= 0; i--) {
      for (int j = 0; j < 26; j++) {
        f[i][j] = f[i + 1][j];
      }
      f[i][in[i] - 'a']++;
    }

    stack<char> s;
    string out(n, ' ');
    int i = 0, j = 0;

    for (char ch = 'a'; ch <= 'z'; ch++) {
      while (!s.empty() && (s.top() <= ch)) {
        out[j++] = s.top();
        s.pop();
      }
      while (i < n && f[i][ch - 'a'] > 0) {
        if (in[i] == ch) {
          out[j++] = ch;
        } else {
          s.push(in[i]);
        }
        i++;
      }
    }

    while (!s.empty()) {
      out[j++] = s.top();
      s.pop();
    }

    return out;
  }
};
