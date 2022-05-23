// https://www.geeksforgeeks.org/k-maximum-sums-non-overlapping-contiguous-sub-arrays/

#include<bits/stdc++.h>

using namespace std;

// time: O(k*n), memory: O(1)
void find(int arr[], int n, int k) {
    for(int j = 0; j < k; j++) {
        int s = 0;
        int e = 0;
        int max_so_far = arr[0];
        int p = 0;
        int max_ending_here = arr[0];
        for(int i = 1; i < n; i++) {
            if (max_ending_here <= 0) {
                max_ending_here = arr[i];
                p = i;
            } else {
                max_ending_here += arr[i];
            }
            if (max_ending_here > max_so_far) {
                s = p;
                e = i;
                max_so_far = max_ending_here;
            }
        }
        for(int i = s; i <= e; i++) {
            arr[i] = INT_MIN;
        }
        cout << s << " " << e << endl;
    }
}

int main() {
    int arr[] = {4, 1, 1, -1, -3, -5, 6, 2, -6, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 10;
    find(arr, n, k);
    return 0;
}
