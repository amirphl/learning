// https://www.geeksforgeeks.org/maximum-distinct-elements-removing-k-elements/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    // time: O(n), memory: O(n)
    int maxDistinctNum(int arr[], int n, int k)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[arr[i]]++;
        }
        int sum = 0;
        for (auto &it: m) {
            sum += it.second - 1;
        }
        int size = m.size();
        if (k <= sum) {
            return size;
        } else {
            return size + sum - k;
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n>>k;
        int arr[n];
        for(i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout <<ob.maxDistinctNum(arr, n, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
