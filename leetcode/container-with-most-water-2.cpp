// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        for(int i = 0, j = n - 1; i < j;) {
            if (height[i] < height[j]) {
                ans = max(ans, (j - i) * height[i]);
                i++;
            } else {
                ans = max(ans, (j - i) * height[j]);
                j--;
            }
        }

        return ans;
    }
};
