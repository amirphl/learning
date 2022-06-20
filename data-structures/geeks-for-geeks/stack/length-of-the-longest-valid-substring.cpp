// https://www.geeksforgeeks.org/length-of-the-longest-valid-substring/

// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
public:
    // This doesn't work!
    int findMaxLen2(string s) {
        int i = 0, n = s.length();
        while(i < n && s[i] == ')') {
            i++;
        }
        int j = i;
        int c = 0, res = 0;
        while(i < n) {
            if (s[i] == '(') {
                c += 1;
            } else {
                c -= 1;
            }
            if (c == 0) {
                res = max(res, j - i + 1);
            }
            i++;
        }
        return res;
    }

    // time: O(n), memory: O(n)
    int findMaxLen(string in) {
        int i = 0, n = in.length();
        while(i < n && in[i] == ')') {
            i++;
        }
        int res = 0;
        stack<int> s;
        s.push(-1);
        i++;
        while(i < n) {
            if (in[i] == '(') {
                s.push(-1);
            } else {
                if (s.top() == -2) {
                    s.push(-2);
                } else {
                    int x = 0;
                    int y = 1;
                    if (s.top() == -1) {
                        x += 2;
                        s.pop();
                        y--;
                    }
                    while(!s.empty() && s.top() > -1) {
                        x += s.top();
                        s.pop();
                        if(!s.empty() && s.top() == -1 && y == 1) {
                            x += 2;
                            s.pop();
                            y--;
                        }
                    }
                    s.push(x);
                    res = max(res, x);
                    if (y == 1) {
                        s.push(-2);
                    }
                }
            }
            i++;
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
// } Driver Code Ends
