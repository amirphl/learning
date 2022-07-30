// https://www.geeksforgeeks.org/c-program-find-gcd-hcf-two-numbers/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<long long> lcmAndGcd(long long A, long long B) {
        long long GCD = gcd(A, B);
        return {A * B / GCD, GCD};
    }
    long long gcd(long long a, long long b) {
        if (a == b) {
            return a;
        }
        return a > b ? gcd(a - b, a) : gcd(a, b - a);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;

        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends
