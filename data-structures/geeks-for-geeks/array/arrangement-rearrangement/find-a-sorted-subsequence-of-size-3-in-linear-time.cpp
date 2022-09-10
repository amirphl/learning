// https://www.geeksforgeeks.org/find-a-sorted-subsequence-of-size-3-in-linear-time/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2, int n, int m) {

    if (m == 0) return true;
    if (n == 0) return false;

    if (v1[n - 1] == v2[m - 1]) return isSubSequence(v1, v2, n - 1, m - 1);

    return isSubSequence(v1, v2, n - 1, m);
}


// } Driver Code Ends
/*The function returns a vector containing the
increasing sub-sequence of length 3 if present
else returns an empty vector */
class Solution {
public:
    // time: O(n), memory: O(n)
    vector<int> find3Numbers(vector<int> arr, int n) {
        int temp[n][2];
        temp[0][0] = INT_MAX;
        int i = 1, min_elem = INT_MAX;
        while(i < n) {
            min_elem = min(min_elem, arr[i - 1]);
            temp[i][0] = min_elem;
            i++;
        }
        temp[n - 1][1] = INT_MIN;
        i = n - 2;
        int max_elem = INT_MIN;
        while(i > -1) {
            max_elem = max(max_elem, arr[i + 1]);
            temp[i][1] = max_elem;
            i--;
        }
        i = 0;
        while(i < n) {
            if (temp[i][0] < arr[i] && arr[i] < temp[i][1]) {
                return {temp[i][0], arr[i], temp[i][1]};
            }
            i++;
        }
        return {};
    }
};

//{ Driver Code Starts.

// Driver program to test above function
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        auto res = obj.find3Numbers(a, n);

        // wrong format output
        if (!res.empty() and res.size() != 3) {
            cout << -1 << "\n";
        }

        if (res.empty()) {
            cout << 0 << "\n";
        } else if ((res[0] < res[1] and res[1] < res[2]) and
                   isSubSequence(a, res, n, res.size())) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends
