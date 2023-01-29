// https://leetcode.com/problems/candy/

class Solution {
public:
    int candy(vector<int>& rank) {
        int n = rank.size(), sum = 0;
        int candy[n];
        memset(candy, 0, sizeof(candy));
        for(int i = 0; i < n - 1; i++) {
            if (rank[i] < rank[i + 1]) {
                candy[i + 1] = candy[i] + 1;
            } else if (rank[i] > rank[i + 1] && candy[i] == 0) {
                candy[i] = 1;
            }
        }
        sum = candy[n - 1] + n;
        for(int i = n - 1; i >= 1; i--) {
            if (rank[i - 1] > rank[i] && candy[i - 1] <= candy[i]) {
                candy[i - 1] = candy[i] + 1;
            }
            sum += candy[i - 1];
        }
        return sum;
    }
};
