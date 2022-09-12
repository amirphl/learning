// https://www.geeksforgeeks.org/maximum-triplet-sum-array/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // time: O(n), memory: O(1)
    int maxTripletSum(int arr[], int n)
    {
        if (n < 3) {
            return INT_MIN;
        }
        int a, b, c;
        if (arr[0] >= arr[1] && arr[0] >= arr[2]) {
            a = arr[0];
            b = max(arr[1], arr[2]);
            c = min(arr[1], arr[2]);
        } else if (arr[1] >= arr[0] && arr[1] >= arr[2]) {
            a = arr[1];
            b = max(arr[0], arr[2]);
            c = min(arr[0], arr[2]);
        } else if (arr[2] >= arr[0] && arr[2] >= arr[1]) {
            a = arr[2];
            b = max(arr[1], arr[0]);
            c = min(arr[1], arr[0]);
        }
        int i = 3;
        while(i < n) {
            if (arr[i] >= a) {
                c = b;
                b = a;
                a = arr[i];
            } else if (arr[i] >= b) {
                c = b;
                b = arr[i];
            } else if (arr[i] >= c) {
                c = arr[i];
            }
            i++;
        }
        return a + b + c;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int a[n];
        for(i=0; i<n; i++)
            cin>>a[i];
        Solution ob;
        cout <<ob.maxTripletSum(a, n);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
