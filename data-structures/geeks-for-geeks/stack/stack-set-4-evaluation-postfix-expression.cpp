// https://www.geeksforgeeks.org/stack-set-4-evaluation-postfix-expression/

// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    //Function to evaluate a postfix expression.
    // time: O(n), memory: O(n)
    int evaluatePostfix(string S)
    {
        stack<int> s;
        int i = 0, n = S.length();
        while(i < n) {
            int ch = S[i];
            if (is_oprator(ch)) {
                int o1 = s.top();
                s.pop();
                int o2 = s.top();
                s.pop();
                s.push(eval(o2, o1, ch));
            } else {
                s.push(ch - 48);
            }
            i++;
        }
        return s.top();
    }

    bool is_oprator(int ch) {
        return ch == '-' || ch == '+' || ch == '*' || ch == '/';
    }

    int eval(int o1, int o2, int op) {
        if (op == '-') {
            return o1 - o2;
        }
        if (op == '+') {
            return o1 + o2;
        }
        if (op == '/') {
            return o1 / o2;
        }
        if (op == '*') {
            return o1 * o2;
        }
        return INT_MAX;
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;

        cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
// } Driver Code Ends
