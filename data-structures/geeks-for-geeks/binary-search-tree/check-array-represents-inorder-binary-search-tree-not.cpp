// https://www.geeksforgeeks.org/check-array-represents-inorder-binary-search-tree-not/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    // time: O(n), memory: O(1)
    int isRepresentingBST(int arr[], int N)
    {
        int i = 1;
        while(i < N) {
            if (arr[i - 1] >= arr[i]) {
                return false;
            }
            i++;
        }
        return true;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0; i<N; i++)cin>>arr[i];
        Solution ob;
        cout<<ob.isRepresentingBST(arr,N)<<endl;
    }
    return 0;
}  // } Driver Code Ends
