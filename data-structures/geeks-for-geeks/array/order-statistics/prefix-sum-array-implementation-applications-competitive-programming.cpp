// https://www.geeksforgeeks.org/prefix-sum-array-implementation-applications-competitive-programming/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // time: O(n + k), memory: O(1)
    void update(int arr[], int n, int updates[], int k)
    {
        int i = 0;
        while(i < k) {
            arr[updates[i] - 1]++;
            i++;
        }
        int s = 0;
        i = 0;
        while(i < n) {
            int t = arr[i];
            arr[i] += s;
            s += t;
            i++;
        }
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
        int a[n]= {0}, updates[k]= {0};
        for(int i = 0; i < k; i++)
            cin>>updates[i];
        Solution ob;
        ob.update(a, n, updates, k);

        for(int i = 0; i < n; i++)
            cout<<a[i]<<" ";

        cout<<endl;
    }

    return 0;
}
// } Driver Code Ends
