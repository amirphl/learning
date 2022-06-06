// https://www.geeksforgeeks.org/queue-based-approach-for-first-non-repeating-character-in-a-stream/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(n), memory: O(26)
    string FirstNonRepeating(string A) {
        string res = "";
        queue<char> q;
        int freq[26] = {0};
        int i = 0, n = A.length();
        while(i < n) {
            char ch = A[i];
            freq[ch - 'a']++;
            if (freq[ch - 'a'] == 1) {
                q.push(ch);
            }
            while(!q.empty() && freq[q.front() - 'a'] != 1) {
                q.pop();
            }
            if (q.empty()) {
                res+='#';
            } else {
                res += q.front();
            }
            i++;
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
