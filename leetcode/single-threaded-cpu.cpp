// https://leetcode.com/problems/single-threaded-cpu/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<int> getOrder(vector<vector<int>> &tasks) {
    int n = tasks.size();
    for (int i = 0; i < n; i++) {
      tasks[i].push_back(i);
    }
    sort(tasks.begin(), tasks.end());
    auto cmp = [](const vector<int> &x, const vector<int> &y) {
      return x[1] > y[1] || (x[1] == y[1] && x[2] > y[2]);
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
    vector<int> res(n);
    int i = 0, j = 0;
    for (; i < n;) {
      int enqueue_time = tasks[i][0];
      int duration = tasks[i][1];
      uint64_t base_time = enqueue_time;
      int index;
      for (; i < n && tasks[i][0] == enqueue_time; i++) {
        pq.push(tasks[i]);
      }
      while (!pq.empty()) {
        enqueue_time = pq.top()[0];
        duration = pq.top()[1];
        index = pq.top()[2];
        // cout << enqueue_time << " " << duration << " " << index << "\n";
        pq.pop();
        res[j++] = index;
        base_time += duration;
        for (; i < n && tasks[i][0] <= base_time; i++) {
          pq.push(tasks[i]);
        }
      }
    }
    return res;
  };
};
