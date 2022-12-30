// https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned/

class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int j = 0, count = 0, n = flips.size();

        for(int i = 0; i < n; i++) {
            int coeff = flips[i] < 0 ? -1 : 1;
            flips[coeff * flips[i] - 1] *= -1;

            for(; j < n && flips[j] < 0; j++);

            if (i + 1 == j) {
                count++;
            }
        }

        return count;
    }
};
