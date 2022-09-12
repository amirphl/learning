// https://www.geeksforgeeks.org/distinct-adjacent-elements-array/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(n), memory: O(n)
    bool distinctAdjacentElement(int arr[], int n)
    {
        unordered_map<int, int> m;
        int i = 0;
        while(i < n) {
            m[arr[i]]++;
            if (m[arr[i]] > (n + 1) / 2) {
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
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i<n; i++)
            cin >> arr[i];
        Solution ob;
        if(ob.distinctAdjacentElement(arr,n))
            cout<<"YES";
        else
            cout<<"NO";
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
