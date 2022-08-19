// https://www.geeksforgeeks.org/pairs-difference-less-k/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // time: O(nlogn), memory: O(1)
    int countPairs(int arr[], int n, int k)
    {
        sort(arr, arr + n);
        int i = 0, count = 0;
        while(i < n) {
            count += distance(arr + i + 1, lower_bound(arr + i + 1, arr + n, arr[i] + k));
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
        int n,k;
        cin>>n>>k;
        int a[n],i;
        for(i=0; i<n; i++)
        {
            cin>>a[i];
        }
        Solution ob;
        cout << ob.countPairs(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
