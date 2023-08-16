// https://leetcode.com/problems/most-popular-video-creator/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<vector<string>> mostPopularCreator(vector<string> &creators,
                                            vector<string> &ids,
                                            vector<int> &views) {
    unordered_map<string, pair<int64_t, pair<string, int>>> m;
    int n = creators.size();
    int64_t highest = INT_MIN;
    for (int i = 0; i < n; i++) {
      if (m.find(creators[i]) == m.end()) {
        m[creators[i]] = {0, {"", INT_MIN}};
      }
      m[creators[i]].first += views[i];
      if (m[creators[i]].second.second < views[i] ||
          (m[creators[i]].second.second == views[i] &&
           m[creators[i]].second.first > ids[i])) {
        m[creators[i]].second = {ids[i], views[i]};
      }
      if (highest < m[creators[i]].first) {
        highest = m[creators[i]].first;
      }
    }
    vector<vector<string>> res;
    for (auto it = m.begin(); it != m.end(); it++) {
      if ((it->second).first == highest) {
        res.push_back({it->first, it->second.second.first});
      }
    }
    return res;
  }
};
