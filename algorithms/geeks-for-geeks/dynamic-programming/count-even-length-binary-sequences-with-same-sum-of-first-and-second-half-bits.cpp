// https://www.geeksforgeeks.org/count-even-length-binary-sequences-with-same-sum-of-first-and-second-half-bits/

// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // time: O(n), memory: O(1)
    int compute_value(int n)
    {
        if (n == 0) {
            return 2;
        }
        uint64_t nCr = 1, res = 1, rem = 1e9 + 7;
        int i = 1;
        while(i < n + 1) {
            nCr = (nCr * (n - i + 1) / i) % rem;
            res = (res + (nCr * nCr) % rem) % rem;
            i++;
        }
        return res % rem;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.compute_value(n);
        cout << ans <<"\n";
    }
    return 0;
}  // } Driver Code Ends
