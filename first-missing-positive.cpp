// https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int min_elem = -1;

        for(int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                if (min_elem == -1) {
                    min_elem = nums[i];
                } else {
                    min_elem = min(min_elem, nums[i]);
                }
            }
        }

        if (min_elem == -1 || min_elem > 1) {
            return 1;
        }

        for(int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                nums[i] -= min_elem;
            } else {
                nums[i] = -2;
            }
        }

        for(int i = 0; i < n; i++) {
            int j = nums[i];
            // cout << i << " " << j << endl;
            while(0 <= j && j < n) {
                // cout << j << endl;
                int temp = nums[j];
                nums[j] = -1;
                j = temp;
            }
        }

        for(int i = 0; i < n; i++) {
            if (nums[i] != -1) {
                return i + min_elem;
            }
        }

        return n + 1;
    }
};
