// https://www.geeksforgeeks.org/quickly-find-multiple-left-rotations-of-an-array/

#include<algorithm>
#include<iostream>

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

void rotate(int arr[], int n, int k) {
    for (int i = k; i < n + k; i++) {
        std::cout << arr[i % n] << " ";
    }

    std::cout << std::endl;
}

int main() {
    int n = 20;
    int arr[n];

    print(arr, n);
    rotate(arr, n, 2);
    rotate(arr, n, 4);
    rotate(arr, n, 5);
    rotate(arr, n, 7);
    rotate(arr, n, 10);

    return 0;
}
