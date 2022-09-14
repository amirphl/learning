// https://www.geeksforgeeks.org/k-th-missing-element-in-sorted-array/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];

        cout << KthMissingElement(a, n, k) << endl;

    }
    return 0;
}

// } Driver Code Ends

// time: O(logn), memory: O(1)
int KthMissingElement(int arr[], int n, int k)
{
    int left = 0, right = n - 1;
    while(left < right) {
        if (left == right) {
            // cout << "s1 " << left << " " << k << endl;
            return -1;
        }
        if (left + 1 == right) {
            int missing = arr[right] - arr[left] - 1;
            if (missing < k) {
                // cout << "s2 " << left << " " << k << endl;
                return -1;
            } else {
                // cout << "s3 " << left << " " << k << endl;
                return arr[left] + k;
            }
        }
        int mid = (left + right) >> 1;
        if (mid + 1 < arr[mid]) {
            int missing = (arr[mid] - arr[left] + 1) - (mid - left + 1);
            if (missing < k) {
                k -= missing;
                left = mid;
            } else {
                right = mid;
            }
        } else if (mid + 1 == arr[mid]) {
            left = mid;
        } else {
            // impossible
        }
        // cout << "s4 " << left << " " << right << " " << k << endl;
    }
    return -1;
}
