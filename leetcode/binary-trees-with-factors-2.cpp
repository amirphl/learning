// https://leetcode.com/problems/binary-trees-with-factors/

class Solution {
public:
    int mod = 1e9 + 7;

    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, int> dp;
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            dp[arr[i]] = -1;
        }

        uint64_t sum = 0;

        for(int i = 0; i < n; i++) {
            sum = (sum + find(dp, arr[i])) % mod;
        }

        return sum;
    }

    uint64_t find(unordered_map<int, int>& dp, int m) {
        if (dp.find(m) == dp.end()) {
            return 0;
        }

        if (dp[m] > -1) {
            return dp[m];
        }

        if (m == 1) {
            return dp[1] = 0;
        }

        uint64_t sum = 1;

        for (int i = 1; i <= sqrt(m); i++) {
            if (m % i == 0) {
                if (m / i == i) {
                    sum = (sum + (find(dp, i) * find(dp, i)) % mod) % mod;
                } else if (i != m && m / i != m) {
                    sum = (sum + (2 * find(dp, i) * find(dp, m /i)) % mod) % mod;
                }
            }
        }

        return dp[m] = sum;
    }
};
