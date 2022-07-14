// https://www.geeksforgeeks.org/minimum-cost-to-fill-given-weight-in-a-bag/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution {
public:
    // time: O(n*w), memory: O(w)
    int minimumCost(int cost[], int N, int W)
    {
        int* dp = new int[W + 1];
        int* prv = new int[W + 1];
        int i = 0;
        while(i < N) {
            dp[0] = 0;
            int j = 1;
            while(j <= W) {
                if (cost[i] == -1 || j < i + 1) {
                    dp[j] = i > 0 ? prv[j] : -1;
                } else {
                    int x = cost[i] + dp[j - i - 1];
                    int y = i > 0 ? prv[j] : -1;
                    dp[j] = min(x, y);
                    if (dp[j - i - 1] == -1 && y != -1) {
                        dp[j] = y;
                    }
                    if (dp[j - i - 1] != -1 && y == -1) {
                        dp[j] = x;
                    }
                }
                j++;
            }
            int* temp = prv;
            prv = dp;
            dp = temp;
            i++;
        }
        // delete allocated arrays
        return prv[W];
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
            cin >> a[i];



        Solution ob;
        cout << ob.minimumCost(a, n, w) << "\n";

    }
    return 0;
}  // } Driver Code Ends
