// https://www.geeksforgeeks.org/count-groupings-number-sum-digits-every-sub-group-less-equals-immediate-right-sub-group/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1> {}(p.first);
        auto hash2 = hash<T2> {}(p.second);

        if (hash1 != hash2) {
            return hash1 ^ hash2;
        }

        // If hash1 == hash2, their XOR is zero.
        return hash1;
    }
};

class Solution {
public:
    bool debug = false;
    int TotalCount(string str) {
        unordered_map<pair<int, int>, int, hash_pair> dp;
        return fill(dp, str, 0, 0);
    }

    int fill(unordered_map<pair<int, int>, int, hash_pair>& dp, string& str, int pos, int pre_sum) {
        if (dp.find({pos, pre_sum}) != dp.end()) {
            return dp[ {pos, pre_sum}];
        }

        int n = str.length();
        if (pos == n - 1) {
            dp[ {pos, pre_sum}] = ((str[pos] - '0') >= pre_sum) ? 1 : 0;
            if (debug)
                cout << pos << " " << pre_sum << " " << dp[ {pos, pre_sum}] << endl;
            return dp[ {pos, pre_sum}];
        }

        int i = pos;
        int s = str[i] - '0';
        i++;
        while(s < pre_sum && i < n) {
            s += (str[i] - '0');
            i++;
        }
        if (s >= pre_sum) {
            int count = 1;
            while(i < n) {
                count += fill(dp, str, i, s);
                s += (str[i] - '0');
                i++;
            }
            dp[ {pos, pre_sum}] = count;
            if (debug)
                cout << pos << " " << pre_sum << " " << dp[ {pos, pre_sum}] << endl;
            return count;
        }

        dp[ {pos, pre_sum}] = 0;
        if (debug)
            cout << pos << " " << pre_sum << " " << dp[ {pos, pre_sum}] << endl;
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.TotalCount(str);
        cout << ans <<"\n";
    }
    return 0;
}
// } Driver Code Ends
