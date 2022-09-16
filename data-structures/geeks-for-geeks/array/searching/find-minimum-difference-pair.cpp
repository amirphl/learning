// https://www.geeksforgeeks.org/find-minimum-difference-pair/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(nlogn), memory: O(1)
    int minimum_difference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int i = 0, n = arr.size(), diff = INT_MAX;
        while(i < n - 1) {
            diff = min(diff, arr[i + 1] - arr[i]);
            i++;
        }
        return diff;
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
        for(int i = 0; i < nums.size(); i++)cin >> nums[i];
        Solution ob;
        int ans = ob.minimum_difference(nums);
        cout << ans <<"\n";
    }
    return 0;
}
// } Driver Code Ends
