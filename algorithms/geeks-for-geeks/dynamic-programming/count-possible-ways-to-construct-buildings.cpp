// https://www.geeksforgeeks.org/count-possible-ways-to-construct-buildings/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(n), memory: O(1)
    int TotalWays(int N)
    {
        if (N == 1) {
            return 4;
        }
        uint64_t a = 1;
        uint64_t b = 2;
        uint64_t c;
        int i = 2, mod = 1e9 + 7;
        while(i < N + 1) {
            c = (a + b) % mod;
            a = b;
            b = c;
            i++;
        }
        return (b * b) % mod;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.TotalWays(N);
        cout << ans <<"\n";
    }
    return 0;
}  // } Driver Code Ends
