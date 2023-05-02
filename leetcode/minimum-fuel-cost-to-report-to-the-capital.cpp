// https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital

class Solution {
public:
    const int ROOT = 0;
    int seat;
    long long minimumFuelCost(vector<vector<int>>& r, const int seat) {
        this -> seat = seat;
        int e = r.size();
        int n = e + 1;

        vector<vector<int>> adj(n);

        int u, v;
        for(auto& edge: r) {
            u = edge[0];
            v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int64_t carry = 0, res = 0;
        rec(0, -1, carry, res, 0, adj);

        return res;
    }

    void rec(int node, int parent, int64_t& c, int64_t& res, int depth, vector<vector<int>>& adj) {
        int64_t carry = 0;
        for(auto& neighbor: adj[node]) {
            if (neighbor != parent)
                rec(neighbor, node, carry, res, depth + 1, adj);
        }

        if (node == ROOT) {
            return;
        }

        int people = 1 + carry;
        int cars = people / seat;
        res += cars * depth;

        int remained = people % seat;
        if (remained) {
            res += 1;
            c += remained;
        }
    }
};
