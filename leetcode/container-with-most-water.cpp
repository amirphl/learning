// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        vector<vector<int>> temp;
        temp.push_back({n - 1, height[n - 1]});

        for(int i = n - 2; i >= 0; i--) {
            int m = temp.size();
            if (height[i] > temp[m - 1][1]) {
                temp.push_back({i, height[i]});

            }
            for(int j = 0; j < m; j++) {
                ans = max(ans, (temp[j][0] - i) * min(height[i], temp[j][1]));
            }
        }

        return ans;
    }
};
