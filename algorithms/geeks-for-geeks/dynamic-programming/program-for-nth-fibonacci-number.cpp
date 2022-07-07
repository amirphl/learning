// https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/

// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
public:
    // time: O(n), memory: O(1)
    int firstElement(int n)
    {
        uint64_t f0 = 0;
        uint64_t f1 = 1;
        if (n == 0) {
            return f0;
        }
        n--;
        if (n == 1) {
            return f1;
        }
        n--;
        while(-1 < n) {
            uint64_t temp = f1;
            f1 = (f0 + f1) % 1000000007;
            f0 = temp;
            n--;
        }
        return f1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n ;
        Solution ob;
        cout<<ob.firstElement(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
