// https://www.geeksforgeeks.org/rearrange-array-arrj-becomes-arri-j/
// other approaches:
// method 1: use temporary array: time: O(n), memory: O(n)
// method 2: The idea is to store each element’s new and old value as quotient and remainder of n, respectively (n being the size of the array). 
// For example, Suppose an element’s new value is 2, the old value is 1 and n is 3, then the element’s value is stored as 1 + 2*3 = 7. We can retrieve its old value by 7%3 = 1 and its new value by 7/3 = 2. 

#include <iostream>

// time: O(n), memory: O(1)
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
