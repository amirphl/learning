// https://www.geeksforgeeks.org/count-number-of-occurrences-or-frequency-in-a-sorted-array/

//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:
    /* if x is present in arr[] then returns the count
    	of occurrences of x, otherwise returns 0. */
    int count(int arr[], int n, int x) {
        return countRec(arr, 0, n - 1, x);
    }
    int countRec(int arr[], int i, int j, int x) {
        if (i > j) {
            return 0;
        }
        if (i == j) {
            if (arr[i] == x) {
                return 1;
            }
            return 0;
        }
        int mid = (i + j) / 2;
        if (arr[mid] == x) {
            int count = 1;
            int k = mid - 1;
            while(i <= k) {
                if (arr[k] == x) {
                    count++;
                    k--;
                } else {
                    break;
                }
            }
            k = mid + 1;
            while(k <= j) {
                if (arr[k] == x) {
                    count++;
                    k++;
                } else {
                    break;
                }
            }
            return count;
        } else if (arr[mid] > x) {
            return countRec(arr, i, mid - 1, x);
        } else {
            return countRec(arr, mid + 1, j, x);
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
