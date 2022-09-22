// https://www.geeksforgeeks.org/find-the-smallest-positive-number-missing-from-an-unsorted-array/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
public:
    // Function to find the smallest positive number missing from the array.
    // time: O(n), memory: O(1)
    int missingNumber(int arr[], int n)
    {
        int index = partition(arr, arr + n, [](int a) {
            return a <= 0;
        }) - arr;
        int i = index;
        while(i < n) {
            if (arr[i] <= n) {
                int j = arr[i] - 1;
                do {
                    int t = arr[j];
                    arr[j] = INT_MAX;
                    j = t - 1;
                } while(j + 1 != INT_MAX && j > -1 && j < n);
            }
            i++;
        }
        i = 0;
        while(i < n) {
            if (arr[i] != INT_MAX) {
                return i + 1;
            }
            i++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() {

    //taking testcases
    int t;
    cin>>t;
    while(t--) {

        //input number n
        int n;
        cin>>n;
        int arr[n];

        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];

        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
