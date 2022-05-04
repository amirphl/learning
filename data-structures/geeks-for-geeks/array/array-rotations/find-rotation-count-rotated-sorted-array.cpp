// https://www.geeksforgeeks.org/find-rotation-count-rotated-sorted-array/
// TODO(amirphl) How to handle arrays with duplicates?

#include<algorithm>
#include<iostream>

// time: O(logn), memory: O(logn)
int find_k(int arr[], int l, int r) {
    // std::cout << l << " " << r << " " << std::endl;
    if (r < l)
        return -1;

    if (l == r)
        return 0;

    if (l == r - 1)
        return (arr[l] < arr[r]) ? 0 : 1;

    int mid = (l + r) / 2;

    if (arr[mid] > arr[mid + 1])
        return mid + 1;

    if (arr[l] < arr[mid]) {
        return find_k(arr, mid, r);
    } else {
        return find_k(arr, l, mid);
    }
}

int main() {
    int arr[] = {15, 18, 2, 3, 6, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << find_k(arr, 0, n - 1) << std::endl;

    int arr2[] = {7, 9, 11, 12, 5};
    n = sizeof(arr2) / sizeof(arr2[0]);

    std::cout << find_k(arr2, 0, n - 1) << std::endl;

    int arr3[] = {7, 9, 11, 12, 15};
    n = sizeof(arr3) / sizeof(arr3[0]);

    std::cout << find_k(arr3, 0, n - 1) << std::endl;

    return 0;
}
