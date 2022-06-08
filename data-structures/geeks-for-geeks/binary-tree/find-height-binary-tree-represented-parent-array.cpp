// https://www.geeksforgeeks.org/find-height-binary-tree-represented-parent-array/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // time: O(n), memory: O(n)
    int findHeight(int N, int arr[]) {
        unordered_map<int, int> m;
        int i = 0, u, v, min_seen = INT_MAX, max_seen = INT_MIN;
        while(i < N) {
            if (arr[i] == -1) {
                i++;
                continue;
            }
            u = INT_MIN;
            v = INT_MIN;
            if (m.find(arr[i]) != m.end()) {
                v = m[arr[i]];
            }
            if (m.find(i) != m.end()) {
                u = m[i];
            }
            if (u == INT_MIN && v == INT_MIN) {
                m[i] = 0;
                m[arr[i]] = 1;
            } else if (u == INT_MIN) {
                m[i] = v - 1;
            } else if (v == INT_MIN) {
                m[arr[i]] = u + 1;
            } else {

            }
            // cout << i << " " << m[i] << " " << m[arr[i]] << " " << u << " " << v << endl;
            min_seen = min(min_seen, m[i]);
            max_seen = max(max_seen, m[arr[i]]);
            i++;
        }
        return max_seen - min_seen + 1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) {
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0; i < N; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.findHeight(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
