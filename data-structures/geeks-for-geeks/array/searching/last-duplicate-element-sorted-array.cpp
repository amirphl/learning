// https://www.geeksforgeeks.org/last-duplicate-element-sorted-array/

//{ Driver Code Starts
// To print last duplicate element and its
// index in a sorted array
#include<bits/stdc++.h>
using namespace std;

vector<int> dupLastIndex(int arr[], int n) ;



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
        {
            cin>>a[i];
        }
        vector<int> v;
        v = dupLastIndex(a,n);
        for(int i:v)
            cout << i << " ";
        cout << endl;

    }
    return 0;
}


// } Driver Code Ends

// time: O(n), memory: O(1)
vector<int> dupLastIndex(int arr[], int n) {
    int pre = arr[n - 1];
    int i = n - 2;
    while(i >= 0) {
        if (arr[i] == arr[i + 1]) {
            return {i + 1, arr[i]};
        } else {
            pre = arr[i];
        }
        i--;
    }
    return {-1};
}

