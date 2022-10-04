// https://www.geeksforgeeks.org/maximum-distance-two-occurrences-element-array/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // your task is to complete this function
    // time: O(n), memory: O(n)
    int maxDistance(int arr[], int n)
    {
        unordered_map<int, int> m;
        int i = 0, res = 0;
        while(i < n) {
            if (m.find(arr[i]) == m.end()) {
                m[arr[i]] = i;
            } else {
                res = max(res, i - m[arr[i]]);
            }
            i++;
        }
        return res;
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
        cout<<ob.maxDistance(arr,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
