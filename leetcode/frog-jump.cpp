// https://leetcode.com/problems/frog-jump/

class Solution {
public:
    bool canCross(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) {
            return 0;
        }
        if (arr[1] != 1) {
            return 0;
        }
        unordered_map<uint64_t, bool> dp;
        return rec(arr, dp, 1, 1);
    }

    bool rec(vector<int>& arr, unordered_map<uint64_t, bool>& dp, int index, int k) {
        uint64_t h = hash(index, k);
        if (dp.find(h) != dp.end()) {
            return dp[h];
        }
        int n = arr.size();
        if (k == 0) {
            return dp[h] = 0;
        }
        if (index == n - 2) {
            return dp[h] = arr[index] + k - 1 == arr[n - 1] ||
                           arr[index] + k == arr[n - 1] ||
                           arr[index] + k + 1 == arr[n - 1];
        }
        if (index == n - 1) {
            return dp[h] = 1;
        }
        int x = lower_bound(arr.begin() + index, arr.end(), arr[index] + k - 1) - arr.begin();
        if (x == n) {
            return dp[h] = 0;
        }
        if (arr[x] == arr[index] + k - 1) { // 8 = 5 + 4 - 1
            if (rec(arr, dp, x, k - 1)) {
                return dp[h] = 1;
            }
            if (arr[x + 1] == arr[index] + k) { // 9 = 5 + 4
                if (rec(arr, dp, x + 1, k)) {
                    return dp[h] = 1;
                }
                if (arr[x + 2] == arr[index] + k + 1) { // 10 = 5 + 4 + 1
                    if (rec(arr, dp, x + 2, k + 1)) {
                        return dp[h] = 1;
                    }
                }
            } else if (arr[x + 1] == arr[index] + k + 1) { // 10 = 5 + 4 + 1
                if (rec(arr, dp, x + 1, k + 1)) {
                    return dp[h] = 1;
                }
            }
        } else if (arr[x] == arr[index] + k) { // 9 = 5 + 4
            if (rec(arr, dp, x, k)) {
                return dp[h] = 1;
            }
            if (arr[x + 1] == arr[index] + k + 1) { // 10 = 5 + 4 + 1
                if (rec(arr, dp, x + 1, k + 1)) {
                    return dp[h] = 1;
                }
            }
        } else if (arr[x] == arr[index] + k + 1) { // 10 = 5 + 4 + 1
            if (rec(arr, dp, x, k + 1)) {
                return dp[h] = 1;
            }
        }
        return dp[h] = 0;
    }

    uint64_t hash(int index, int k) {
        uint64_t h = index;
        h = h << 32;
        return h + k;
    }
};
