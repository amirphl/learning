// https://leetcode.com/problems/make-sum-divisible-by-p/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        /*
        sum(i, j) % p == target
        sum(i , j) % 7 == 3
        (sum(0, i - 1) (4) + 3) % 7 == 0
        (sum(0, i - 1) (5) + 3) % 7 == 1
        (sum(0, i - 1) (0) + 3) % 7 == 3
        (sum(0, i - 1) (2) + 3) % 7 == 5
        */
        int n = nums.size();
        nums[0] = nums[0] % p;

        for(int i = 1; i < n; i++) {
            nums[i] = (nums[i - 1] + (int64_t) nums[i]) % p;
        }

        int ans = n, target = nums[n - 1];

        if (target == 0) {
            return 0;
        }

        // TLE
        // int *rem = new int[p];
        // memset(rem, -1, p * sizeof(int));
        unordered_map<int, int> rem;

        for(int i = 0; i < n; i++) {
            int d = (nums[i] - target + p) % p;
            // if (rem[d] > -1)
            if (rem.find(d) != rem.end()) {
                ans = min(ans, i - rem[d]);
            }
            if (d == 0) {
                ans = min(ans, i + 1);
            }
            rem[nums[i]] = i;
        }

        return ans == n ? -1 : ans;
    }
};
