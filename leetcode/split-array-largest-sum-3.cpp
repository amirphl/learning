// https://leetcode.com/problems/split-array-largest-sum/

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int total = 0;
        int max_found = INT_MIN;

        for(int i = 0; i < n; i++) {
            total += nums[i];
            max_found = max(max_found, nums[i]);
        }

        return find(nums, k, max_found, total);
    }

    int find(vector<int>& nums, int k, int low, int high) {
        if (low == high) {
            return low;
        }

        int n = nums.size();
        int mid = (low + high) / 2;

        int sum = 0, j = 1;
        for(int i = 0; i < n; i++) {
            if (sum + nums[i] <= mid) {
                sum += nums[i];
            } else {
                j++;
                i--;
                sum = 0;
            }
        }

        if (j <= k) {
            return find(nums, k, low, mid);
        } else {
            return find(nums, k, mid + 1, high);
        }
    }
};
