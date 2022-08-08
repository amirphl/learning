// https://www.geeksforgeeks.org/count-all-increasing-subsequences/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    // time: O(n), memory: O(1)
    unsigned long long int countSub(int arr[], int n)
    {
        unsigned long long dp[10];
        memset(dp, 0, sizeof(dp));
        int i = 0;
        while(i < n) {
            int j = 0;
            while(j < arr[i]) {
                dp[arr[i]] += dp[j];
                j++;
            }
            dp[arr[i]]++;
            i++;
        }
        unsigned long long count = 0;
        i = 0;
        while(i < 10) {
            count += dp[i];
            i++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+1];
        for(unsigned long long int i=0; i<n; i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.countSub(a,n)<<endl;
    }
}

// } Driver Code Ends
