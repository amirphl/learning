// https://www.geeksforgeeks.org/longest-alternating-subsequence/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(n*n), memory: O(n)
    // Time Limit Exceeded
    int AlternatingaMaxLength2(vector<int>& arr) {
        int n = arr.size();
        int longest = 1;
        int inc[n];
        int dec[n];
        inc[n - 1] = 1;
        dec[n - 1] = 1;
        int i = n - 2;
        while(i >= 0) {
            inc[i] = 1;
            dec[i] = 1;
            int j = i + 1;
            while(j < n) {
                if (arr[j] > arr[i]) {
                    inc[i] = max(inc[i], 1 + dec[j]);
                } else if (arr[j] < arr[i]) {
                    dec[i] = max(dec[i], 1 + inc[j]);
                }
                j++;
            }
            longest = max({longest, inc[i], dec[i]});
            i--;
        }

        return longest;
    }

    // time: O(n), memory: O(1)
    int AlternatingaMaxLength(vector<int>& arr) {
        int n = arr.size();
        int longest_inc = 1, longest_dec = 1;
        int inc_start = arr[n - 1], dec_start = arr[n - 1];
        int i = n - 2;
        while(i >= 0) {
            if (arr[i] < dec_start) {
                if (1 + longest_dec > longest_inc) {
                    longest_inc = 1 + longest_dec;
                    inc_start = arr[i];
                } else if (1 + longest_dec == longest_inc && arr[i] < inc_start) {
                    longest_inc = 1 + longest_dec;
                    inc_start = arr[i];
                }
            }
            if (arr[i] > inc_start) {
                if (1 + longest_inc > longest_dec) {
                    longest_dec = 1 + longest_inc;
                    dec_start = arr[i];
                } else if (1 + longest_inc == longest_dec && arr[i] > dec_start) {
                    longest_dec = 1 + longest_inc;
                    dec_start = arr[i];
                }
            }
            i--;
        }

        return max(longest_inc, longest_dec);
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
        int ans = obj.AlternatingaMaxLength(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
