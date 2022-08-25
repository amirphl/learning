// https://www.geeksforgeeks.org/find-the-element-that-appears-once-in-a-sorted-array/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
public:
    // time: O(logn), memory: O(1)
    int search(int arr[], int n) {
        int i = 0;
        int j = n - 1;
        while(i <= j) {
            if (i == j) {
                return arr[i];
            }
            if (i + 1 == j) {
                return INT_MAX;
            }
            int mid = (i + j) >> 1;
            if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
                return arr[mid];
            }
            if (i + 2 == j) {
                if (arr[mid - 1] != arr[mid] && arr[mid - 1] != arr[mid + 1]) {
                    return arr[mid - 1];
                }
                return arr[mid + 1];
            }
            if (arr[mid] == arr[mid + 1]) {
                if ((j - mid - 2 + 1) % 2 == 0) {
                    j = mid - 1;
                } else {
                    i = mid + 2;
                }
            } else {
                if ((j - mid - 1 + 1) % 2 == 0) {
                    j = mid - 2;
                } else {
                    i = mid + 1;
                }
            }
        }
        return INT_MAX;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0; i<len; i++) {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends
