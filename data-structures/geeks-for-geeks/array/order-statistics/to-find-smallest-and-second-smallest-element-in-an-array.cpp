// https://www.geeksforgeeks.org/to-find-smallest-and-second-smallest-element-in-an-array/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> minAnd2ndMin(int a[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> ans = minAnd2ndMin(a, n);
        if (ans[0] == -1)
            cout << -1 << endl;
        else
            cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}
// } Driver Code Ends

// time: O(n), memory: O(1)
vector<int> minAnd2ndMin(int arr[], int n) {
    int a = arr[0];
    int b;
    int i = 1;
    while(i < n && arr[i] == a) {
        i++;
    }
    if (i == n) {
        return {-1};
    }
    if (arr[i] > a) {
        b = arr[i];
    } else {
        b = a;
        a = arr[i];
    }
    i++;
    while(i < n) {
        if (arr[i] < a) {
            b = a;
            a = arr[i];
        } else if (a < arr[i] && arr[i] < b) {
            b = arr[i];
        }
        i++;
    }
    return {a, b};
}
