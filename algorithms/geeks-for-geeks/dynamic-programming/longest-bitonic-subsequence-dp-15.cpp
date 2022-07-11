// https://www.geeksforgeeks.org/longest-bitonic-subsequence-dp-15/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(n*n), memory: O(n)
    int LongestBitonicSequence(vector<int> arr)
    {
        int n = arr.size();
        int inc[n];
        int dec[n];
        inc[0] = 1;
        dec[n - 1] = 1;
        int i = 1;
        while(i < n) {
            inc[i] = 1;
            int j = 0;
            while(j < i) {
                if (arr[j] < arr[i]) {
                    inc[i] = max(inc[i], 1 + inc[j]);
                }
                j++;
            }
            i++;
        }
        i = n - 2;
        while(-1 < i) {
            dec[i] = 1;
            int j = n - 1;
            while(i < j) {
                if (arr[j] < arr[i]) {
                    dec[i] = max(dec[i], 1 + dec[j]);
                }
                j--;
            }
            i--;
        }
        int res = INT_MIN;
        i = 0;
        while(i < n) {
            res = max(res, inc[i] + dec[i] - 1);
            // cout << res << " " << i << " " << inc[i] << " " << dec[i] << endl;
            i++;
        }
        return res;

    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        vector<int>nums(n);
        for(int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.LongestBitonicSequence(nums);
        cout << ans <<"\n";
    }
    return 0;
}  // } Driver Code Ends
