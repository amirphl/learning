// https://www.geeksforgeeks.org/given-an-array-a-and-a-number-x-check-for-pair-in-a-with-sum-as-x/
// https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/

#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>

// TODO(amirphl) what about pairs of m elements?
// TODO(amirphl) what about finding all pairs
// (in case there is more than one pair matching the solution)

// O(nlogn)
int two_pointer(int arr[], int n, int x) {
    std::sort(arr, arr + n);

    int l = 0;
    int r = n - 1;

    while (l < r) {
        if (arr[l] + arr[r] == x) {
            // std::cout << arr[l] << " " << arr[r] << std::endl;
            return 1;
        } else if (arr[l] + arr[r] < x) {
            l++;
        } else {
            r--;
        }
    }

    return 0;
}

// O(n)
int hash_table(int arr[], int n, int x) {
    std::unordered_set<int> s;
    int temp;

    for (int i = 0; i < n; i++) {
        temp = x - arr[i];

        if (s.find(temp) != s.end()) {
            // std::cout << arr[i] << " " << temp << std::endl;
            return 1;
        }

        s.insert(arr[i]);
    }

    return 0;
}

int main() {
    // int arr[] = { 1, 4, 45, 6, 10, -8 };
    int arr[] = { 3, 4, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    // int x = 16;
    int x = 6;

    std::cout << two_pointer(arr, n, x) << std::endl;
    std::cout << hash_table(arr, n, x) << std::endl;

    return 0;
}
