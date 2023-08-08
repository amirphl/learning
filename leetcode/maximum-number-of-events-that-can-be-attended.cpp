// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int maxEvents(vector<vector<int>> &events) {
    sort(events.begin(), events.end());
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    int m = 1e5 + 2;
    int n = events.size();
    int c = 0;
    for (int i = events[0][0], j = 0; i < m; i++) {
      for (; j < n && events[j][0] == i; j++) {
        pq.push({events[j][1], events[j][0]});
      }
      while (!pq.empty()) {
        int deadline = pq.top()[0];
        pq.pop();
        if (i <= deadline) {
          c++;
          break;
        }
      }
    }
    return c;
  }
};
