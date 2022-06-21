// https://www.geeksforgeeks.org/find-index-closing-bracket-given-opening-bracket-expression/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    // time: O(n), memory: O(1)
    int closing (string arr, int pos)
    {
        int i = pos + 1, n = arr.length();
        int c = 0;
        while(i < n) {
            if (arr[i] == '[') {
                c++;
            }
            if (arr[i] == ']') {
                if (c == 0)
                    return i;
                c--;
            }
            i++;
        }
        return -1;
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
        int pos;
        cin >> pos;
        Solution ob;
        cout <<ob.closing (s, pos) << '\n';
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends
