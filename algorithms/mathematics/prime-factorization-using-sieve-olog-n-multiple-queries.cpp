// https://www.geeksforgeeks.org/prime-factorization-using-sieve-olog-n-multiple-queries/

//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    // time: O(n), memory: O(n)
    vector<int> AllPrimeFactors(int n) {
        vector<int> res;
        int c = 2, freq = 0;
        while(n >= c) {
            if (n % c == 0) {
                freq++;
                n = n / c;
                if (freq == 1) {
                    res.push_back(c);
                }
            } else {
                freq = 0;
                c++;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        long long int N;
        cin >> N;
        Solution ob;
        vector<int>ans = ob.AllPrimeFactors(N);
        for(auto i: ans)
            cout << i <<" ";
        cout <<"\n";
    }
    return 0;
}
// } Driver Code Ends
