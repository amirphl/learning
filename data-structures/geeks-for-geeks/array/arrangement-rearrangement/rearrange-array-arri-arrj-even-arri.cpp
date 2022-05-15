// https://www.geeksforgeeks.org/rearrange-array-arri-arrj-even-arri/
// https://www.geeksforgeeks.org/rearrange-array-order-smallest-largest-2nd-smallest-2nd-largest/
// https://www.geeksforgeeks.org/rearrange-array-maximum-minimum-form/
// https://www.geeksforgeeks.org/rearrange-array-maximum-minimum-form-set-2-o1-extra-space/

#include<algorithm>
#include<iostream>

// time: O(nlogn), memory: O(n)
int* rearr(int arr[], int n) {
    std::sort(arr, arr + n);

    int *brr = new int[n];

    for (int i = 0; i < n / 2; i++) {
        if (n % 2 == 0) {
            brr[n - 1 - 2 * i] = arr[n - 1 - i];
            brr[n - 1 - 2 * i - 1] = arr[i];
        } else {
            brr[n - 1 - 2 * i] = arr[i];
            brr[n - 1 - 2 * i - 1] = arr[n - 1 - i];
        }
    }

    if (n % 2 == 1)
        brr[0] = arr[n / 2];

    return brr;
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

int main() {
    // int arr[] = {1, 2, 3, 4, 5, 6, 7};
    // int arr[] = {1, 2, 1, 4, 5, 6, 8, 8};
    int arr[20];
    int n = sizeof(arr) / sizeof(arr[0]);

    int *brr = rearr(arr, n);
    print(brr, n);

    return 0;
}
