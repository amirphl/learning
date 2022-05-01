// https://www.geeksforgeeks.org/check-if-an-array-can-be-divided-into-pairs-whose-sum-is-divisible-by-k/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // time: O(n), memory: O(n)
    bool canPair(vector<int> nums, int k) {
        if (nums.size() % 2 == 1) {
            return false;
        }
        unordered_map<int, int> m;
        int s = 0;
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i] % k]++;
            if (nums[i] % k == 0) {
                s++;
            }
        }
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] % k != 0) {
                if(m[k - (nums[i] % k)] == 0) {
                    return false;
                } else {
                    m[k - (nums[i] % k)]--;
                }
            }
        }
        return s % 2 == 0;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends
