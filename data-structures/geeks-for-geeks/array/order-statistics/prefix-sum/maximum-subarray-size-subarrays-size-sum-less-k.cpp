// https://www.geeksforgeeks.org/maximum-subarray-size-subarrays-size-sum-less-k/

#include<bits/stdc++.h>

using namespace std;

// time: O(n), memory: O(1)
int find(int arr[], int n, int k) {
    int sum = 0, j = 0;
    int min_window_size = n;
    int s = -1, e = -1;

    for(int i = 0; i < n; i++) {
        if (arr[i] > k) {
            return -1;
        }

        sum += arr[i];
        if (sum > k) {
            if (i - j + 1 < min_window_size) {
                min_window_size = i - j + 1;
                s = j;
                e = i;
            }
            sum -= arr[j] + arr[i];
            j++;
            i--;
        }
    }

    int max_window_size = min_window_size - 1;

    // cout << s << " " << e << " " << max_window_size << endl;
    return max_window_size;
}

// geeks solution
int func(int arr[],
          int k, int n)
{
    // Variable declaration
    int ans = n;
    int sum = 0;
    int start = 0;
 
    // Loop till N
    for (int end = 0; end < n; end++)
    {
        // Sliding window from left
        sum += arr[end];
 
        while (sum > k) {
            // Sliding window from right
            sum -= arr[start];
            start++;
 
            // Storing sub-array size - 1
            // for which sum was greater than k
            ans = min(ans, end - start + 1);
 
            // Sum will be 0 if start>end
            // because all elements are positive
            // start>end only when arr[end]>k i.e,
            // there is an array element with
            // value greater than k, so sub-array
            // sum cannot be less than k.
            if (sum == 0)
                break;
        }
        if (sum == 0) {
            ans = -1;
            break;
        }
    }
 
    // Print the answer
    // cout << ans;
    return ans;
}

int main() {
    int arr[] = {4, 6, 2, 2, 2, 3, 7, 9, 9, 2, 3, 6, 10, 3, 1, 9, 4, 7, 10, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int k = 0; k < 100; k++) {
        int my_sol = find(arr, n, k);
        int geeks_sol = func(arr, k, n);
        if (my_sol != geeks_sol) {
            cout << my_sol << " " << geeks_sol << " " << k << endl;
        }
    }
    return 0;
}
