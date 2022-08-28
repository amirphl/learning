// https://www.geeksforgeeks.org/maximize-sum-consecutive-differences-circular-array/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; ++i)
            cin>>arr[i];
        cout<<maxSum(arr,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends

// time: O(nlogn), memory: O(1)
long long int maxSum(int arr[], int n)
{
    sort(arr, arr + n);
    long long int s = 0;
    int i = 0, j = n - 1;
    bool f = true;
    while(i < j) {
        s += abs(arr[i] - arr[j]);
        if (f) {
            i++;
            f = false;
        } else {
            j--;
            f = true;
        }
    }
    s += abs(arr[0] - arr[j]);
    return s;
}
