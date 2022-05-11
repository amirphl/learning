// https://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution/
// https://www.geeksforgeeks.org/josephus-circle-using-circular-linked-list/
// https://www.geeksforgeeks.org/?p=158048
// http://en.wikipedia.org/wiki/Josephus_problem

// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    int safePos(int n, int k) {
        return safePos(n, k, 0) + 1;
    }
    // time: O(n), memory: O(n)
    int safePos(int n, int k, int p) {
        if (n == 1) {
            return p;
        }
        int rem = ((p + k) % n) - 1;
        if (rem < 0) {
            rem = (rem + n) % n;
        }
        int idx = safePos(n - 1, k, rem);
        if (idx < rem) {
            return idx;
        } else {
            return (idx + 1) % n;
        }
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}  // } Driver Code Ends
