// https://www.geeksforgeeks.org/gcd-two-array-numbers/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(nlogn), memory: O(1)
    long long getVal(int N, int A[]) {
        int mod = 1e9 + 7;
        int f = A[0];
        long long h = A[0];
        int i = 1;
        while(i < N) {
            f = gcd(f, A[i]);
            h = (h * A[i]) % mod;
            i++;
        }
        // cout << f << " " << h << endl;
        return (long long)(pow(h, f)) % mod;
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;
        int A[N];

        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.getVal(N,A) << endl;
    }
    return 0;
}
// } Driver Code Ends
