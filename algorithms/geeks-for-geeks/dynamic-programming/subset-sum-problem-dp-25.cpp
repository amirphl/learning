// https://www.geeksforgeeks.org/subset-sum-problem-dp-25/

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    // time: O(n*m), memory: O(m)
    bool isSubsetSum(vector<int> arr, int m) {
        int dp[m + 1];
        memset(dp, 0, sizeof(dp));
        int j = 0, n = arr.size();
        while(j < n) {
            if (arr[j] > m) {
                j++;
                continue;
            }
            if (dp[m - arr[j]] == 1) {
                return true;
            }
            int i = m;
            while(-1 < i) {
                if (dp[i] == 1 && i + arr[j] < m + 1) {
                    // cout << i << ":" << arr[j] << "  ";
                    dp[i + arr[j]] = 1;
                }
                i--;
            }
            dp[arr[j]] = 1;
            // cout << endl;
            j++;
        }
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0;
}
// } Driver Code Ends
