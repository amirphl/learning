// https://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution {
public:
    // time: O(n), memory: O(1)
    ll countStrings(int n) {
        if (n == 1) {
            return 2;
        }
        if (n == 2) {
            return 3;
        }
        ll a = 2;
        ll b = 3;
        ll c;
        int i = 3, mod = 1e9 + 7;
        while(i <= n) {
            c = (a + b) % mod;
            a = b;
            b = c;
            i++;
        }
        return b;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
