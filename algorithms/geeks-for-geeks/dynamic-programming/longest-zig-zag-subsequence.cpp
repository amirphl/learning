// https://www.geeksforgeeks.org/longest-zig-zag-subsequence/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(n), memory: O(1)
    int ZigZagMaxLength(vector<int>& arr) {
        int n = arr.size();
        int inc_val = arr[0], inc_len = 1;
        int dec_val = arr[0], dec_len = 1;
        int i = 1;
        while(i < n) {
            int a, b;
            a = b = INT_MAX;
            if (arr[i] < inc_val) {
                if (dec_len < inc_len + 1) {
                    a = inc_len + 1;
                } else if (dec_len == inc_len + 1 && arr[i] < dec_val) {
                    a = inc_len + 1;
                }
            }
            if (arr[i] > dec_val) {
                if (inc_len < dec_len + 1) {
                    b = dec_len + 1;
                } else if (inc_len == dec_len + 1 && arr[i] > inc_val) {
                    b = dec_len + 1;
                }
            }
            if (a != INT_MAX) {
                dec_len = a;
                dec_val = arr[i];
            }
            if (b != INT_MAX) {
                inc_len = b;
                inc_val = arr[i];
            }
            i++;
        }
        return max(inc_len, dec_len);
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
        for(int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.ZigZagMaxLength(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
