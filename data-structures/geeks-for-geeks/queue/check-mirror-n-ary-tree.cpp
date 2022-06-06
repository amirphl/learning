// https://www.geeksforgeeks.org/check-mirror-n-ary-tree/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    // time: O(n), memory: O(n)
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        unordered_map<int, vector<int>> m1;
        unordered_map<int, vector<int>> m2;
        for(int i = 0; i < 2 * e; i += 2) {
            m1[A[i]].push_back(A[i + 1]);
            m2[B[2 * e - 2 - i]].push_back(B[2 * e - 2 - i + 1]);
        }
        // assume that 1 is root.
        queue<int> q1;
        queue<int> q2;
        q1.push(1);
        q2.push(1);
        while(!q1.empty() && !q2.empty()) {
            int t1 = q1.front();
            int t2 = q2.front();
            q1.pop();
            q2.pop();
            if (t1 != t2) {
                return false;
            }
            for(auto& it: m1[t1]) {
                q1.push(it);
            }
            for(auto& it: m2[t2]) {
                q2.push(it);
            }
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;

        cin>>n>>e;
        int A[2*e], B[2*e];

        for(int i=0; i<2*e; i++)
            cin>>A[i];

        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends
