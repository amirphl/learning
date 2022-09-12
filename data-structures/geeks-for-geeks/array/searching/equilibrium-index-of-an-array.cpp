// https://www.geeksforgeeks.org/equilibrium-index-of-an-array/

//{ Driver Code Starts
#include <iostream>
using namespace std;
#include <stdio.h>

int findEquilibrium(int [], int );

int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        cout<<findEquilibrium (a,n)<<endl;
    }
    // your code goes here
    return 0;
}
// } Driver Code Ends


/* You are required to complete this method*/
// time: O(n), memory: O(1)
int findEquilibrium(int arr[], int n)
{
    int i = 0, s = 0;
    while(i < n) {
        s += arr[i];
        i++;
    }
    int left = 0;
    i = 0;
    while(i < n) {
        if (s - left - arr[i] == left) {
            return i;
        }
        left += arr[i];
        i++;
    }
    return -1;
}
