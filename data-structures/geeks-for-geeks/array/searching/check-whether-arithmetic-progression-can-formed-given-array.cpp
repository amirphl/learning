// https://www.geeksforgeeks.org/check-whether-arithmetic-progression-can-formed-given-array/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    // time: O(n), memory: O(1)
    bool checkIsAP(int arr[], int n)
    {
        if (n == 1) {
            return true;
        }
        sort(arr, arr + n);
        int ap = arr[1] - arr[0];
        int i = 2;
        while(i < n) {
            if (arr[i] - arr[i - 1] != ap) {
                return false;
            }
            i++;
        }
        return true;
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
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        (ob.checkIsAP(arr, n))? (cout << "YES" << endl) :
        (cout << "NO" << endl);
    }

    return 0;
}

// } Driver Code Ends
