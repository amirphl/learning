// https://leetcode.com/problems/maximum-star-sum-of-a-graph/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int maxStarSum(vector<int> &vals, vector<vector<int>> &edges, int k) {
    if (k == 0) {
      return *max_element(vals.begin(), vals.end());
    }

    int n = vals.size();
    vector<priority_queue<int, vector<int>, greater<int>>> adj(
        n, priority_queue<int, vector<int>, greater<int>>());
    vector<int> cost = vals;

    for (auto &e : edges) {
      int src = e[0];
      int dst = e[1];
      f(src, dst, k, adj, cost, vals);
      f(dst, src, k, adj, cost, vals);
    }
    // for(auto& x: cost) {
    //   cout << x << " ";
    // }

    return *max_element(cost.begin(), cost.end());
  }

  void f(const int src, const int dst, const int k,
         vector<priority_queue<int, vector<int>, greater<int>>> &adj,
         vector<int> &cost, const vector<int> &vals) {
    int v = vals[dst];
    if (v > 0 && (adj[src].size() < k || v > adj[src].top())) {
      if (adj[src].size() == k) {
        cost[src] -= adj[src].top();
        adj[src].pop();
      }
      adj[src].push(v);
      cost[src] += v;
    }
  }
};
