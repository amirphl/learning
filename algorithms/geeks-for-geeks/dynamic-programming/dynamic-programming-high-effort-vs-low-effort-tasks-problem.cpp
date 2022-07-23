// https://www.geeksforgeeks.org/dynamic-programming-high-effort-vs-low-effort-tasks-problem/

//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends
#include<bits/stdc++.h>

class Solution
{
public:
    // time: O(n), memory: O(1)
    int maxAmt(int n, int hi[], int li[])
    {
        int f = hi[n - 1], f_;
        int g = li[n - 1], g_;
        int h = 0, h_;
        int i = n - 2;
        while(i >= 0) {
            f_ = hi[i] + max(g, h);
            g_ = li[i] + max(g, h);
            h_ = max({f, g, h});
            f = f_;
            g = g_;
            h = h_;
            i--;
        }
        return max({f, g, h});
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
        int hi[n], li[n];
        for(int i = 0 ; i<n; i++)
            cin>>hi[i];
        for(int i = 0 ; i<n; i++)
            cin>>li[i];
        Solution ob;
        cout<<ob.maxAmt(n,hi,li)<<endl;
    }
}
// } Driver Code Ends
