// https://leetcode.com/problems/freedom-trail/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // time: O(n*m), memory: O(n)
    int findRotateSteps(string ring, string key) {
        int n = ring.length(), m = key.length();
        vector<int> dp(n);
        unordered_map<char, vector<int>> pos;
        int i = 0;
        while(i < n) {
            pos[ring[i]].push_back(i);
            i++;
        }
        int j = m - 1;
        while(-1 < j) {
            vector<int> temp(n);
            i = 0;
            while(i < n) {
                int res = INT_MAX, a;
                for(auto& k: pos[key[j]]) {
                    a = abs(i - k);
                    res = min(res, (j == m - 1 ? 0 : dp[k]) + min(a, n - a));
                }
                temp[i] = res;
                i++;
            }
            dp = temp;
            j--;
        }
        return dp[0] + m;
    }

    // time: O(n*m), memory: O(n*m)
    int findRotateSteps3(string ring, string key) {
        int n = ring.length(), m = key.length();
        vector<vector<int>> dp(n);
        unordered_map<char, vector<int>> pos;
        int i = 0;
        while(i < n) {
            dp[i] = vector<int>(m, -1);
            pos[ring[i]].push_back(i);
            i++;
        }
        fill(0, 0, ring, key, dp, pos);
        return dp[0][0] + m;
    }

    void fill(int i, int j, string& ring, string& key, vector<vector<int>>& dp, unordered_map<char, vector<int>>& pos) {
        if (dp[i][j] != -1) {
            return;
        }
        int n = ring.length(), m = key.length();
        int res = INT_MAX;
        for(auto& k: pos[key[j]]) {
            if (j < m - 1) {
                fill(k, j + 1, ring, key, dp, pos);
            }
            int a = abs(i - k);
            res = min(res, (j == m - 1 ? 0 : dp[k][j + 1]) + min(a, n - a));
        }
        dp[i][j] = res;
    }

    // greedy
    // Doesn't work!
    // testcase:
    // "caotmcaataijjxi"
    // "oatjiioicitatajtijciocjcaaxaaatmctxamacaamjjx"
    int findRotateSteps2(string ring, string key) {
        unordered_map<char, vector<int>> pos;
        int i = 0, n = ring.length();
        while(i < n) {
            pos[ring[i]].push_back(i);
            i++;
        }
        int j = 0, opt = 0, offset = 0, m = key.length();
        while(j < m) {
            int d = INT_MAX;
            int loc;
            for(auto& it: pos[key[j]]) {
                if (abs(offset - it) < d) {
                    d = abs(offset - it);
                    loc = it;
                }
                if (n - abs(offset - it) < d) {
                    d = n - abs(offset - it);
                    loc = it;
                }
            }
            // cout << offset << " " << loc << endl;
            if (d <= n / 2) {
                opt += d + 1;
            } else {
                opt += n - d + 1;
            }
            offset = loc;
            j++;
        }
        return opt;
    }
};

int main() {
    string ring = "caotmcaataijjxi";
    string key = "oatjiioicitatajtijciocjcaaxaaatmctxamacaamjjx";
    Solution sol;
    cout << sol.findRotateSteps(ring, key);
    cout << endl;
    return 0;
}
