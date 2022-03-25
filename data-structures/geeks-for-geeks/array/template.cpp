// mention link
// mention notes
// mention time and memory complexity

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

int main() {
	int arr[40];
	int n = sizeof(arr) / sizeof(arr[0]);
	fill_arr(arr, n);
	print(arr, n);
	return 0;
}
