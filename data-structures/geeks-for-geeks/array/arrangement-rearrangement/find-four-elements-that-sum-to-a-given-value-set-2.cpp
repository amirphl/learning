// https://www.geeksforgeeks.org/find-four-elements-that-sum-to-a-given-value-set-2/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

struct hash_function
{
    size_t operator()(const vector<int>
                      &myVector) const
    {
        std::hash<int> hasher;
        size_t answer = 0;

        for (int i : myVector)
        {
            answer ^= hasher(i) + 0x9e3779b9 +
                      (answer << 6) + (answer >> 2);
        }
        return answer;
    }
};

class Solution {
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    // time: O(n*n), memory: O(n*n)
    // not works
    vector<vector<int>> fourSum2(vector<int> &arr, int k) {
        int n = arr.size(), s = n * (n - 1) / 2;
        sort(arr.begin(), arr.end());
        int temp[s][3]; // TODO convert to 1D
        int i = 0, c = 0;
        while(i < n) {
            int j = 0;
            while(j < i) {
                temp[c][0] = arr[i] + arr[j];
                temp[c][1] = i;
                temp[c][2] = j;
                c++;
                j++;
            }
            i++;
        }
        set<vector<int>> unique;
        i = 0;
        int j = s - 1;
        while(i < j) {
            if (temp[i][0] + temp[j][0] < k) {
                i++;
            } else if (temp[i][0] + temp[j][0] == k) {
                int p = temp[i][1];
                int q = temp[i][2];
                int u = temp[j][1];
                int v = temp[j][2];
                if (p != u && p != v && q != u && q != v) {
                    vector<int> sol = {arr[p], arr[q], arr[u], arr[v]};
                    sort(sol.begin(), sol.end());
                    unique.insert(sol);
                }
                i++;
            } else {
                j--;
            }
        }
        vector<vector<int>> res;
        for(auto& x: unique) {
            res.push_back(x);
        }
        return res;
    }

    // time: O(n*n*n*logn), memory: O(n*n)
    vector<vector<int>> fourSum(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        set<vector<int>> unique;
        int i = 0, n = arr.size();
        while(i < n) {
            int j = i + 1;
            while(j < n) {
                int x = arr[i] + arr[j];
                int y = k - x;
                int u = j + 1;
                int v = n - 1;
                while(u < v) {
                    if (arr[u] + arr[v] < y) {
                        u++;
                    } else if (arr[u] + arr[v] == y) {
                        // res.push_back({arr[i], arr[j], arr[u], arr[v]});
                        unique.insert({arr[i], arr[j], arr[u], arr[v]});
                        u++;
                        v--;
                    } else {
                        v--;
                    }
                }
                j++;
            }
            i++;
        }
        // for(auto& x: unique) {
        for(auto x: unique) {
            sort(x.begin(), x.end());
            res.push_back(x);
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
