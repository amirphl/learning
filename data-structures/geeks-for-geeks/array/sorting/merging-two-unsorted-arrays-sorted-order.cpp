// https://www.geeksforgeeks.org/merging-two-unsorted-arrays-sorted-order/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Your code goes here

class Solution {
public:
    // time: O((n + m)log(n + m)), memory: O(1)
    void sortedMerge(int a[], int b[], int res[], int n, int m)
    {
        memcpy(res, a, n * sizeof(int));
        memcpy(res + n, b, m * sizeof(int));
        sort(res, res + n + m);
    }
};


//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for(int i = 0; i<n; i++) {
            cin >> a[i];
        }

        for(int i = 0; i<m; i++) {
            cin >> b[i];
        }

        int res[n+m];


        Solution ob;
        ob.sortedMerge(a,b,res,n,m);

        for(int i = 0; i<n+m; i++) {
            cout << res[i] << " ";
        }


        cout << "\n";

    }
    return 0;
}

// } Driver Code Ends
