// https://www.geeksforgeeks.org/replace-every-element-with-the-greatest-on-right-side/

//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:
    /* Function to replace every element with the
    next greatest element */
    // time: O(n), memory: O(1)
    void nextGreatest(int arr[], int n) {
        int i = n - 2;
        int g = arr[n - 1];
        arr[n - 1] = -1;
        while(i > -1) {
            int t = arr[i];
            arr[i] = g;
            g = max(g, t);
            i--;
        }
    }


};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.nextGreatest(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
