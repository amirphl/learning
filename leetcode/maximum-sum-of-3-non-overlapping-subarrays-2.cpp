// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/

// Time Limit Exceeded

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix_sum[n];
        int dp_1[n][2];
        int dp_2[n][3];

        memset(prefix_sum, 0, sizeof(prefix_sum));
        memset(dp_1, -1, sizeof(dp_1));
        memset(dp_2, -1, sizeof(dp_2));

        prefix_sum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }

        int max_found = INT_MIN;
        int idx0, idx1, idx2;

        for(int i = 0; i <= n - 3 * k; i++) {
            int j = i + k;
            maxSumOfTwoSubarrays(nums, prefix_sum, dp_1, dp_2, j, k);
            int w = prefix_sum[j - 1] - (i > 0 ? prefix_sum[i - 1] : 0) + dp_2[j][2];
            vector<int> first = {i, dp_2[j][0], dp_2[j][1]};
            vector<int> second = {idx0, idx1, idx2};

            if (w > max_found ||
                    (w == max_found && is_smaller_than(first, second))) {
                max_found = w;
                idx0 = i;
                idx1 = dp_2[j][0];
                idx2 = dp_2[j][1];
            }
        }

        return {idx0, idx1, idx2};
    }

    void maxSumOfTwoSubarrays(vector<int>& nums, int prefix_sum[], int dp_1[][2], int dp_2[][3], int idx0, int k) {
        if (dp_2[idx0][0] != -1) {
            return;
        }

        int n = nums.size();
        int max_found = INT_MIN;
        int idx1, idx2;

        for(int i = idx0; i <= n - 2 * k; i++) {
            int j = i + k;
            maxSumOfOneSubarrays(nums, prefix_sum, dp_1, j, k);
            int w = prefix_sum[j - 1] - prefix_sum[i - 1] + dp_1[j][1];
            vector<int> first = {i, dp_1[j][0]};
            vector<int> second = {idx1, idx2};

            if (w > max_found ||
                    (w == max_found && is_smaller_than(first, second))) {
                max_found = w;
                idx1 = i;
                idx2 = dp_1[j][0];
            }
        }

        dp_2[idx0][0] = idx1;
        dp_2[idx0][1] = idx2;
        dp_2[idx0][2] = max_found;
    }

    void maxSumOfOneSubarrays(vector<int>& nums, int prefix_sum[], int dp_1[][2], int idx1, int k) {
        if (dp_1[idx1][0] != -1) {
            return;
        }

        int n = nums.size();
        int max_found = INT_MIN;
        int idx2;

        for(int i = idx1; i <= n - k; i++) {
            int j = i + k;
            int w = prefix_sum[j - 1] - prefix_sum[i - 1];
            vector<int> first = {i};
            vector<int> second = {idx2};

            if (w > max_found ||
                    (w == max_found && is_smaller_than(first, second))) {
                max_found = w;
                idx2 = i;
            }
        }

        dp_1[idx1][0] = idx2;
        dp_1[idx1][1] = max_found;
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
