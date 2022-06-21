// https://www.geeksforgeeks.org/print-bracket-number/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:
    // time: O(n), memory: O(n)
    vector<int> barcketNumbers(string S)
    {
        vector<int> v;
        int i = 0, n = S.length(), c = 0;
        stack<vector<int>> s;
        while(i < n) {
            if (S[i] == '(') {
                c++;
                s.push({'(', c});
                v.push_back(c);
            }
            if (S[i] == ')') {
                int x = s.top()[1];
                s.pop();
                v.push_back(x);
            }
            i++;
        }
        return v;
    }
};

// { Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while(t--)
    {
        string s;
        getline(cin, s);

        Solution ob;

        vector<int> ans = ob.barcketNumbers(s);

        for(auto i:ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends
