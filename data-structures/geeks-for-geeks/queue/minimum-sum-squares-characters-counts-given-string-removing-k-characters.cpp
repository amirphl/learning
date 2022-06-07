// https://www.geeksforgeeks.org/minimum-sum-squares-characters-counts-given-string-removing-k-characters/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    // time: O(klogn), memory: O(n)
    int minValue(string s, int k) {
        unordered_map<int, int> freq;
        int i = 0, n = s.length();
        while(i < n) {
            freq[s[i]]++;
            i++;
        }
        priority_queue<vector<int>> pq;
        for(auto& it: freq) {
            pq.push({it.second, it.first});
        }
        while(k > 0) {
            int f = pq.top()[0];
            int ch = pq.top()[1];
            pq.pop();
            if (f > 0) {
                freq[ch]--;
                pq.push({f - 1, ch});
            }
            k--;
        }
        int res = 0;
        for(auto& it: freq) {
            res += pow(it.second, 2);
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        int k;
        cin>>s>>k;

        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
