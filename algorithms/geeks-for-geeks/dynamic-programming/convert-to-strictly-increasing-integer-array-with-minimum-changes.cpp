// https://www.geeksforgeeks.org/convert-to-strictly-increasing-integer-array-with-minimum-changes/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(n*n), memory: O(n)
    int min_operations(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        int i = 0, lis = 1;
        while(i < n) {
            dp[i] = 1;
            int j = 0;
            while(j < i) {
                dp[i] = max(dp[i],
                            nums[j] < nums[i] && i - j <= nums[i] - nums[j] ? dp[j] + 1 : 0
                           );
                j++;
            }
            lis = max(lis, dp[i]);
            i++;
        }
        return n - lis;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        vector<int>nums(n);
        for(int i = 0; i < n; i++)cin >> nums[i];
        Solution ob;
        int ans  = ob.min_operations(nums);
        cout << ans <<"\n";
    }
    return 0;
}
// } Driver Code Ends
