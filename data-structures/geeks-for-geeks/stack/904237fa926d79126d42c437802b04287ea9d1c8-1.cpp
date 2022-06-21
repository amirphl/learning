// https://practice.geeksforgeeks.org/problems/904237fa926d79126d42c437802b04287ea9d1c8/1/

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    // time: O(n), memory: O(n)
    int minLength(string in, int n) {
        stack<char> s;
        s.push(in[0]);
        int i = 1;
        while(i < n) {
            if (!s.empty() && match(string(1, s.top()) + string(1, in[i]))) {
                s.pop();
            } else {
                s.push(in[i]);
            }
            i++;
        }
        return s.size();
    }

    bool match(string in) {
        // cout << in << endl;
        if (in == "12") {
            return true;
        }
        if (in == "21") {
            return true;
        }
        if (in == "34") {
            return true;
        }
        if (in == "43") {
            return true;
        }
        if (in == "56") {
            return true;
        }
        if (in == "65") {
            return true;
        }
        if (in == "78") {
            return true;
        }
        if (in == "87") {
            return true;
        }
        if (in == "90") {
            return true;
        }
        if (in == "09") {
            return true;
        }
        return false;
    }
};


// { Driver Code Starts.

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        Solution obj;
        cout << obj.minLength(s, n) << "\n";
    }
    return 0;
}  // } Driver Code Ends
