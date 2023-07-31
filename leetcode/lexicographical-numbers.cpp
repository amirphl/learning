// https://leetcode.com/problems/lexicographical-numbers/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<int> lexicalOrder(int n) {
    vector<int> res(n);
    int pos = 0;
    for (int i = 1; i < 10; i++) {
      if (i <= n && pos < n) {
        res[pos] = i;
        pos++;
      }
      rec(i, pos, n, res);
    }
    return res;
  }

  void rec(int curr, int &pos, const int n, vector<int> &res) {

    for (int i = 0; i < 10; i++) {
      int j = 10 * curr + i;
      if (j <= n && pos < n) {
        res[pos] = j;
        pos++;
        rec(j, pos, n, res);
      } else {
        break;
      }
    }
  }
};

int main() {
  int n = 200;
  vector<int> res = Solution().lexicalOrder(n);
  for (auto &x : res) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
