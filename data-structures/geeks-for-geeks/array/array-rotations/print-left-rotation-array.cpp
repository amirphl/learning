#include<algorithm>
#include<iostream>

void print(int arr[], int n, int k) {
    k = k % n;

    for (int i = k; i < n + k; i++) {
        std::cout << arr[i % n] << " ";
    }

    std::cout << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int k[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = sizeof(k) / sizeof(k[0]);

    for (int i = 0; i < m; i++) {
        print(arr, n, i);
    }

    return 0;
}
