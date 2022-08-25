// https://www.geeksforgeeks.org/find-k-closest-elements-given-value/

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    // time: O(n), memory: O(1)
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        int index = distance(arr.begin(), lower_bound(arr.begin(), arr.end(), x));
        int i = index;
        int j = index;
        while(i >= 0 && arr[i] == x) {
            i--;
        }
        while(j < n && arr[j] == x) {
            j++;
        }
        if (i == j) {
            i--;
            // j++ is wrong!
        }
        vector<int> v(k);
        int c = k;
        while((i >= 0 || j < n) && k > 0) {
            if (i >= 0 && j < n) {
                if (x - arr[i] < arr[j] - x) {
                    v[c - k] = arr[i];
                    i--;
                } else {
                    v[c - k] = arr[j];
                    j++;
                }
            } else if (i >= 0) {
                v[c - k] = arr[i];
                i--;
            } else if (j < n) {
                v[c - k] = arr[j];
                j++;
            } else {

            }
            k--;
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
