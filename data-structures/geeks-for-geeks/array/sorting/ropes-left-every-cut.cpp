// https://www.geeksforgeeks.org/ropes-left-every-cut/

//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(nlogn), memory: O(1)
    vector<int> RopeCutting(int arr[], int n)
    {
        vector<int> res;
        sort(arr, arr + n);
        int i = 0;
        while(i < n) {
            int elem = arr[i];
            int j = i + 1;
            while(j < n && arr[j] == elem) {
                j++;
            }
            if (j == n) {
                break;
            }
            res.push_back(n - j);
            i = j;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>> T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        vector<int> v;
        Solution ob;
        v = ob.RopeCutting(arr, n);
        for(int i : v) {
            cout << i << " ";
        }
        cout << endl;


    }
    return 0;
}

// } Driver Code Ends
