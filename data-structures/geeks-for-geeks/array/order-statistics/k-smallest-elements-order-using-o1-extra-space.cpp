// https://www.geeksforgeeks.org/k-smallest-elements-order-using-o1-extra-space/

#include<algorithm>
#include<iostream>

void fill_arr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] =  (rand() % 100);
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

// time: O((n - k)*n), memory: O(1)
void find_kth(int arr[], int n, int k) {
    int max_ind = 0;

    for (int i = 0; i < k; i++)
        if (arr[i] > arr[max_ind])
            max_ind = i;

    for (int i = k; i < n; i++) {
        if (arr[i] >= arr[max_ind])
            continue;

        int temp = arr[i];
        arr[i] = arr[max_ind];

        for (int j = max_ind; j < k - 1; j++)
            arr[j] = arr[j + 1];

        arr[k - 1] = temp;

        for (int i = 0; i < k; i++)
            if (arr[i] > arr[max_ind])
                max_ind = i;
    }

    print(arr, n);
}

int main() {
    int arr[40];
    int n = sizeof(arr) / sizeof(arr[0]);
    fill_arr(arr, n);
    print(arr, n);
    find_kth(arr, n, 10);
    // std::sort(arr, arr + n);
    // print(arr, n);
    return 0;
}
