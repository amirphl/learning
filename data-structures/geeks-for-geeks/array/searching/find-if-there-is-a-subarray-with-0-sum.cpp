// https://www.geeksforgeeks.org/find-if-there-is-a-subarray-with-0-sum/

// { Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution {
public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    // time: O(n), memory: O(n)
    bool subArrayExists(int arr[], int n)
    {
        int pre[n];
        pre[0] = arr[0];

        for(int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + arr[i];
        }
        unordered_set<int> s;
        for(int i = 0; i < n; i++) {
            if (pre[i] == 0 || s.find(pre[i]) != s.end()) {
                return 1;
            } else {
                s.insert(pre[i]);
            }
        }
        return 0;
    }
};

// { Driver Code Starts.
// Driver code
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
        Solution obj;
        if (obj.subArrayExists(arr, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}  // } Driver Code Ends
