// https://practice.geeksforgeeks.org/problems/array-to-bst4443/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(n), memory: O(logn)
    vector<int> sortedArrayToBST(vector<int>& nums) {
        vector<int> pre(nums.size());
        stack<vector<int>> s;
        s.push({0, nums.size() - 1});
        int i = 0;
        while(!s.empty()) {
            int low = s.top()[0];
            int high = s.top()[1];
            int mid = (low + high) / 2;
            s.pop();
            if (low > high) {
                continue;
            }
            pre[i] = nums[mid];
            i++;
            s.push({mid + 1, high});
            s.push({low, mid - 1});
        }
        return pre;
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
        for(int i = 0; i < n; i++)cin >> nums[i];
        Solution obj;
        vector<int>ans = obj.sortedArrayToBST(nums);
        for(auto i: ans)
            cout << i <<" ";
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
