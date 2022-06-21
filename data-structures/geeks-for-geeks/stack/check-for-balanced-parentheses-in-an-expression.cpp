// https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}// } Driver Code Ends

// time: O(n), memory: O(1)
bool valid(string s)
{
    int v1 = 0, v2 = 0, v3 = 0;
    int i = 0, n = s.length();
    while(i < n) {
        if (s[i] == '(') {
            v1++;
        } else if (s[i] == ')') {
            v1--;
        } else if (s[i] == '[') {
            v2++;
        } else if (s[i] == ']') {
            v2--;
        } else if (s[i] == '{') {
            v3++;
        } else if (s[i] == '}') {
            v3--;
        }
        if (v1 < 0 || v2 < 0 || v3 < 0) {
            return false;
        }
        i++;
    }
    return v1 == 0 && v2 == 0 && v3 == 0;
}

// This solution supports strings like [(])
// link to practice: https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1/
class Solution
{
public:
    //Function to check if brackets are balanced or not.
    // time: O(n), memory: O(n)
    bool ispar(string x)
    {
        stack<char> s;
        int i = 0, n = x.length();
        while(i < n) {
            if (x[i] == ')') {
                if (s.empty() || s.top() != '(') {
                    return false;
                }
                s.pop();
            } else if (x[i] == '}') {
                if (s.empty() || s.top() != '{') {
                    return false;
                }
                s.pop();
            } else if (x[i] == ']') {
                if (s.empty() || s.top() != '[') {
                    return false;
                }
                s.pop();
            } else {
                s.push(x[i]);
            }
            i++;
        }
        return s.empty();
    }

};
