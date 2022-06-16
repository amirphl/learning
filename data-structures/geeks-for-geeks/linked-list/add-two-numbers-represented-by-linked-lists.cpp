// https://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:
    // time: O(n), memory: O(1)
    vector<int> findSum(vector<int> &a, vector<int> &b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int c = 0;
        vector<int> v;
        while(i >= 0 || j >= 0 || c > 0) {
            if (i >= 0) {
                c += a[i];
                i--;
            }
            if (j >= 0) {
                c += b[j];
                j--;
            }
            v.push_back(c % 10);
            c = c / 10;
        }
        reverse(v.begin(), v.end());
        return v;
    }

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        Solution ob;
        auto ans = ob.findSum(a, b);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
