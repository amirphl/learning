// https://www.geeksforgeeks.org/range-minimum-query-for-static-array/

#include<algorithm>
#include<iostream>
#include<cmath>

// time: O(n), memory: O(sqrt(n))
void fill_rqd(int arr[], int brr[], int n) {
	int sq = std::ceil(std::sqrt(n));
	int r = std::floor(std::sqrt(n));
	int c = -1;

	while(++c < sq) {
		int i = c * r;
		int min = arr[i];

		while(i < n && i < (c + 1) * r) {
			if (arr[i] < min)
				min = arr[i];
			i++;
		}

		brr[c] = min;
	}
}

// time: O(sqrt(n)), memory: O(1)
int query_rqd(int arr[], int brr[], int n, int low, int high) {
	int r = std::floor(std::sqrt(n));
	int min = arr[low];
	int l = std::ceil(low / r) * r;
	int h = std::floor(high / r) * r;

	int c = low;
	while(c < std::min(l, high + 1)) {
		if (arr[c] < min)
			min = arr[c];
		c++;
	}

	c = std::max(h, low);
	while(c <= high) {
		if (arr[c] < min)
			min = arr[c];
		c++;
	}

	c = l / r - 1;
	while(++c < h / r) {
		if (brr[c] < min)
			min = brr[c];
	}
	
	return min;
}

void print(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

int main() {
	int arr[] = {12, 13, 6, 18, 2, 12, 15, 11, 11, 12, 14, 11, 15, 17, 12, 11, 20, 17, 14, 5, -1, 0 ,-2, 5, 6, -3, 13, 3, 10, 11, 8, 15, 1, 14, 5, 6, 13, 13, 9, 1, 7, 2, 3, 10, 12, 1, 15, 6, 15, 19, 17, 3, 2, 6, 13, 17, 9, 5, 8, 1, 13, 19, 17, 20, 20, 19, 3, 1, 9, 10, 19, 1, 5, 5, 5, 9, 12, 9, 8, 19, 9, 15, 18, 7, 14, 6, 11, 8, 14, 3, 5, 15, 19, 8, 10, 1, 7, 8, 17, 14, 3, 7, 15, 3, 14, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	int sq = std::ceil(std::sqrt(n));
	int brr[sq];
	fill_rqd(arr, brr, n);
	print(arr, n);
	print(brr, sq);
	std::cout << query_rqd(arr, brr, n, 0,  20)  << std::endl;
	std::cout << query_rqd(arr, brr, n, 5,  20)  << std::endl;
	std::cout << query_rqd(arr, brr, n, 7,  27)  << std::endl;
	std::cout << query_rqd(arr, brr, n, 14, 37)  << std::endl;
	std::cout << query_rqd(arr, brr, n, 30, 40)  << std::endl;
	std::cout << query_rqd(arr, brr, n, 34, 34)  << std::endl;
	std::cout << query_rqd(arr, brr, n, 39, 49)  << std::endl;
	std::cout << query_rqd(arr, brr, n, 45, 69)  << std::endl;
	std::cout << query_rqd(arr, brr, n, 51, 52)  << std::endl;
	std::cout << query_rqd(arr, brr, n, 55, 105) << std::endl;
	std::cout << query_rqd(arr, brr, n, 0,  105) << std::endl;

	return 0;
}
