// https://www.geeksforgeeks.org/maximum-difference-zeros-ones-binary-string/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:
    // time: O(n), memory: O(1)
    int maxSubstring(string S)
    {
        int n = S.length();
        int max_so_far = S[0] == '0' ? 1 : -1;
        int max_ending_here = S[0] == '0' ? 1 : -1;
        int i = 1;
        while(i < n) {
            int c = S[i] == '0' ? 1 : -1;
            max_ending_here = max_ending_here < 0 ? c : c + max_ending_here;
            max_so_far = max(max_so_far, max_ending_here);
            i++;
        }
        return max_so_far;
    }
};

// { Driver Code Starts.

int main()
{


    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;

        Solution ob;

        cout << ob.maxSubstring(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends
