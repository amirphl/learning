// https://www.geeksforgeeks.org/partition-problem-dp-18/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // time: O(n*w), memory: O(w)
    int equalPartition(int N, int arr[])
    {
        int total = 0;
        int i = 0;
        while(i < N) {
            total += arr[i];
            i++;
        }
        if (total % 2 == 1) {
            return 0;
        }
        total /= 2;
        bool* prv = new bool[total + 1];
        bool* dp = new bool[total + 1];
        i = 0;
        while(i < N) {
            dp[0] = true;
            int j = 1;
            while(j < total + 1) {
                if (i == 0) {
                    dp[j] = arr[i] == j;
                } else if (arr[i] <= j) {
                    dp[j] = prv[j] || prv[j - arr[i]];
                } else {
                    dp[j] = prv[j];
                }
                j++;
            }
            bool* temp = dp;
            dp = prv;
            prv =  temp;
            i++;
        }
        // TODO delete allocated arrays
        return prv[total];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) {
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0; i < N; i++)
            cin>>arr[i];

        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
