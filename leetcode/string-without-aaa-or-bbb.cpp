// https://leetcode.com/problems/string-without-aaa-or-bbb/description/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  string strWithout3a3b(int a, int b) {
    string str(a + b, ' ');
    list<char> li;
    const char A = a > b ? 'b' : 'a';
    const char B = a > b ? 'a' : 'b';
    if (a > b) {
      int temp = a;
      a = b;
      b = temp;
    }
    while (b) {
      li.push_back(B);
      b--;
      if (b) {
        li.push_back(B);
        b--;
      }
      if (a) {
        li.push_back(A);
        a--;
      }
    }
    auto it = li.begin();
    if (a) {
      li.insert(it, A);
      a--;
      if (a) {
        li.insert(it, A);
        a--;
      }
    }
    while (a) {
      if (*it == A) {
        li.insert(it, A);
        a--;
        it++;
      } else {
        it++;
        li.insert(it, A);
        a--;
        if (a) {
          li.insert(it, A);
          a--;
        }
        it++;
      }
    }
    int i = 0;
    for (auto &c : li) {
      str[i++] = c;
    }
    return str;
  }
};

int main() {
  int a, b;
  cin >> a >> b;
  Solution sol;
  cout << sol.strWithout3a3b(a, b) << endl;

  return 0;
}
