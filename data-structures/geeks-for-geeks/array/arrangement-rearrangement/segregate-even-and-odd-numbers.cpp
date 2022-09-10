// https://www.geeksforgeeks.org/segregate-even-and-odd-numbers/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:
    // time: O(nlogn), memory: O(n)
    void segregateEvenOdd(int arr[], int n) {
        int x = distance(arr, stable_partition(arr, arr + n, [](int a) {
            return a % 2 == 0;
        }));
        sort(arr, arr + x);
        sort(arr + x, arr + n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.segregateEvenOdd(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
