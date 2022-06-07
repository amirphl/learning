// https://www.geeksforgeeks.org/first-negative-integer-every-window-size-k/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
        long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

// time: O(n), memory: O(n)
vector<long long> printFirstNegativeInteger(long long int A[],
        long long int N, long long int K) {
    vector<long long int> v;
    long long int i = 0;
    queue<vector<long long int>> q;
    while(i < N) {
        if (A[i] < 0) {
            q.push({A[i], i});
        }
        if (K - 1 <= i) {
            if (q.empty()) {
                // cout << " + " << i << endl;
                v.push_back(0);
            } else if (i - K + 1 == q.front()[1]) {
                // cout << " _ " << i << endl;
                v.push_back(q.front()[0]);
                q.pop();
            } else if (i - K + 1 < q.front()[1] && q.front()[1] < i + 1) {
                // cout << " = " << i << endl;
                v.push_back(q.front()[0]);
            } else {
                // cout << " * " << i << endl;
                v.push_back(0);
            }
        }
        i++;
    }
    return v;
}
