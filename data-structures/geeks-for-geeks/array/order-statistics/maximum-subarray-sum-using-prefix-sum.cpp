// https://www.geeksforgeeks.org/maximum-subarray-sum-using-prefix-sum/

#include<bits/stdc++.h>
using namespace std;

// time: O(n), memory: O(1)
void find(int arr[], int n) {
    int pre[n];
    pre[0] = arr[0];

    for(int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + arr[i];
    }

    int min_pre_so_far = pre[0];
    int max_so_far = arr[0];

    for(int i = 1; i < n; i++) {
        max_so_far = max(pre[i] - min_pre_so_far, max_so_far);
        min_pre_so_far = min(pre[i], min_pre_so_far);
    }
    cout << max_so_far << endl;
}

int main() {
    int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    find(arr, n);

    int arr2[] = { 4, -8, 9, -4, 1, -8, -1, 6 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    find(arr2, n2);

    return 0;
}
