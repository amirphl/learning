// https://www.geeksforgeeks.org/printing-longest-increasing-consecutive-subsequence/

#include<bits/stdc++.h>

using namespace std;

// geeks solution
// function that returns the length of the
// longest increasing subsequence
// whose adjacent element differ by 1
void longestSubsequence(int a[], int n)
{
    // stores the index of elements
    unordered_map<int, int> mp;
 
    // stores the length of the longest
    // subsequence that ends with a[i]
    int dp[n];
    memset(dp, 0, sizeof(dp));
 
    int maximum = INT_MIN;
 
    // iterate for all element
    int index = -1;
    for (int i = 0; i < n; i++) {
 
        // if a[i]-1 is present before i-th index
        if (mp.find(a[i] - 1) != mp.end()) {
 
            // last index of a[i]-1
            int lastIndex = mp[a[i] - 1] - 1;
 
            // relation
            dp[i] = 1 + dp[lastIndex];
        }
        else
            dp[i] = 1;
 
        // stores the index as 1-index as we need to
        // check for occurrence, hence 0-th index
        // will not be possible to check
        mp[a[i]] = i + 1;
 
        // stores the longest length
        if (maximum < dp[i]) {
            maximum = dp[i];
            index = i;
        }
    }
 
    // We know last element of sequence is
    // a[index]. We also know that length
    // of subsequence is "maximum". So We
    // print these many consecutive elements
    // starting from "a[index] - maximum + 1"
    // to a[index].
    for (int curr = a[index] - maximum + 1;
         curr <= a[index]; curr++)
        cout << curr << " ";
    cout << endl;
}

// my solution
// time: O(n), memory: O(n)
void print(int arr[], int n) {
    unordered_map<int, int> m;
    int max_ends_so_far = arr[0];
    int len_ends_so_far = 1;
    m[arr[0]] = 1;

    for(int i = 1; i < n; i++) {
        if (max_ends_so_far + 1 == arr[i]) {
            max_ends_so_far = arr[i];
            len_ends_so_far++;
            m[arr[i]] = len_ends_so_far;
        } else {
            if (m.find(arr[i] - 1) == m.end()) {
                m[arr[i]] = 1;
            } else {
                if (m[arr[i] - 1] + 1 > len_ends_so_far) {
                    max_ends_so_far = arr[i];
                    len_ends_so_far = m[arr[i] - 1] + 1;
                    m[arr[i]] = len_ends_so_far;
                } else {
                    m[arr[i]] = m[arr[i] - 1] + 1;
                }
            }
        }
    }

    cout << "max_ends_so_far: " << max_ends_so_far << endl;
    cout << "len_ends_so_far: " << len_ends_so_far << endl;
}

int main() {
    int arr[] = { 3, 10, 3, 11, 4, 5, 6, 7, 8, 12 };
    int n = sizeof(arr) / sizeof(arr[0]);

    print(arr, n);
    longestSubsequence(arr, n);

    int brr[] = {60, 72, 2, 75, 8, 22, 98, 87, 22, 26, 51, 13, 12, 24, 68, 93, 11, 57, 22, 45, 59, 15, 15, 82, 30, 9, 7, 58, 19, 23, 18, 64, 52, 4, 75, 81, 73, 39, 41, 6, 9, 3, 4, 80, 69, 99, 42, 2, 24, 48, 77, 72, 44, 52, 89, 39, 69, 66, 43, 34, 29, 66, 43, 69, 97, 42, 99, 82, 76, 43, 54, 28, 81, 78, 8, 27, 100, 5, 40, 53, 44, 74, 79, 45, 71, 26, 94, 19, 51, 43, 80, 14, 77, 63, 7, 91, 20, 100, 2, 37};
    n = sizeof(brr) / sizeof(brr[0]);

    print(brr, n);
    longestSubsequence(brr, n);

    return 0;
}
