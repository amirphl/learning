// https://practice.geeksforgeeks.org/problems/8c8f95810b05b4cab665f2997d36991bd58308a2/1/

// { Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // time: O(n), memory: O(n)
    string Reduced_String(int k, string in) {
        if (k == 1) {
            return "";
        }
        stack<vector<int>> s;
        int i = 0, n = in.length();
        while(i < n) {
            if (s.empty()) {
                s.push({in[i], 1});
                i++;
                continue;
            }
            char ch = s.top()[0];
            int f = s.top()[1];
            if (ch == in[i]) {
                s.pop();
                if (k - 1 == f) {
                } else {
                    s.push({ch, f + 1});
                }
            } else {
                s.push({in[i], 1});
            }
            i++;
        }
        string res = "";
        while(!s.empty()) {
            char ch = s.top()[0];
            int f = s.top()[1];
            s.pop();
            while(f > 0) {
                res += ch;
                f--;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }


};

// { Driver Code Starts.

int main() {


    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";

    }

    return 0;
}  // } Driver Code Ends
