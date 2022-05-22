// https://www.geeksforgeeks.org/check-if-a-given-array-can-represent-preorder-traversal-of-binary-search-tree/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        int index = canRepresentBSTRec(arr, 0, N, INT_MIN, INT_MAX);
        return index == N - 1;
    }
    // time: O(n), memory: O(h)
    int canRepresentBSTRec(int arr[], int i, int n, int lower, int upper) {
        if (i == n - 1) {
            return n - 1;
        }
        int index = i + 1;
        if (arr[index] > upper || arr[index] < lower) {
            return i;
        }
        if (arr[i] > arr[index]) {
            index = canRepresentBSTRec(arr, index, n, lower, arr[i]);
            if (index == n - 1) {
                return n - 1;
            }
            index++;
        }
        if (arr[index] > upper || arr[index] < lower || arr[i] > arr[index]) {
            return index - 1;
        }
        return canRepresentBSTRec(arr, index, n, arr[i], upper);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}  // } Driver Code Ends
