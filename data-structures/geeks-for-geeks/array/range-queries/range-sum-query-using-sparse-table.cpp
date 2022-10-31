// https://www.geeksforgeeks.org/range-sum-query-using-sparse-table/

#include <algorithm>
#include <iostream>
#include <cmath>
#include <climits>

int t[100][100];

void print_t(int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            std::cout << t[i][j] << " ";
        std::cout << std::endl;
    }
}

// time: O(nlogn), memory: O(nlogn)
void fill_sum(int arr[], int n, int m) {
    for(int i = 0; i < n; i++)
        t[i][0] = arr[i];

    for(int i = n - 1; i >= 0; i--) {
        for (int j = 1; j < m; j++) {
            int p = t[i][j - 1]; // i ---> i + pow(2, j - 1) - 1
            int q = t[i + int(pow(2, j - 1))][j - 1]; // i + pow(2, j - 1) ---> i + pow(2, j) - 1
            t[i][j] = p + q;
        }
    }
}

// Inclusive
// time: O(logn), memory: O(1)
int query_sum(int low, int high) {
    if (low > high)
        return 0;

    int diff = high - low + 1;
    int p = int(log2(diff));
    int q = int(pow(2, p));

    return t[low][p] + query_sum(low + pow(2, p), high);
}

int main() {
    int arr[] = {7, 2, 3, 1, 5, 10, 3, 12, 18, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = int(log2(n)) + 2;
    fill_sum(arr, n, m);
    print_t(n, m);
    std::cout << query_sum(0, 5) << std::endl;
    std::cout << query_sum(3, 5) << std::endl;
    std::cout << query_sum(2, 4) << std::endl;
    std::cout << query_sum(0, 4) << std::endl;
    std::cout << query_sum(0, 8) << std::endl;
    std::cout << query_sum(3, 8) << std::endl;
    std::cout << query_sum(8, 9) << std::endl;
    std::cout << query_sum(9, 9) << std::endl;
    std::cout << query_sum(0, 0) << std::endl;
    std::cout << query_sum(4, 8) << std::endl;

    return 0;
}
