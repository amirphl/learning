// https://www.geeksforgeeks.org/find-whether-an-array-is-subset-of-another-array-set-1/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends

// time: O(n + m), memory: O(n + m)
string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, int> freq;
    int i = 0;
    while(i < n) {
        freq[a1[i]]++;
        i++;
    }
    i = 0;
    while(i < m) {
        if (freq[a2[i]] == 0) {
            return "No";
        } else {
            freq[a2[i]]--;
        }
        i++;
    }
    return "Yes";
}
