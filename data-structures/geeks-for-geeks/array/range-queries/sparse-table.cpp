// https://www.geeksforgeeks.org/sparse-table/
// TODO(amirphl) sparse tabel with dynamic data?

// gcd properties:
// gcd(a, b, c) = gcd(gcd(a, b), c) = gcd(a, gcd(b, c)) = gcd((a, c), b) = gcd((a, b), (b, c))

// note: It works because GCD on repetitive elements results in the same answer! Also MIN.

#include <algorithm>
#include <iostream>
#include <cmath>
#include <climits>
#define MAX 200

int t[MAX][MAX];
int gcd[MAX][MAX];

void print_t(int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            std::cout << t[i][j] << " ";
        std::cout << std::endl;
    }
}

void print_gcd(int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            std::cout << gcd[i][j] << " ";
        std::cout << std::endl;
    }
}

// time: O(nlogn), memory: O(nlogn)
void fill_min(int arr[], int n, int m) {
    for(int i = 0; i < n; i++)
        t[i][0] = arr[i];

    for(int i = n - 1; i >= 0; i--) {
        for (int j = 1; j < m; j++) {
            int p = t[i][j - 1]; // i ---> i + pow(2, j - 1) - 1
            int q = t[i + int(pow(2, j - 1))][j - 1]; // i + pow(2, j - 1) ---> i + pow(2, j) - 1
            t[i][j] = std::min(p, q);
        }
    }
}

// time: O(nlogn), memory: O(nlogn)
void fill_gcd(int arr[], int n, int m) {
    for(int i = 0; i < n; i++)
        gcd[i][0] = arr[i];

    for(int i = n - 1; i >= 0; i--) {
        for (int j = 1; j < m; j++) {
            int p = gcd[i][j - 1]; // i ---> i + pow(2, j - 1) - 1
            int q = gcd[i + int(pow(2, j - 1))][j - 1]; // i + pow(2, j - 1) ---> i + pow(2, j) - 1
            gcd[i][j] = std::__gcd(p, q);
        }
    }
}

// Inclusive
// time: O(1), memory: O(1)
int query_min(int low, int high) {
    if (low > high)
        return INT_MIN;

    int diff = high - low + 1;
    int p = int(log2(diff));
    int q = int(pow(2, p));

    return std::min(t[low][p], t[high - q + 1][p]);
}

// Inclusive
// time: O(1), memory: O(1)
int query_gcd(int low, int high) {
    if (low > high)
        return INT_MIN;

    int diff = high - low + 1;
    int p = int(log2(diff));
    int q = int(pow(2, p));

    return std::__gcd(gcd[low][p], gcd[high - q + 1][p]);
}

int main() {
    int arr[] = {12, 13, 6, 18, 2, 12, 15, 11, 11, 12, 14, 11, 15, 17, 12, 11, 20, 17, 14, 5, -1, 0,-2, 5, 6, -3, 13, 3, 10, 11, 8, 15, 1, 14, 5, 6, 13, 13, 9, 1, 7, 2, 3, 10, 12, 1, 15, 6, 15, 19, 17, 3, 2, 6, 13, 17, 9, 5, 8, 1, 13, 19, 17, 20, 20, 19, 3, 1, 9, 10, 19, 1, 5, 5, 5, 9, 12, 9, 8, 19, 9, 15, 18, 7, 14, 6, 11, 8, 14, 3, 5, 15, 19, 8, 10, 1, 7, 8, 17, 14, 3, 7, 15, 3, 14, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = int(log2(n)) + 2;
    fill_min(arr, n, m);
    fill_gcd(arr, n, m);
    std::cout << "t:   --------------\n";
    print_t(n, m);
    std::cout << "gcd: --------------\n";
    print_gcd(n, m);
    std::cout << "query min --------------\n";
    std::cout << query_min(0,  20)  << std::endl;
    std::cout << query_min(5,  20)  << std::endl;
    std::cout << query_min(7,  27)  << std::endl;
    std::cout << query_min(14, 37)  << std::endl;
    std::cout << query_min(30, 40)  << std::endl;
    std::cout << query_min(34, 34)  << std::endl;
    std::cout << query_min(39, 49)  << std::endl;
    std::cout << query_min(45, 69)  << std::endl;
    std::cout << query_min(51, 52)  << std::endl;
    std::cout << query_min(55, 105) << std::endl;
    std::cout << query_min(0,  105) << std::endl;
    std::cout << "query gcd --------------\n";
    std::cout << query_gcd(0, 0) << std::endl;
    std::cout << query_gcd(0, 4) << std::endl;
    std::cout << query_gcd(4, 7) << std::endl;
    std::cout << query_gcd(7, 8) << std::endl;
    std::cout << query_gcd(8, 8) << std::endl;
    std::cout << query_gcd(0, 8) << std::endl;

    return 0;
}
