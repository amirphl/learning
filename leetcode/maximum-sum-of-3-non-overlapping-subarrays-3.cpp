// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        if (3 * k > n) {
            return {0, 0, 0};
        }

        int prefix_sum[n];
        int dp_1[n - 3 * k + 1]; // k - 1: n - 2k - 1
        int dp_2[n - 3 * k + 1]; // 2k : n - k

        memset(prefix_sum, 0, sizeof(prefix_sum));
        memset(dp_1, -1, sizeof(dp_1));
        memset(dp_2, -1, sizeof(dp_2));

        prefix_sum[0] = nums[0];

        for(int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }

        dp_1[0] = 0;
        int temp = prefix_sum[k - 1];

        for(int j = 1, i = k; i < n - 2 * k; i++, j++) {
            int mid_sum = prefix_sum[i] - prefix_sum[i - k];

            if (mid_sum > temp) {
                temp = mid_sum;
                dp_1[j] = i - k + 1;
            } else {
                dp_1[j] = dp_1[j - 1];
            }
        }

        dp_2[n - 3 * k] = n - k;
        temp = prefix_sum[n - 1] - prefix_sum[n - k - 1];

        for(int j = n - 3 * k - 1, i = n - k - 1; i >= 2 * k; i--, j--) { // merge
            int mid_sum = prefix_sum[i + k - 1] - prefix_sum[i - 1];

            if (mid_sum >= temp) {
                temp = mid_sum;
                dp_2[j] = i;
            } else {
                dp_2[j] = dp_2[j + 1];
            }
        }

        int max_total = INT_MIN;
        int idx0 = 0, idx1 = 0, idx2 = 0;

        for(int j = 0, i = k; i <= n - 2 * k; i++, j++) {
            int low = dp_1[j];
            int high = dp_2[j];

            int left_sum = prefix_sum[low + k - 1] - (low > 0 ? prefix_sum[low - 1] : 0);
            int mid_sum = prefix_sum[i + k - 1] - prefix_sum[i - 1];
            int right_sum = prefix_sum[high + k - 1] - prefix_sum[high - 1];
            int total = left_sum + mid_sum + right_sum;

            vector<int> first = {low, i, high};
            vector<int> second = {idx0, idx1, idx2};

            if (total > max_total ||
                    (total == max_total && is_smaller_than(first, second))) {
                max_total = total;
                idx0 = low;
                idx1 = i;
                idx2 = high;
            }
        }

        return {idx0, idx1, idx2};
    }

    bool is_smaller_than(vector<int>& first, vector<int>& second) {
        for(int i = 0; i < min(first.size(), second.size()); i++) {
            if (first[i] < second[i]) {
                return true;
            }
            if (first[i] > second[i]) {
                return false;
            }
        }

        return false;
    }
};
