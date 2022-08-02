// https://www.geeksforgeeks.org/least-prime-factor-of-numbers-till-n/

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    // time: O(nlogn), memory: O(n)
    vector<int> leastPrimeFactor(int n) {
        vector<int> res;
        res.push_back(0);
        res.push_back(1);
        vector<int> primes;
        int i = 2;
        while(i <= n) {
            int j = 0;
            bool pushed = false;
            while(j < primes.size()) {
                if (i % primes[j] == 0) {
                    res.push_back(primes[j]);
                    pushed = true;
                    break;
                }
                j++;
            }
            if (!pushed) {
                primes.push_back(i);
                res.push_back(i);
            }
            i++;
        }
        return res;
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
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1; i<=n; i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends
