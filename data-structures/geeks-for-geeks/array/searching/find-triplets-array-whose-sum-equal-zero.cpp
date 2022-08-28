// https://www.geeksforgeeks.org/find-triplets-array-whose-sum-equal-zero/

//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution {
public:
    // Function to find triplets with zero sum.
    // time: O(n*n), memroy: O(1)
    bool findTriplets(int arr[], int n)
    {
        sort(arr, arr + n);
        int i = 0;
        while(i < n) {
            int k = 0;
            int j = n - 1;
            while(k < j) {
                if (k == i) {
                    k++;
                    continue;
                }
                if (j == i) {
                    j--;
                    continue;
                }
                if (arr[k] + arr[j] + arr[i] == 0) {
                    return true;
                }
                if (arr[k] + arr[j] + arr[i] < 0) {
                    k++;
                } else {
                    j--;
                }
            }
            i++;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n]= {0};
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0;
}
// } Driver Code Ends
