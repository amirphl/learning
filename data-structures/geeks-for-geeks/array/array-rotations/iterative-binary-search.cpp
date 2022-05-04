// https://www.geeksforgeeks.org/binary-search/

#include<bits/stdc++.h>

using namespace std;

// time O(logn) memory O(1)
int iterative_binary_search(int arr[], int n, int elem) {
    int low = 0;
    int high = n - 1;
    int mid;
    while(low <= high) {
        if (low == high) {
            if (arr[low] == elem) {
                return low;
            } else {
                return -1;
            }
        }
        if (low + 1 == high) {
            if (arr[low] == elem) {
                return low;
            } else if (arr[high] == elem) {
                return high;
            } else {
                return -1;
            }
        }
        mid = (low + high) / 2;
        if (arr[mid] == elem) {
            return mid;
        } else if (arr[mid] < elem){
            low = mid;
        } else {
            high = mid;
        }
    }
    return -1;
}

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};
    int n = sizeof(arr) / sizeof(arr[0]), j;

    for(int i = 0; i < n; i++) {
        j = iterative_binary_search(arr, n, i);
        if (i != j) {
            cout << i << " " << j << endl;
        }
    }

    cout << "find -1 : " << iterative_binary_search(arr, n, -1) << endl;
    cout << "find 0 : " << iterative_binary_search(arr, n, 0) << endl;
    cout << "find 100 : " << iterative_binary_search(arr, n, 100) << endl;
    cout << "find 101 : " << iterative_binary_search(arr, n, 101) << endl;
    cout << "find 1001 : " << iterative_binary_search(arr, n, 1001) << endl;

    return 0;
}
