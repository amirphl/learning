// https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  int seat;
  long long minimumFuelCost(vector<vector<int>> &edges, const int seat) {
    this->seat = seat;
    int n = edges.size() + 1;
    vector<vector<int>> adj(n, vector<int>());

    for (auto &e : edges) {
      int src = e[0];
      int dst = e[1];
      adj[src].push_back(dst);
      adj[dst].push_back(src);
    }

    uint64_t full = 0, partial = 0, fuel = 0;
    rec(-1, 0, full, partial, fuel, adj);
    return fuel;
  }

  void rec(int root, int node, uint64_t &full, uint64_t &partial,
           uint64_t &fuel, vector<vector<int>> &adj) {
    for (auto &neighbor : adj[node]) {
      if (neighbor == root) {
        continue;
      }
      uint64_t m_full = 0, m_partial = 0, m_fuel = 0;
      rec(node, neighbor, m_full, m_partial, m_fuel, adj);
      full += m_full;
      partial += m_partial;
      fuel += m_fuel + m_full + (m_partial ? 1 : 0);
    }

    partial++;
    full += partial / seat;
    partial = partial % seat;
    // cout << node << "-->" << root << " fuel:" << fuel << " full:" << full
    // << " partial:" << partial << endl;
  }
};
