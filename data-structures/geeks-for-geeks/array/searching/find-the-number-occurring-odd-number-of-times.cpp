// https://www.geeksforgeeks.org/find-the-number-occurring-odd-number-of-times/

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    // time: O(n), memory: O(1)
    int getOddOccurrence(int arr[], int n) {
        int x = arr[0];
        int i = 1;
        while(i < n) {
            x ^= arr[i];
            i++;
        }
        return x;
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
        auto ans = ob.getOddOccurrence(arr, n);
        cout << ans << "\n";
    }
    return 0;
}


// } Driver Code Ends
