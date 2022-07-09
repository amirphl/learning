// https://www.geeksforgeeks.org/newman-conway-sequence/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    // time: O(1), memory: O(1)
    int singleDigit(long long N)
    {
        string s = to_string(N);
        while(s.length() != 1) {
            int x = 0;
            for(auto& it: s) {
                x += it - 48;
            }
            s = to_string(x);
        }
        return s[0] - 48;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        int ans  = ob.singleDigit(N);
        cout<<ans<<endl;
    }
    return 0;
}  // } Driver Code Ends
