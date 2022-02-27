// https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/
// TODO(amirphl) What about pairs of m elements?
// TODO(amirphl) This method does not handle array with duplicates well.

#include<algorithm>
#include<iostream>

int search(int arr[], int n, int x) {
    int l = 0;
    int r = n - 1;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            r = i;
            l = i + 1;
            break;
        }
    }

    int i = l % n;
    int j = r % n;

    while (i != j) {
        if (arr[i] + arr[j] == x) {
            // std::cout << i << " " << j << " " << l << " " << r << " " << arr[i] << " " << arr[j] << std::endl;
            return 1;
        }

        if (arr[i] + arr[j] > x) {
            r--;
        } else {
            l++;
        }

        i = l % n;
        j = (r + n) % n;
    }

    return 0;
}

int count(int arr[], int n, int x) {
    int l = 0;
    int r = n - 1;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            r = i;
            l = i + 1;
            break;
        }
    }

    int i = l % n;
    int j = r % n;
    int counter = 0;

    while (i != j) {
        if (arr[i] + arr[j] == x) {
            std::cout << i << " " << j << " " << l << " " << r << " " << arr[i] << " " << arr[j] << std::endl;
            counter++;
            l++;
            i = l % n;
        } else if (arr[i] + arr[j] > x) {
            r--;
            j = (r + n) % n;
        } else {
            l++;
            i = l % n;
        }
    }

    return counter;
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    // int arr[] = {1, 2, 3, 4, 5};
    // int arr[] = {11, 15, 6, 7, 9, 10};
    int arr[20];

    for (int i = 0; i < 10; i++) {
        arr[i] = i + 10;
        arr[i + 10] = i;
    }

    int n = sizeof(arr) / sizeof(arr[0]);
    // int x = 5;
    // int x = 16;

    print(arr, n);
    std::cout << "\n--------------------\n";
    std::cout << search(arr, n, 19) << std::endl;
    std::cout << "\n--------------------\n";
    std::cout << count(arr, n, 19) << std::endl;
    std::cout << "\n--------------------\n";
    std::cout << count(arr, n, 15) << std::endl;
    std::cout << "\n--------------------\n";
    std::cout << count(arr, n, 7) << std::endl;
    std::cout << "\n--------------------\n";
    std::cout << count(arr, n, 1) << std::endl;
    std::cout << "\n--------------------\n";

    int arr2[] = {3, 3, 3, 3};
    n = sizeof(arr2) / sizeof(arr2[0]);

    std::cout << count(arr2, n, 6) << std::endl;
    std::cout << "\n--------------------\n";

    return 0;
}
