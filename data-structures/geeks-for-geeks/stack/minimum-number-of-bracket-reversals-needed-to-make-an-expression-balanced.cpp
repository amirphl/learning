// https://www.geeksforgeeks.org/minimum-number-of-bracket-reversals-needed-to-make-an-expression-balanced/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends


// time: O(n), memory: O(1)
int countRev(string s)
{
    int n = s.length();
    if (n % 2 == 1) {
        return -1;
    }
    int p = 0, j = 1;
    int res = 0;
    for(int i = 0; i < n; i++, j++) {
        if (s[i] == '}') {
            p++;
            if (j / 2 < p) {
                res++;
                p--;
            }
        }
        // cout << res << " " << p << " " << j << " " << endl;
    }
    if (n / 2 != p) {
        res += n / 2 - p;
    }
    return res;
}
