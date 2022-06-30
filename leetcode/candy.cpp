// https://leetcode.com/problems/candy/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // time: O(n), memory: O(n)
    int candy(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) {
            return 1;
        }
        int dp[n];
        arr.push_back(INT_MAX);
        arr.push_back(INT_MIN);
        int i = 0;
        while(i < n) {
            int j = i;
            while(j < n && arr[j] > arr[j + 1]) {
                j++;
            }
            int k = j;
            while(i <= j) {
                dp[j] = k - j + 1;
                j--;
            }
            i = k + 1;
        }
        int res = dp[0];
        i = 1;
        while(i < n) {
            if (arr[i - 1] < arr[i] && dp[i - 1] >= dp[i]) {
                dp[i] = dp[i - 1] + 1;
            }
            // cout << dp[i] << " ";
            res += dp[i];
            i++;
        }
        // cout << endl;
        return res;
    }
};

int main() {
    vector<int> arr = {2, 4, 0, 2, 3, 0, 3, 4, 1, 4, 1, 4, 4, 2, 2, 2, 3, 1, 4, 2, 2, 0, 2, 2, 1, 1, 4, 0, 4, 2};
    Solution sol;
    cout << sol.candy(arr);
    cout << endl;
    return 0;
}
