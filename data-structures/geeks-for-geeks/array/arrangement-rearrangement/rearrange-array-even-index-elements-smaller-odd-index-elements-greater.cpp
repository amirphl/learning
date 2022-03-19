// https://www.geeksforgeeks.org/rearrange-array-even-index-elements-smaller-odd-index-elements-greater/

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

// time: O(n), memory: O(1)
void rearr(int arr[], int n) {
	int i = 0;

	while (i < n - 1) {
		if ((i % 2 == 0 && arr[i] > arr[i + 1]) || (i % 2 == 1 && arr[i] < arr[i + 1]))
				swap(arr, i, i + 1);
		i++;
	}
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

	print(arr, n);
	rearr(arr, n);
	print(arr, n);

    return 0;
}
