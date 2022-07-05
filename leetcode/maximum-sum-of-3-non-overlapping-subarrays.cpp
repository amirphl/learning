// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // time: O(n), memory: O(n)
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3, -2));
        vector<vector<int>> dp2(n, vector<int>(2, -2));
        vector<int> dp3(n, -1);
        vector<int> prefix(n);
        prefix[0] = nums[0];
        int i = 1;
        while(i < n) {
            prefix[i] = prefix[i - 1] + nums[i];
            i++;
        }
        i = n - k;
        int x = INT_MIN;
        int j;
        while(-1 < i) {
            int y = prefix[n - 1] - prefix[i] + nums[i];
            if (y >= x) {
                x = y;
                j = i;
            }
            dp3[i] = j;
            n--;
            i--;
        }
        fill(0, k, nums, prefix, dp, dp2, dp3);
        // for(auto& it: dp) {
        //     cout << it[0] << ":" << it[1] << ":" << it[2] << "  ";
        // }
        // cout << endl;
        return dp[0];
    }

    void fill(int i, int k, vector<int>& nums, vector<int>& prefix, vector<vector<int>>& dp, vector<vector<int>>& dp2, vector<int>& dp3) {
        if (dp[i][0] != -2) {
            return;
        }

        int n = nums.size();
        int size = n - i;
        dp[i][0] = -1;
        dp[i][1] = -1;
        dp[i][2] = -1;
        dp2[i][0] = -1;
        dp2[i][1] = -1;

        if (size < k) {
            return;
        }

        if (size == k) {
            dp[i][0] = i;
            dp2[i][0] = i;
            return;
        }

        fill(i + k, k, nums, prefix, dp, dp2, dp3);
        fill(i + 1, k, nums, prefix, dp, dp2, dp3);

        if (size < 2 * k) {
            dp[i][0] = dp3[i];
            dp2[i][0] = dp3[i];
            return;
        }

        if (size == 2 * k) {
            dp[i][0] = i;
            dp[i][1] = i + k;
            dp2[i][0] = i;
            dp2[i][1] = i + k;
            return;
        }

        int t1, s1, t2, s2, p1, q1, p2, q2;
        t1 = i;
        t2 = dp3[i + k];
        s1 = prefix[t1 + k - 1] - prefix[t1] + nums[t1];
        s2 = prefix[t2 + k - 1] - prefix[t2] + nums[t2];
        p1 = dp2[i + 1][0];
        p2 = dp2[i + 1][1];
        q1 = prefix[p1 + k - 1] - prefix[p1] + nums[p1];
        q2 = prefix[p2 + k - 1] - prefix[p2] + nums[p2];

        if (s1 + s2 < q1 + q2) {
            dp2[i] = dp2[i + 1];
        } else {
            dp2[i][0] = t1;
            dp2[i][1] = t2;
        }

        if (size < 3 * k) {
            if (s1 + s2 < q1 + q2) {
                dp[i][0] = p1;
                dp[i][1] = p2;
            } else {
                dp[i][0] = t1;
                dp[i][1] = t2;
            }
            return;
        }

        if (size == 3 * k) {
            dp[i][0] = i;
            dp[i][1] = i + k;
            dp[i][2] = i + k + k;
            return;
        }

        int t3, s3, p3, q3;
        t2 = dp2[i + k][0];
        t3 = dp2[i + k][1];
        s2 = prefix[t2 + k - 1] - prefix[t2] + nums[t2];
        s3 = prefix[t3 + k - 1] - prefix[t3] + nums[t3];
        p1 = dp[i + 1][0];
        p2 = dp[i + 1][1];
        p3 = dp[i + 1][2];
        q1 = prefix[p1 + k - 1] - prefix[p1] + nums[p1];
        q2 = prefix[p2 + k - 1] - prefix[p2] + nums[p2];
        q3 = prefix[p3 + k - 1] - prefix[p3] + nums[p3];

        // if (i == 4) {
        //     cout << t1 << " " << t2 << " " << t3 << endl;
        //     cout << s1 << " " << s2 << " " << s3 << endl;
        //     cout << p1 << " " << p2 << " " << p3 << endl;
        //     cout << q1 << " " << q2 << " " << q3 << endl;
        // }

        if (s1 + s2 + s3 < q1 + q2 + q3) {
            dp[i] = dp[i + 1];
        } else {
            dp[i][0] = t1;
            dp[i][1] = t2;
            dp[i][2] = t3;
        }
    }
};

int main() {
    vector<int> nums = {95, 31, 33, 56, 84, 6, 10, 96, 17, 87, 29, 41, 41, 83, 39, 23, 33, 33, 51, 62, 36, 63, 52, 57, 89, 91, 43, 98, 83, 65, 91, 41, 7, 97, 56, 15, 32, 97, 19, 60, 68, 28, 2, 94, 64, 43, 67, 39, 32, 15, 75,   94, 40, 3, 10, 77, 24, 75, 35, 62, 83, 97, 51, 24, 75, 47, 28, 90, 31, 89, 17, 17, 7, 46, 6, 38, 4, 95, 37, 38, 4, 65, 76, 10, 48, 93, 59, 88, 26, 33, 63, 32, 23, 29, 99, 38, 18, 71, 87, 55};
    int k = 3;
    Solution sol;
    vector<int> res = sol.maxSumOfThreeSubarrays(nums, k);
    for(auto& idx: res) {
        cout << idx << " ";
    }
    cout << endl;
    return 0;
}
