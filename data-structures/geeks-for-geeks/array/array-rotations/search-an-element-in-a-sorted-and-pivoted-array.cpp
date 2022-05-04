// https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
// TODO(amirphl) How to handle duplicates?

#include<algorithm>
#include<iostream>

// time: O(logn), memory: O(1)
int binary_pivot_search(int arr[], int low, int high, int elem) {
    if (high - low < 0)
        return -1;

    if (high == low) {
        if (arr[low] == elem)
            return low;
        return -1;
    }

    if (high == low + 1) {
        if (arr[low] == elem)
            return low;
        if (arr[high] == elem)
            return high;
        return -1;
    }

    int mid = (high + low) / 2;

    if (arr[mid] == elem)
        return mid;

    if (arr[low] < arr[mid - 1]) {
        if (arr[low] <= elem && elem <= arr[mid - 1])
            return binary_pivot_search(arr, low, mid - 1, elem);
        return binary_pivot_search(arr, mid + 1, high, elem);
    } else {
         if (arr[mid + 1] <= elem && elem <= arr[high])
            return binary_pivot_search(arr, mid + 1, high, elem);
         return binary_pivot_search(arr, low, mid - 1, elem);
    }

    return -1;
}

int main() {
    int arr[] = { 4, 5, 6, 7, 8, 9, 1, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 6;

    int index = binary_pivot_search(arr, 0, n - 1, key);
    std::cout << index << std::endl;

    return 0;
}
