// https://www.geeksforgeeks.org/k-th-distinct-or-non-repeating-element-in-an-array/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(n), memory: O(n)
    int KthDistinct(vector<int> arr, int k) {
        unordered_map<int, int> m;
        int i = 0, n = arr.size();
        while(i < n) {
            m[arr[i]]++;
            i++;
        }
        i = 0;
        while(i < n) {
            if (m[arr[i]] == 1) {
                if (k == 1) {
                    return arr[i];
                }
                k--;
            }
            i++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n, k;
        cin >> n >> k;
        vector<int>nums(n);
        for(int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans  = ob.KthDistinct(nums, k);
        cout << ans <<"\n";
    }
    return 0;
}
// } Driver Code Ends
