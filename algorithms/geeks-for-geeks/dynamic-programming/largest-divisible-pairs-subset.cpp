// https://www.geeksforgeeks.org/largest-divisible-pairs-subset/
// https://leetcode.com/problems/largest-divisible-subset/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // time: O(n*n), memory: O(n)
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int dp[n];
        int next[n];
        dp[0] = 1;
        next[0] = -1;
        int i = 1;
        while(i < n) {
            int j = 0;
            int res = 0, idx = -1;
            while(j < i) {
                if (nums[i] % nums[j] == 0 && res < dp[j]) {
                    res = dp[j];
                    idx = j;
                }
                j++;
            }
            dp[i] = 1 + res;
            next[i] = idx;
            i++;
        }
        vector<int> v;
        i = distance(dp, max_element(dp, dp + n));
        while(i != -1) {
            v.push_back(nums[i]);
            i = next[i];
        }
        return v;
    }
};

int main() {
    vector<int> nums = {67, 116, 118, 13, 129, 217, 8, 75, 235, 20, 187, 256, 221, 220, 107, 58, 269, 192, 189, 223, 170, 290, 206, 27, 147, 264, 173, 6, 31, 276, 128, 80, 185, 162, 231, 85, 180, 115, 293, 219, 234, 105, 168, 214, 131, 286, 197, 72, 237, 138, 149, 140, 212, 198, 283, 53, 257, 274, 92, 42, 102, 181, 76, 268, 103, 43, 155, 35, 294, 14, 59, 3, 142, 60, 277, 87, 278, 82, 132, 273, 249, 54, 204, 119, 148, 21, 32, 225, 229, 296, 5, 169, 41, 18, 292, 196, 127, 203, 202, 178};
    Solution sol;
    vector<int> res = sol.largestDivisibleSubset(nums);
    for(auto& it: res) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
