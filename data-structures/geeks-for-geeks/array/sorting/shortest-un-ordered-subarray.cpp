// https://www.geeksforgeeks.org/shortest-un-ordered-subarray/
// TODO(amirphl) subsets

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

// time: O(n), memory: O(1)
int find(int arr[], int n) {
	if (n <= 2)
		return 0;

	int i = 0;

	while(++i < n) {
		if (arr[i - 1] != arr[i])
			break;
	}

	int inc = (arr[i - 1] < arr[i]) ? 1 : 0;

	for (; i < n; i++) {
		if ((arr[i - 1] < arr[i] && inc == 0) || (arr[i - 1] > arr[i] && inc == 1))
			return 3;
	}

	return 0;
}

int main() {
	int arr[] = { 7, 9, 10, 8, 11 };
	// int arr[] = { 7, 9, 9, 9, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	// fill_arr(arr, n);
	// print(arr, n);
	std::cout << find(arr, n) << std::endl;
	return 0;
}
