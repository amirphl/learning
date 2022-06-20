// https://www.geeksforgeeks.org/reverse-individual-words/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // time: O(n), memory: O(1)
    string reverseWords (string s)
    {
        string res(s.length(), '.');
        int i = 0, j = 0, c = 0, n = s.length();
        while(i < n) {
            if (s[i] == '.') {
                int k = i - 1;
                while(k >= j) {
                    res[c] = s[k];
                    k--;
                    c++;
                }
                res[c] = '.';
                c++;
                j = i + 1;
            }
            i++;
        }
        int k = i - 1;
        while(k >= j) {
            res[c] = s[k];
            k--;
            c++;
        }
        j = i + 1;
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
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
// } Driver Code Ends
