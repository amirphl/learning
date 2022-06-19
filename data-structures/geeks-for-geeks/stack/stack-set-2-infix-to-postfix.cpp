// https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/

// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    //Function to convert an infix expression to a postfix expression.
    std::map<char, int> m;
    std::stack<char> s;
    string res;


    Solution() {
        m[')'] = 2;
        m['-'] = 3;
        m['+'] = 3;
        m['/'] = 5;
        m['*'] = 5;
        m['^'] = 7;
        m['('] = 8;
    }

    void add() {
        if (s.empty())
            return;
        char t = s.top();
        s.pop();
        add();
        res.push_back(t);
    }

    // time: O(n), memory: O(n)
    string infixToPostfix(string in) {
        char c;

        for (int i = 0; i < in.size(); i++) {
            c = in[i];
            if (m[c] == 0) {
                res.push_back(c);
                continue;
            }
            while(!s.empty() && m[s.top()] >= m[c] && m[s.top()] != 8) {
                res.push_back(s.top());
                s.pop();
            }
            s.push(c);
            if (m[c] == 2) {
                s.pop();
                s.pop();
            }
        }

        add();

        return res;
    }
};


// { Driver Code Starts.
//Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string exp;
        cin>>exp;
        Solution ob;
        cout<<ob.infixToPostfix(exp)<<endl;
    }
    return 0;
}
// } Driver Code Ends
