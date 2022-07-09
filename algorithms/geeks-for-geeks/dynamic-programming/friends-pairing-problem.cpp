// https://www.geeksforgeeks.org/friends-pairing-problem/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // time: O(n), memory: O(1)
    int countFriendsPairings(int n)
    {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        long long x = 1, y = 2;
        int i = 3, rem = 1e9 + 7;
        while(i <= n) {
            long long temp = y;
            y = (y + (i - 1) * x) % rem;
            x = temp;
            i++;
        }
        return y;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout <<ob.countFriendsPairings(n);
        cout<<endl;
    }
}
// } Driver Code Ends
