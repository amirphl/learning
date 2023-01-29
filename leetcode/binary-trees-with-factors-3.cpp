// https://leetcode.com/problems/binary-trees-with-factors/

class Solution {
public:
    int mod = 1e9 + 7;

    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, pair<int, int>> dp;
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            dp[arr[i]] = {-1, i};
        }

        uint64_t sum = 0;

        for(int i = 0; i < n; i++) {
            sum = (sum + find(dp, arr, i)) % mod;
        }

        return sum;
    }

    uint64_t find(unordered_map<int, pair<int, int>>& dp, vector<int>& arr, int k) {
        int m = arr[k];

        if (dp.find(m) == dp.end()) {
            return 0;
        }

        if (dp[m].first > -1) {
            return dp[m].first;
        }

        if (m == 1) {
            return 0;
        }

        uint64_t sum = 1;

        for (int j = 0; j < k && arr[j] <= sqrt(m); j++) {
            int i = arr[j];

            if (m % i == 0) {
                if (m / i == i) {
                    sum = (sum + (find(dp, arr, j) * find(dp, arr, j)) % mod) % mod;
                } else if (dp.find(m / i) != dp.end() && i != m && m / i != m) {
                    sum = (sum + (2 * find(dp, arr, j) * find(dp, arr,  dp[m / i].second)) % mod) % mod;
                }
            }
        }

        return dp[m].first = sum;
    }
};
