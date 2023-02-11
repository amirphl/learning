// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution {
public:
    // This doesn't work!
    int findUnsortedSubarray(vector<int>& nums) {
        const int n = nums.size();
        int min_arr[n], max_arr[n];
        min_arr_to[0] = nums[0];
        max_arr_to[0] = nums[0];
        min_arr_from[n - 1] = nums[n - 1];
        max_arr_from[n - 1] = nums[n - 1];

        for(int i = 1; i < n; i++) {
            min_arr_to[i] = min(min_arr_to[i - 1], nums[i]);
            max_arr_to[i] = max(max_arr_to[n - 1], nums[i]);
            min_arr_from[n - i - 1] = min(min_arr_from[n - i], nums[i]);
            max_arr_from[n - i - 1] = max(max_arr_from[n - i], nums[i]);
        }

        int low = 1, high = n;

        while(low < high) {
            if (low == high) {
                return low;
            }

            const int wnd = (low + high) >> 1;
            int i = 0;

            for(; i < n - wnd; i++) {
                const int j = i + wnd;
                int max_to_i_1 = i > 0 ? max_arr_to[i - 1] ? INT_MIN;
                int min_i_j_1 = 0; // This is the problem!
                int max_i_j_1 = 0; // This is the problem too!
                int min_from_j = min_arr_from[j];

                if (max_to_i_1 <= min_i_j_1 && max_i_j_1 <= min_from_j) {
                    break;
                }
            }

            if (i == n) {
                low = mid + 1;
            } else {
                high = wnd;
            }
        }

        return n;
    }
};
