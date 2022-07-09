// https://www.geeksforgeeks.org/subset-sum-divisible-m/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(n*m), memory; O(m)
    int DivisibleByM(vector<int> nums, int m) {
        vector<int> dp(m, 0);
        vector<int> dp2(m, 0);
        int j = 0, n = nums.size();
        while(j < n) {
            int i = 0;
            int rem2 = nums[j] % m;
            dp2[rem2] = 1;
            if (rem2 == 0) {
                return true;
            }
            while(i < m) {
                int rem = (i + nums[j]) % m;
                if (dp[i] == 1) {
                    if (rem == 0) {
                        return true;
                    }
                    dp2[rem] = 1;
                }
                i++;
            }
            dp = dp2;
            j++;
        }
        return 0;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n, m;
        cin >> n >> m;
        vector<int>nums(n);
        for(int i = 0; i < n; i++)cin >> nums[i];
        Solution ob;
        int ans  = ob.DivisibleByM(nums, m);
        cout << ans <<"\n";
    }
    return 0;
}  // } Driver Code Ends
