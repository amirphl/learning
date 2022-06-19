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
