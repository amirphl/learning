// https://www.geeksforgeeks.org/power-set/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(n*pow(2,n)), memory: O(pow(2,n))
    vector<string> AllPossibleStrings(string s) {
        int n = s.length();
        int size = pow(2, n) - 1;
        vector<string> res(size);
        int j = 0;
        fill(res, j, s, 0, "", n);
        sort(res.begin(), res.end());
        return res;
    }

    void fill(vector<string>& res, int& j, string& s, int i, string gen, int& n) {
        if (i == n) {
            if (gen.empty()) {
                return;
            }
            res[j] = gen;
            j++;
            return;
        }
        fill(res, j, s, i + 1, gen, n);
        fill(res, j, s, i + 1, gen + s[i], n);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        string s;
        cin >> s;
        Solution ob;
        vector<string> res = ob.AllPossibleStrings(s);
        for(auto i : res)
            cout << i <<" ";
        cout << "\n";

    }
    return 0;
}
// } Driver Code Ends
