#include<algorithm>
#include<iostream>

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

int main() {
    int arr[40];
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    return 0;
}
