// https://www.geeksforgeeks.org/array-rotation/
#include<algorithm>
#include<iostream>

// my wrong solution
void left_rotate_2(int arr[], int d, int n) {
    d = d % n;

    if (d == 0)
        return;

    int index = n - d;
    int temp = arr[index];
    arr[index] = arr[0];

    int swap;

    do {
        index -= d;

        if (index < 0)
            index += n;

        swap = temp;
        temp = arr[index];
        arr[index] = swap;
    } while (index != 0);
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
}

void reverse(int arr[], int n, int m) {
    int swap;
    for (int i = n; i < (m + n + 1) / 2; i++) {
        swap = arr[i];
        arr[i] = arr[m + n - i];
        arr[m + n - i] = swap;
    }
}

void left_rotate(int arr[], int d, int n) {
    if (d == 0)
        return;

    d = d % n;
    // std::reverse(arr, arr + d);
    reverse(arr, 0, d - 1);
    // std::reverse(arr + d, arr + n);
    reverse(arr, d, n - 1);
    print(arr, n);
    // std::reverse(arr, arr + n);
    reverse(arr, 0, n - 1);
}

int main() {
    // int arr[] = {1, 4, 5, 7};
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2;

    std::cout << "\nbefore rotation:\n";
    print(arr, n);
    left_rotate(arr, d, n);
    std::cout << "\nafter rotation:\n";
    print(arr, n);

    return 0;
}
