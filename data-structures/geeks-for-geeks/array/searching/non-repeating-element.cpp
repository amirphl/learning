// https://www.geeksforgeeks.org/non-repeating-element/

//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // time: O(n), memory: O(n)
    int firstNonRepeating(int arr[], int n)
    {
        unordered_map<int, vector<int>> m;
        int i = 0;
        while(i < n) {
            if (m.find(arr[i]) == m.end()) {
                m[arr[i]] = {1, i};
            } else {
                m[arr[i]][0]++;
            }
            i++;
        }
        int index = INT_MAX;
        i = 0;
        while(i < n) {
            if (m[arr[i]][0] == 1) {
                index = min(index, m[arr[i]][1]);
            }
            i++;
        }
        return index == INT_MAX ? 0 : arr[index];
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
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.firstNonRepeating(arr,n)<<endl;
    }
}

// } Driver Code Ends
