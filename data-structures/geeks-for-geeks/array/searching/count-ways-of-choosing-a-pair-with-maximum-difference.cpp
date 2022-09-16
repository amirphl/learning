// https://www.geeksforgeeks.org/count-ways-of-choosing-a-pair-with-maximum-difference/

//{ Driver Code Starts
//
// Created by Tanuj Johal on 24-06-2020.
//
#include <bits/stdc++.h>
using namespace std;

long long countPairs(int *a,int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+1];
        for(int i=0; i<n; i++)
            cin>>a[i];
        long long ans = countPairs(a,n);
        cout<<ans<<endl;
    }
}


// } Driver Code Ends

// time: O(nlogn), memory: O(1)
long long countPairs(int arr[],int n) {
    int min_elem = *min_element(arr, arr + n);
    int max_elem = *max_element(arr, arr + n);
    int diff = max_elem - min_elem;
    long long res = 0;
    sort(arr, arr + n);
    int i = 0;
    while(i < n) {
        int j = lower_bound(arr + i + 1, arr + n, arr[i] + diff) - arr;
        int k = upper_bound(arr + i + 1, arr + n, arr[i] + diff) - arr;
        res += k - j;
        i++;
    }
    return res;
}
