// https://leetcode.com/problems/arithmetic-slices/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) {
            return 0;
        }
        int prev = (arr[2] - arr[1] == arr[1] - arr[0] ? 1 : 0);
        int count = prev;
        for(int i = 3; i < n; i++) {
            bool x = arr[i - 2] - arr[i - 1] == arr[i - 1] - arr[i];
            if (x) {
                prev += 1;
            } else {
                prev = 0;
            }
            count += prev;
        }
        return count;
    }
};
