// https://www.geeksforgeeks.org/find-the-element-before-which-all-the-elements-are-smaller-than-it-and-after-which-all-are-greater-than-it/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends

// time: O(nlogn), memory: O(1)

// time: O(n), memory: O(n)
int findElement(int arr[], int n) {
    int s[n][2];
    int i = 0, min_seen = arr[n - 1], max_seen = arr[0];
    while(i < n) {
        min_seen = min(min_seen, arr[n - 1 - i]);
        max_seen = max(max_seen, arr[i]);
        s[n - 1 - i][0] = min_seen;
        s[i][1] = max_seen;
        i++;
    }
    // if (arr[0] < s[1][0]) {
    //     return arr[0];
    // }
    i = 1;
    while(i < n - 1) {
        if (s[i - 1][1] <= arr[i] && arr[i] <= s[i + 1][0]) {
            return arr[i];
        }
        i++;
    }
    // if (s[n - 2][1] < arr[n - 1]) {
    //     return arr[n - 1];
    // }
    return -1;
}
