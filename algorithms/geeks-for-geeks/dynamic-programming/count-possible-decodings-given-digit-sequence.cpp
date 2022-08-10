// https://www.geeksforgeeks.org/count-possible-decodings-given-digit-sequence/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(n), memory: O(1)
    int CountWays(string str) {
        int n = str.length();
        if (n == 1) {
            if (str[0] == '0') {
                return 0;
            }
            return 1;
        }
        int two = stoi(str.substr(n - 2, 2));
        int nxt_nxt = str[n - 1] == '0' ? 0 : 1;
        int nxt;
        if (two <= 26) {
            if (two < 10) {
                nxt = 0;
            } else if (two == 10 || two == 20) {
                nxt = 1;
            } else {
                nxt = 2;
            }
        } else {
            if (two % 10 == 0) {
                nxt = 0;
            } else {
                nxt = 1;
            }
        }
        int i = n - 3, mod = 1e9 + 7, curr = nxt;
        while(i >= 0) {
            if (str[i] == '0') {
                curr = 0;
            } else {
                curr = nxt;
                two = stoi(str.substr(i, 2));
                if (two <= 26) {
                    curr = (curr + nxt_nxt) % mod;
                }
            }
            nxt_nxt = nxt;
            nxt = curr;
            i--;
        }
        return curr;
    }

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.CountWays(str);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
