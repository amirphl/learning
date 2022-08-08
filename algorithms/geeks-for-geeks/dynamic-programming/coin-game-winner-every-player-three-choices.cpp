// https://www.geeksforgeeks.org/coin-game-winner-every-player-three-choices/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

public:
    // time: O(n), memory: O(n)
    int findWinner(int N, int X, int Y)
    {
        bool dp[N + 1];
        dp[0] = false;
        int i = 1;
        while(i < N + 1) {
            dp[i] = false;
            if (i - X >= 0 && !dp[i - X]) {
                dp[i] = true;
            }
            if (i - Y >= 0 && !dp[i - Y]) {
                dp[i] = true;
            }
            if (!dp[i - 1]) {
                dp[i] = true;
            }
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
        int n, x, y;
        cin >> n >> x >> y;



        Solution ob;
        cout << ob.findWinner(n, x, y);
        cout << "\n";

    }
    return 0;
}
// } Driver Code Ends
