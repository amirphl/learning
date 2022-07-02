// https://leetcode.com/problems/split-array-largest-sum/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // time: O(n*m), memory: O(n*m)
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp(n);
        vector<int> prefix(n);
        prefix[0] = nums[0];
        int i = 0;
        while(i < n) {
            dp[i] = vector<int>(m, -1);
            if (0 < i) {
                prefix[i] = prefix[i - 1] + nums[i];
            }
            i++;
        }
        fill(0, m - 1, n, m, nums, prefix, dp);
        return dp[0][m - 1];
    }

    void fill(int i, int j, int n, int m, vector<int>& nums, vector<int>& prefix, vector<vector<int>>& dp) {
        // cout << i << " " << j << endl;
        if (n <= i || m <= j || dp[i][j] != -1) {
            return;
        }
        if (j == 0) {
            dp[i][j] = prefix[n - 1] - prefix[i] + nums[i];
            return;
        }
        int k = i, sum = 0, res = INT_MAX;
        while(i < n - j) {
            sum += nums[i];
            fill(i + 1, j - 1, n, m, nums, prefix, dp);
            res = min(res, max(sum, dp[i + 1][j - 1]));
            i++;
        }
        dp[k][j] = res;
        // cout << k << " " << j << " " << dp[k][j] << endl;
    }
};

int main() {
    vector<int> nums = {7,2,5,10,8};
    int m = 2;
    Solution sol;
    cout << sol.splitArray(nums, m);
    cout << endl;
    return 0;
}
