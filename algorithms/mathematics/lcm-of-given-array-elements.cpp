// https://www.geeksforgeeks.org/lcm-of-given-array-elements/

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // time: O(nlogn), memory: O(1)
    long long numGame(long long n) {
        int mod = 1e9 + 7;
        long long lcm = 1;
        long long i = 2;
        while(i <= n) {
            lcm = ((lcm * i) / (__gcd(lcm, i) % mod)) % mod;
            i++;
        }
        return lcm;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;

        cin>>n;

        Solution ob;
        cout << ob.numGame(n) << endl;
    }
    return 0;
}
// } Driver Code Ends
