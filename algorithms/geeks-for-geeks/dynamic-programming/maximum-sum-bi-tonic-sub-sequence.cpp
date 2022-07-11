// https://www.geeksforgeeks.org/maximum-sum-bi-tonic-sub-sequence/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int maxSumBS(int arr[], int n );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];

        cout<<maxSumBS(a,n)<<endl;

    }
}// } Driver Code Ends


// time: O(n*n), memory: O(n)
int maxSumBS(int arr[], int n )
{
    int inc[n];
    int dec[n];
    inc[0] = arr[0];
    dec[n - 1] = arr[n - 1];
    int i = 1;
    while(i < n) {
        inc[i] = arr[i];
        int j = 0;
        while(j < i) {
            if (arr[j] < arr[i]) {
                inc[i] = max(inc[i], arr[i] + inc[j]);
            }
            j++;
        }
        i++;
    }
    i = n - 2;
    while(-1 < i) {
        dec[i] = arr[i];
        int j = n - 1;
        while(i < j) {
            if (arr[j] < arr[i]) {
                dec[i] = max(dec[i], arr[i] + dec[j]);
            }
            j--;
        }
        i--;
    }
    int res = INT_MIN;
    i = 0;
    while(i < n) {
        res = max(res, inc[i] + dec[i] - arr[i]);
        // cout << res << " " << i << " " << inc[i] << " " << dec[i] << endl;
        i++;
    }
    return res;
}

