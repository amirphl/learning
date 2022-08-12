// https://www.geeksforgeeks.org/find-a-pair-with-the-given-difference/

//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0; i<l; i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }


    return 0;
}
// } Driver Code Ends

// time: O(nlogn), memory: O(1)
bool findPair(int arr[], int n, int diff) {
    sort(arr, arr + n);
    int i = 0;
    while(i < n) {
        int *p = lower_bound(arr, arr + n, arr[i] + diff);
        int *q = lower_bound(arr, arr + n, arr[i] - diff);
        bool b1 = &arr[i] != p && distance(arr, p) < n && (*p == arr[i] + diff);
        bool b2 = &arr[i] != q && distance(arr, q) < n && (*p == arr[i] - diff);

        if (b1 || b2) {
            return true;
        }
        i++;
    }
    return false;
}
