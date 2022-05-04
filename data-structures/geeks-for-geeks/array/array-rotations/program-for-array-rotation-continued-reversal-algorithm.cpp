// https://www.geeksforgeeks.org/program-for-array-rotation-continued-reversal-algorithm/
// https://www.geeksforgeeks.org/reversal-algorithm-right-rotation-array/

#include<algorithm>
#include<iostream>

// time: O(n), memory: O(1)
void rotate(int arr[], int n, int d) {
    std::reverse(arr, arr + n - d);
    std::reverse(arr + n - d, arr + n);
    std::reverse(arr, arr + n);
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 1, 2, 3, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 8;

    print(arr, n);
    rotate(arr, n, d);
    print(arr, n);

    return 0;
}
