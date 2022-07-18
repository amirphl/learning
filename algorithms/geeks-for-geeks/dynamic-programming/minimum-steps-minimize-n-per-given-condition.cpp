// https://www.geeksforgeeks.org/minimum-steps-minimize-n-per-given-condition/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(n), memory: O(n)
    int minSteps(int N)
    {
        int dp[N + 1];
        dp[1] = 0;
        int i = 2;
        while(i < N + 1) {
            dp[i] = 1 + min({
                dp[i - 1],
                i % 2 == 0 ? dp[i / 2] : INT_MAX,
                i % 3 == 0 ? dp[i / 3] : INT_MAX
            });
            i++;
        }
        return dp[N];
    }
};


//{ Driver Code Starts.
int main()
{


    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;



        Solution ob;
        cout << ob.minSteps(n) << "\n";

    }
    return 0;
}


// } Driver Code Ends
