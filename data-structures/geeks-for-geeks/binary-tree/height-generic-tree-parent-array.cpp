// https://www.geeksforgeeks.org/height-generic-tree-parent-array/

#include<bits/stdc++.h>

using namespace std;

// time: O(n), memory: O(n)
int main() {
    int arr[] = {-1, 0, 0, 0, 3, 1, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int h[n];
    // memset(h, INT_MAX, sizeof(h));
    int i = 0, min_h = 0, max_h = 0;
    while(i < n) {
        h[i] = INT_MAX;
        i++;
    }
    i = 0;
    while(i < n) {
        // cout << h[i] << endl;
        if (arr[i] == -1) {
            i++;
            continue;
        }
        if (h[i] == INT_MAX && h[arr[i]] == INT_MAX) {
            h[arr[i]] = 1;
            h[i] = 0;
        } else if (h[i] == INT_MAX) {
            h[i] = h[arr[i]] - 1;
        } else {
            h[arr[i]] = h[i] + 1;
        }
        min_h = min({min_h, h[i], h[arr[i]]});
        max_h = max({max_h, h[i], h[arr[i]]});
        i++;
    }
    i = 0;
    while(i < n) {
        cout << h[i] << " ";
        i++;
    }
    cout << endl;
    cout << min_h << " " << max_h;
    cout << endl;
    return 0;
}
