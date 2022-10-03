// https://www.geeksforgeeks.org/iterative-method-check-two-trees-mirror/
// https://www.geeksforgeeks.org/check-if-two-trees-are-mirror/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        multimap<int, int> m1;
        multimap<int, int> m2;

        for(int i = 0; i < 2 * e; i += 2) {
            m1.insert(pair<int, int> (A[i], A[i + 1]));
            m2.insert(pair<int, int> (B[i], B[i + 1]));
        }

        // assume that 1 is root.
        queue<int> q1;
        queue<int> q2;
        stack<int> s2;
        q1.push(1);
        q2.push(1);

        while(!q1.empty() && !q2.empty()) {
            int t1 = q1.front();
            int t2 = q2.front();
            q1.pop();
            q2.pop();
            // cout << t1 << " " << t2 << endl;

            if (t1 != t2) {
                return false;
            }

            auto itr1 = m1.lower_bound(t1);
            auto itr2 = m1.upper_bound(t1);

            while (itr1 != itr2) {
                if (itr1 -> first == t1) {
                    // cout << "-- " << itr1 -> first << " " << itr1 -> second << endl;
                    q1.push(itr1 -> second);
                }
                itr1++;
            }

            itr1 = m2.lower_bound(t2);
            itr2 = m2.upper_bound(t2);

            while (itr1 != itr2) {
                if (itr1 -> first == t2) {
                    s2.push(itr1 -> second);
                }
                itr1++;
            }

            while(!s2.empty()) {
                q2.push(s2.top());
                s2.pop();
            }
        }

        return true;
    }

    // time: O(n), memory: O(n)
    int checkMirrorTree2(int n, int e, int A[], int B[]) {
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
