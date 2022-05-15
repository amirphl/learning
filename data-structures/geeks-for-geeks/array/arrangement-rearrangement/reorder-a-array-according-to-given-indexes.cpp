// https://www.geeksforgeeks.org/reorder-a-array-according-to-given-indexes/
// other approaches:
// method 1: copy src to correct indexes in an auxiliary array then copy back auxiliary array to the main array: time: O(n), memory: O(n)
// method 2: sort the array according to the index array by a customized sort function: time: O(nlogn), memory: O(1)

#include<algorithm>
#include<iostream>

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

// time: O(n), memory: O(1)
void rearr(int arr[], int brr[], int n) {
    int i = -1, j;
    int t, u, v;

    while (++i < n) {
        if (brr[i] == -1)
            continue;

        j = brr[i];
        brr[i] = -1;
        t = arr[i];

        do {
            u = arr[j];
            arr[j] = t;
            t = u;
            v = brr[j];
            brr[j] = -1;
            j = v;
        } while (j != -1);
    }
}

int main() {
    int arr[10];
    int brr[] = {1, 3, 6, 0, 9, 2, 5, 8, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    print(arr, n);
    print(brr, n);
    rearr(arr, brr, n);
    print(arr, n);

    return 0;
}
