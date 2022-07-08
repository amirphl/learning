// https://www.geeksforgeeks.org/tiling-problem/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(logn), memory: O(1)
    long long numberOfWays(long long n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        n--;
        long long A[2][2] = {{1, 1}, {1, 0}};
        long long B[2][2] = {{1, 1}, {1, 1}};
        int i = 1 * 2;
        while(i <= n) {
            multiply(A, A);
            i *= 2;
            if (i > n) {
                n -= i / 2;
                multiply(B, A);
                A[0][0] = 1;
                A[0][1] = 1;
                A[1][0] = 1;
                A[1][1] = 0;
                if (n == 1) {
                    multiply(B, A);
                    n--;
                }
                i = 1 * 2;
            }
        }
        return B[0][0];
    }
    void multiply(long long A[2][2], long long B[2][2]) {
        int rem = 1e9 + 7;
        long long x1 = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % rem;
        long long x2 = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % rem;
        long long x3 = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % rem;
        long long x4 = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % rem;
        A[0][0] = x1;
        A[0][1] = x2;
        A[1][0] = x3;
        A[1][1] = x4;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;

        cin>>N;

        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0;
}  // } Driver Code Ends
