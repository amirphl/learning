// https://www.geeksforgeeks.org/k-th-missing-element-increasing-sequence-not-present-given-sequence/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // time: O(nlogn), memory: O(1)
    int MissingNumber(int arr[], int b[], int k, int n, int m)
    {
        sort(b, b + m);
        int i = 0;
        while(i < n) {
            int idx = lower_bound(b, b + m, arr[i]) - b;
            if (idx < 0 || idx >= m || b[idx] != arr[i]) {
                k--;
            }
            if (k == 0) {
                return arr[i];
            }
            i++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int a[n],b[m];
        for(int i=0; i<n; i++)
            cin>>a[i];
        for(int i=0; i<m; i++)
            cin>>b[i];
        Solution ob;
        cout << ob.MissingNumber(a, b, k, n, m)<<endl;

    }
    return 0;
}

// } Driver Code Ends
