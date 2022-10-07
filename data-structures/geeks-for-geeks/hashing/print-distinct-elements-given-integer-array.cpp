// https://www.geeksforgeeks.org/print-distinct-elements-given-integer-array/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // time: O(nlogn), memory: O(1)
    vector<int> removeDuplicate2(int arr[], int n) {
        sort(arr, arr + n);
        vector<int> v;
        int i = 0;
        while(i < n - 1) {
            if (arr[i] != arr[i + 1]) {
                v.push_back(arr[i]);
            }
            i++;
        }
        v.push_back(arr[n - 1]);
        return v;
    }

    // time: O(n), memory: O(n)
    vector<int> removeDuplicate(int arr[], int n) {
        vector<int> v;
        unordered_set<int> s;
        int i = 0;
        while(i < n) {
            if (s.find(arr[i]) == s.end()) {
                v.push_back(arr[i]);
                s.insert(arr[i]);
            }
            i++;
        }
        return v;
    }
};

//{ Driver Code Starts.

// Driver method to test above method
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<int> v = ob.removeDuplicate(a, n);

        for (auto it : v) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
