// https://leetcode.com/problems/minimum-score-by-changing-two-elements/

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();

        if (n <= 3) {
            return 0;
        }

        int u, v, w, x;

        sort(nums.begin(), nums.begin() + 4);

        u = 0;
        v = 1;
        w = 2;
        x = 3;

        for(int i = 4; i < n; i++) {
            if (nums[i] <= nums[u]) {
                v = u;
                u = i;
            } else if (nums[i] <= nums[v]) {
                v = i;
            } else if (nums[i] >= nums[x]) {
                w = x;
                x = i;
            } else if (nums[i] >= nums[w]) {
                w = i;
            }
        }

        // cout << a << " " << b << " " << c << " " << d << endl;
        // cout << u << " " << v << " " << w << " " << x << endl;

        int e = INT_MAX, f = INT_MIN;

        for(int i = 0; i < n; i++) {
            if (i != u && i != v) {
                e = min(e, nums[i]);
            }
            if (i != w && i != x) {
                f = max(f, nums[i]);
            }
        }

        // cout << e << " " << f << endl;

        return min({nums[w] - nums[v], f - nums[u], nums[x] - e});
    }
};
