// https://leetcode.com/problems/maximum-product-subarray/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // time: O(n), memory: O(1)
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), pos, neg;
        if (0 <= nums[0]) {
            pos = nums[0];
            neg = 0;
        } else {
            pos = 0;
            neg = nums[0];
        }
        int i = 1, res = nums[0];
        while(i < n) {
            if (0 < nums[i]) {
                if (0 < pos) {
                    pos = pos * nums[i];
                } else {
                    pos = nums[i];
                }
                if (neg < 0) {
                    neg = neg * nums[i];
                } else {
                    neg = 0;
                }
            } else if (nums[i] == 0) {
                pos = 0;
                neg = 0;
            } else {
                int pre_pos = pos;
                int pre_neg = neg;
                if (pre_neg < 0) {
                    pos = pre_neg * nums[i];
                } else {
                    pos = 0;
                }
                if (0 < pre_pos) {
                    neg = pre_pos * nums[i];
                } else {
                    neg = nums[i];
                }
            }
            res = max({res, pos, neg});
            i++;
        }
        return res;
    }
};

int main() {
    vector<int> nums = {0, -1, -3, -2, 1, -1, -3, 0, -1, 1, -1, 1, 1, -1, -1, 0, 3, -1, 0, 1};
    Solution sol;
    cout << sol.maxProduct(nums);
    cout << endl;
    return 0;
}
