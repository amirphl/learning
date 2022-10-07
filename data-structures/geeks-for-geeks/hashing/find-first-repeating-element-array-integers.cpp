// https://www.geeksforgeeks.org/find-first-repeating-element-array-integers/

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution {
public:
    // Function to return the position of the first repeating element.
    // time: O(n), memory: O(n)
    int firstRepeated(int arr[], int n) {
        unordered_map<int, vector<int>> m;
        int i = 0;
        while(i < n) {
            if (m.find(arr[i]) == m.end()) {
                m[arr[i]] = {1, i};
            } else {
                m[arr[i]][0]++;
            }
            i++;
        }
        i = 0;
        while(i < n) {
            if(m[arr[i]][0] > 1) {
                return m[arr[i]][1] + 1;
            }
            i++;
        }
        return -1;
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

        for (int i = 0; i < n; ++i) cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}

// } Driver Code Ends
