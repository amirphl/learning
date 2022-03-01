// https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/
// https://www.geeksforgeeks.org/rearrange-array-in-alternating-positive-negative-items-with-o1-extra-space-set-2/
// https://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers-publish/
// TODO(amirphl) maintain order - time: O(n) || O(nlogn) - memory: O(1)

#include<algorithm>
#include<iostream>

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void right_shift(int arr[], int i, int j) {
    if (i >= j)
        return;

    std::reverse(arr + i, arr + j);
    std::reverse(arr + i, arr + j + 1);
}

// doesn't maintain order - time: O(n) - memory: O(1)
void rearr2(int arr[], int n) {
    int next_neg = n;
    int next_pos = n;
    int j;

    for (int k = 0; k < n; k++) {
        if (arr[k] < 0 && next_neg == n)
            next_neg = k;
        if (arr[k] >= 0 && next_pos == n)
            next_pos = k;
    }

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {  // -
            if (arr[i] < 0)
                continue;

            if (next_neg < i) {
                next_neg = i + 1;
                for (; next_neg < n; next_neg++)
                    if (arr[next_neg] < 0)
                        break;
            }

            if (next_neg == n)
                break;

            swap(arr, i, next_neg);

            next_neg = i + 1;
            for (; next_neg < n; next_neg++)
                if (arr[next_neg] < 0)
                    break;
        } else {  // +
            if (arr[i] >= 0)
                continue;

            if (next_pos < i) {
                next_pos = i + 1;
                for (; next_pos < n; next_pos++)
                    if (arr[next_pos] >= 0)
                        break;
            }

            if (next_pos == n)
                break;

            swap(arr, i, next_pos);

            next_pos = i + 1;
            for (; next_pos < n; next_pos++)
                if (arr[next_pos] >= 0)
                    break;
        }
    }
}


// maintaining order - time: O(n*n) - memory: O(1)
void rearr1(int arr[], int n) {
    int next_neg = n;
    int next_pos = n;
    int j;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {  // -
            if (arr[i] < 0)
                continue;

            j = i + 1;
            for (; j < n; j++)
                if (arr[j] < 0) {
                    next_neg = j;
                    break;
                }

            if (n == j)
                break;

            swap(arr, i, next_neg);
            right_shift(arr, i + 1, next_neg);
            i++;
        } else {  // +
            if (arr[i] >= 0)
                continue;

            j = i + 1;
            for (; j < n; j++)
                if (arr[j] >= 0) {
                    next_pos = j;
                    break;
                }

            if (n == j)
                break;

            swap(arr, i, next_pos);
            right_shift(arr, i + 1, next_pos);
            i++;
        }
    }
}

int main() {
    // int arr[] = {1, 2, 3, 4, 5};
    // int arr[] = {1, 2, 3, -4, -1, 4};
    // int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    // int arr[] = {1, -1};
    // int arr[] = {-1, 1};
    // int arr[] = {-2, 3, 4, -1};
    int arr[] = {-5, 3, 4, 5, -6, -2, 8, 9, -1, -4};
    int n = sizeof(arr) / sizeof(arr[0]);

    print(arr, n);
    // rearr1(arr, n);
    rearr2(arr, n);
    print(arr, n);

    return 0;
}

// We can also maintain order in time: O(n), memory: O(n)
