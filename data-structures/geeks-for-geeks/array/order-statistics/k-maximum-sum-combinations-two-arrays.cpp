// https://www.geeksforgeeks.org/k-maximum-sum-combinations-two-arrays/
// https://www.geeksforgeeks.org/find-k-pairs-smallest-sums-two-arrays/

// approaches:
// method 1: sorting + max heap: time: O(nlogn + klogk), memory: O(k)
// method 2: partition around kth largest element + partition new array of k^2 elements around kth largest: time: O(n + k^2), memory: O(k^2)

#include<algorithm>
#include<iostream>
#include<climits>

using namespace std;

void fill_arr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] =  (rand() % 100) - 50;
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

// This solution isn't correct:
// testcase:
// arr: {1, 2, 4, 5}
// brr: {0, 3, 5, 5, 8}
void print_k_max_sum_combinations(int arr[], int brr[], int n, int m, int k) {
    std::sort(arr, arr + n);
    std::sort(brr, brr + m);
    print(arr, n);
    print(brr, m);

    int i = m - 1, j = n - 2;
    int p = m - 2, q = n - 1;
    int s1, s2, r;

    std::cout << arr[n - 1] + brr[m - 1] << " ";

    for (int u = 0; u < k - 1; u++) {
        s1 = brr[i] + arr[j];
        s2 = brr[p] + arr[q];

        if (s1 > s2) {
            r = s1;
            j--;
        } else {
            r = s2;
            q--;
        }

        if (j==-1) {
            i -= 2;
        } else if (q == -1) {
            p -= 2;
        }
        std::cout << r << " ";
    }
}

int main() {
    int arr[40];
    int brr[40];
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = sizeof(brr) / sizeof(brr[0]);
    fill_arr(arr, n);
    fill_arr(brr, m);
    int k = 10;
    // int k = 81;
    // int k = 1000;
    // int k = 1600;
    // int k = 1601;
    print_k_max_sum_combinations(arr, brr, n, m, k);
    return 0;
}
