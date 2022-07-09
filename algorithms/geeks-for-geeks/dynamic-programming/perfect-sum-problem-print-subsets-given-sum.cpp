// https://www.geeksforgeeks.org/perfect-sum-problem-print-subsets-given-sum/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

public:
    // time: O(n*m), memory: O(m)
    int perfectSum(int arr[], int n, int m)
    {
        uint64_t dp[m + 1], rem = 1e9 + 7;
        memset(dp, 0, sizeof(dp));
        int i = 0;
        while(i < n) {
            int j = m;
            while(-1 < j) {
                uint64_t x = arr[i] + j;
                if (x < m + 1) {
                    dp[x] = (dp[x] + dp[j]) % rem;
                }
                j--;
            }
            dp[arr[i]]++;
            i++;
        }
        return dp[m];
    }

};

// { Driver Code Starts.
int main()
{


    int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];



        Solution ob;
        cout << ob.perfectSum(a, n, sum) << "\n";

    }
    return 0;
}
// } Driver Code Ends
