// https://leetcode.com/problems/word-subsets/
#include "bits/stdc++.h"
using namespace std;

int freq[26];
int temp[26];
class Solution {
public:
  vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
    memset(freq, 0, sizeof(freq));
    memset(temp, 0, sizeof(temp));
    for (auto &w : words2) {
      for (auto &c : w) {
        temp[c - 'a']++;
      }
      for (int i = 0; i < 26; i++) {
        freq[i] = max(freq[i], temp[i]);
        temp[i] = 0;
      }
    }
    int c = 0;
    for (int j = 0; j < words1.size(); j++) {
      memset(temp, 0, sizeof(temp));
      for (auto &c : words1[j]) {
        temp[c - 'a']++;
      }
      int i = 0;
      for (; i < 26 && temp[i] >= freq[i]; i++)
        ;
      if (i != 26) {
        words1[j] = "";
        c++;
      }
    }
    vector<string> res(words1.size() - c);
    for (int i = 0, j = 0; i < words1.size(); i++) {
      if (words1[i] != "") {
        res[j++] = words1[i];
      }
    }
    return res;
  }
};
