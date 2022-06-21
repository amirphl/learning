// https://www.geeksforgeeks.org/reversing-an-equation/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // time: O(n), memory: O(n)
    string reverseEqn(string s)
    {
        unordered_set<char> op({'+', '-', '*', '/'});
        stack<string> stk;
        int i = 0, n = s.length();
        while(i < n) {
            int p = i;
            if (op.find(s[i]) == op.end()) {
                while(op.find(s[i]) == op.end() && i < n) {
                    i++;
                }
                i--;
            }
            stk.push(s.substr(p, i - p + 1));
            i++;
        }
        string res = "";
        while(!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends
