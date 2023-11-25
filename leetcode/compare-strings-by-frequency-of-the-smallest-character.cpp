// https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/
#include "bits/stdc++.h"
#include <algorithm>
using namespace std;

const int M = 2000;
const int N = 26;
int freq[N];
int wpre[M];
int qpre[M];
class Solution {
public:
  vector<int> numSmallerByFrequency(vector<string> &queries,
                                    vector<string> &words) {
    memset(wpre, 0, sizeof(wpre));
    memset(qpre, 0, sizeof(qpre));
    const int n = queries.size();
    const int m = words.size();
    vector<int> res(n, 0);
    int i = 0, j;
    for (auto &w : words) {
      memset(freq, 0, sizeof(freq));
      for (auto &c : w) {
        freq[c - 'a']++;
      }
      wpre[i] = 0;
      for (int k = 0; k < N; k++) {
        if (freq[k] != 0) {
          wpre[i] = freq[k];
          break;
        }
      }
      i++;
    }
    sort(wpre, wpre + m);
    i = 0;
    for (auto &q : queries) {
      memset(freq, 0, sizeof(freq));
      for (auto &c : q) {
        freq[c - 'a']++;
      }
      qpre[i] = 0;
      for (int k = 0; k < N; k++) {
        if (freq[k] != 0) {
          qpre[i] = freq[k];
          break;
        }
      }
      i++;
    }
    for (i = 0; i < n; i++) {
      res[i] += m - (upper_bound(wpre, wpre + m, qpre[i]) - wpre);
    }
    return res;
  }
};
