// https://www.geeksforgeeks.org/block-swap-algorithm-for-array-rotation/

#include<algorithm>
#include<iostream>

void swap(int arr[], int s, int e, int s2) {
    int i = 0;
    int temp;

    while (s <= e) {
        temp = arr[s2 + i];
        arr[s2 + i] = arr[s];
        arr[s] = temp;
        s += 1;
        i += 1;
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// time O(n) memory O(1)
void left_rotate(int arr[], int d, int s, int e) {
    // std::cout << s << "  " << e << " --- " << d << " --- ";
    // print(arr, 8);
    if (e == s || d == 0)
        return;

    d = d % (e - s + 1);

    if (e == s + 1) {
        if (d == 0)
            return;
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
        return;
    }

    if (e - s + 1 - d > d) {
        swap(arr, s, s + d - 1, e - d + 1);
        left_rotate(arr, d, s, e - d);
    } else {
        swap(arr, s + d, e, s);
        left_rotate(arr, 2 * d - (e - s + 1), e - d + 1, e);
    }
}

int main() {
    int arr[20];
    for (int i = 0; i < 20; i++)
        arr[i] = i;
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 10;

    print(arr, n);
    left_rotate(arr, d, 0, n - 1);
    print(arr, n);

    return 0;
}
