// https://www.geeksforgeeks.org/count-balanced-binary-trees-height-h/

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    // time: O(n), memory: O(1)
    long long int countBT(int h) {
        if (h == 1) {
            return 1;
        }
        if (h == 2) {
            return 3;
        }
        long long int a = 1, b = 3, c;
        int i = 3, mod = 1e9 + 7;
        while(i <= h) {
            c = ((2 * a * b) % mod + (b * b) % mod) % mod;
            a = b;
            b = c;
            i++;
        }
        return c;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;
    }
    return 0;
}

// } Driver Code Ends
