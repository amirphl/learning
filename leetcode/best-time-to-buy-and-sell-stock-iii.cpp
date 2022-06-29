// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // time: O(n), memory: O(n)
    int maxProfit(vector<int>& p) {
        int n = p.size();
        int** dp = new int*[n + 1];
        int i = 0;
        while(i < n + 1) {
            dp[i] = new int[4];
            dp[i][0] = -1;
            dp[i][1] = -1;
            dp[i][2] = -1;
            dp[i][3] = -1;
            i++;
        }
        dp[n][0] = 0;
        dp[n][0] = 0;
        dp[n][0] = 0;
        dp[n][0] = 0;
        find(0, 0, p, dp);
        find(0, 2, p, dp);
        int res = max({dp[0][0], dp[0][2], 0});
        i = 0;
        while(i < n + 1) {
            delete [] dp[i];
            i++;
        }
        delete [] dp;
        return res;
    }

    void find(int idx, int opt, vector<int>& p, int** dp) {
        if (p.size() <= idx || dp[idx][opt] != -1) {
            return;
        }
        int m1, m2;
        if (opt == 3) {
            m1 = p[idx];
            find(idx + 1, opt, p, dp);
            m2 = dp[idx + 1][opt];
        } else {
            find(idx + 1, opt + 1, p, dp);
            m1 = (opt % 2 == 0 ? -1 : 1) * p[idx] + dp[idx + 1][opt + 1];
            find(idx + 1, opt, p, dp);
            m2 = dp[idx + 1][opt];
        }
        dp[idx][opt] = max(m1, m2);
    }
};

int main() {
    vector<int> prices = {3,3,5,0,0,3,1,4};
    Solution sol;
    cout << sol.maxProfit(prices);
    cout << endl;
    return 0;
}
