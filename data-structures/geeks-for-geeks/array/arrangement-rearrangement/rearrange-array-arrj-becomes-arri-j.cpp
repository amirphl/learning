// https://www.geeksforgeeks.org/rearrange-array-arrj-becomes-arri-j/
// TODO(amirphl) There is another approach by Prateek Oraon which is fantastic! Review it.

#include <iostream>

int rearr(int arr[], int n) {
    int temp;

    for (int i = 0; i < n; i++) {
        arr[i]++;
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0)
            continue;

        int j = arr[i] - 1;
        int index = i;
        do {
            temp = arr[j] - 1;
            arr[j] = -1 * (index + 1);
            index = j;
            j = temp;
        } while (index != i);
    }

    for (int i = 0; i < n; i++) {
        arr[i] *= -1;
        arr[i]--;
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

int main() {
	// int arr[] = {1, 3, 5, 2, 0, 4};
	// int arr[] = {1, 3, 0, 2};
	int arr[] = {2, 0, 1, 4, 5, 3};
	// int arr[] = {3, 2, 1, 0};
	// int arr[] = {0, 1, 2, 3};
	int n = sizeof(arr) / sizeof(arr[0]);

    print(arr, n);
	rearr(arr, n);
	print(arr, n);

	return 0;
}
