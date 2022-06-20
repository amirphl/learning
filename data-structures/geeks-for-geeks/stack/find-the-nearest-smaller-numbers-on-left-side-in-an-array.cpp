// https://www.geeksforgeeks.org/find-the-nearest-smaller-numbers-on-left-side-in-an-array/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // time: O(n), memory: O(n)
    vector<int> leftSmaller(int n, int arr[]) {
        vector<int> v(n);
        stack<int> s;
        s.push(arr[0]);
        v[0] = -1;
        int i = 1;
        while(i < n) {
            if (arr[i] > arr[i - 1]) {
                v[i] = arr[i - 1];
            } else {
                while(!s.empty() && s.top() >= arr[i]) {
                    s.pop();
                }
                if (s.empty()) {
                    v[i] = -1;
                } else {
                    v[i] = s.top();
                }
            }
            s.push(arr[i]);
            i++;
        }
        return v;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int a[n];
        for(int i = 0; i < n; i++)
            cin>>a[i];

        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0; i < n; i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
