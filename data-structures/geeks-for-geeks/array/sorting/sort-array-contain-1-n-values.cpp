// https://www.geeksforgeeks.org/sort-array-contain-1-n-values/

#include<algorithm>
#include<iostream>

// time: O(n), memory: O(1)
void sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

int main() {
    int arr[] = { 10, 7, 9, 2, 8, 3, 5, 4, 6, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    sort(arr, n);
    print(arr, n);
    return 0;
}
