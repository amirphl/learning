// https://www.geeksforgeeks.org/find-distinct-subset-subsequence-sums-array/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(n*sum/w), memory: O(sum)
    vector<int> DistinctSum(vector<int>& arr) {
        int n = arr.size();
        bitset<10001> bs;
        bs[0] = 1;
        int i = 0;
        while(i < n) {
            bs |= bs << arr[i];
            i++;
        }
        vector<int> res;
        i = 0;
        while(i < 10001) {
            if (bs[i] == 1) {
                res.push_back(i);
            }
            i++;
        }
        return res;
    }

    // time: O(n*sum), memory: O(n*sum)
    vector<int> DistinctSum2(vector<int>& arr) {
        int n = arr.size();
        int max_sum = 0;
        int min_sum = 0;
        int i = 0;
        while(i < n) {
            if (arr[i] > 0) {
                max_sum += arr[i];
            }
            if (arr[i] < 0) {
                min_sum += arr[i];
            }
            i++;
        }
        int diff = max_sum - min_sum + 1;
        bool dp[n][diff];
        i = 0;
        while(i < n) {
            int j = 0;
            while(j < diff) {
                if (j + min_sum == 0) {
                    dp[i][j] = true;
                } else if (i > 0) {
                    dp[i][j] = (j + min_sum - arr[i] >= 0 ? dp[i - 1][j - arr[i]] : false) || dp[i - 1][j];
                } else {
                    dp[i][j] = (j + min_sum - arr[i] == 0);
                }
                // cout << i << ":" << j + min_sum << ":" << dp[i][j] << " ";
                j++;
            }
            // cout << endl;
            i++;
        }
        vector<int> res;
        i = 0;
        while(i < diff) {
            if (dp[n - 1][i]) {
                res.push_back(i + min_sum);
            }
            i++;
        }
        return res;
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
        Solution obj;
        vector<int> ans = obj.DistinctSum(nums);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
