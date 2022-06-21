// https://www.geeksforgeeks.org/decode-string-recursively-encoded-count-followed-substring/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // time: O(n), memory: O(n)
    string decodedString(string in) {
        int i = 0, n = in.length();
        stack<string> s;
        while(i < n) {
            char ch = in[i];
            if (47 < ch && ch < 58) {
                int j = i + 1;
                while(47 < in[j] && in[j] < 58) { // i < n no need to check
                    j++;
                }
                s.push(in.substr(i, j - i));
                i = j - 1;
            } else if (ch == '[') {
                s.push("[");
            } else if (ch == ']') {
                string res = "";
                string mid = "";
                while(s.top() != "[") {
                    mid = s.top() + mid;
                    s.pop();
                }
                s.pop();
                int j = 0;
                while(j < stoi(s.top())) {
                    res += mid;
                    j++;
                }
                s.pop();
                s.push(res);
            } else {
                s.push(string(1, ch));
            }
            i++;
        }
        return s.top();
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;

        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
