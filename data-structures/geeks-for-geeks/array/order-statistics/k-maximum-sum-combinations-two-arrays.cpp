// https://www.geeksforgeeks.org/k-maximum-sum-combinations-two-arrays/
// https://www.geeksforgeeks.org/k-maximum-sums-non-overlapping-contiguous-sub-arrays/

// // https://www.geeksforgeeks.org/k-th-largest-sum-contiguous-subarray/
// TODO(amirphl) subsets vs subarrays

#include<algorithm>
#include<iostream>
#include<climits>

using namespace std;

void fill_arr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		arr[i] =  (rand() % 100) - 50;
	}
}

void print(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

// https://www.geeksforgeeks.org/k-maximum-sum-combinations-two-arrays/
// This solution isn't correct:
// ex:
// arr: {1, 2, 4, 5}
// brr: {0, 3, 5, 5, 8}
void print_k_max_sum_combinations(int arr[], int brr[], int n, int m, int k) {
	std::sort(arr, arr + n);
	std::sort(brr, brr + m);
	print(arr, n);
	print(brr, m);

	int i = m - 1, j = n - 2;
	int p = m - 2, q = n - 1;
	int s1, s2, r;

	std::cout << arr[n - 1] + brr[m - 1] << " ";

	for (int u = 0; u < k - 1; u++) {
		s1 = brr[i] + arr[j];
		s2 = brr[p] + arr[q];

		if (s1 > s2) {
			r = s1;
			j--;
		} else {
			r = s2;
			q--;
		}

		if (j==-1) {
			i -= 2;
		} else if (q == -1){
			p -= 2;
		}
		std::cout << r << " ";
	}
}

// https://www.geeksforgeeks.org/k-maximum-sums-non-overlapping-contiguous-sub-arrays/
// time: O(k*n), memory: O(1)
void print_k_max_sum_non_ovarlapping_contiguous_subarrays(int arr[], int n, int k){
	for (int j = 0; j < k; j++) {
		int p, q; // largest contiguous sum subarray = arr[p] ... arr[q]
		int r = 0; // r = current p
		int max_seen = (arr[0] > 0) ? arr[0] : 0;
		int curr = (arr[0] > 0) ? arr[0] : 0;
		int max_elem_index = 0, flag = (arr[0] > 0) ? 1 : 0;
		int s;

		for (int i = 1; i < n; i++) {
			s = curr + arr[i];

			if (curr <= 0 && s >= 0)
				r = i;

			if (s > max_seen) {
				max_seen = s;
				p = r;
				q = i;
			}

			if (s < 0)
				curr = 0;
			else
				curr = s;

			if (arr[i] > 0)
				flag = 1;

			if (arr[i] > arr[max_elem_index])
				max_elem_index = i;
		}

		if (flag) {
			// std::cout << p << " " << q << " " << max_seen << "\n";
			std::cout << max_seen << " ";
			p--;
			while (++p <= q)
				arr[p] = INT_MIN;
		} else {
			// std::cout << max_elem_index << " " << arr[max_elem_index] << "\n";
			std::cout << arr[max_elem_index] << "  ";
			arr[max_elem_index] = INT_MIN;
		}
	}
}

/*
int main() {
	int arr[40];
	int brr[40];
	int n = sizeof(arr) / sizeof(arr[0]);
	int m = sizeof(brr) / sizeof(brr[0]);
	fill_arr(arr, n);
	fill_arr(brr, m);
	int k = 10;
	// int k = 81;
	// int k = 1000;
	// int k = 1600;
	// int k = 1601;
	print_k_max_sum_combinations(arr, brr, n, m, k);
	return 0;
}
*/

int main() {
	int arr[40] = {33, 36, 27, -35, 43, -15, 36, 42, -1, -29, 12, -23, 40, 9, 13, -24, -10, -24, 22, -14, -39, 18, 17, -21, 32, -20, 12, -27, 17, -15, -21, -48, -28, 8, 19, 17, 43, 6, -39, -8
};
	int n = sizeof(arr) / sizeof(arr[0]);
	// fill_arr(arr, n);
	// print(arr, n);
	// int k = 10;
	int k = 40;
	// int k = 50;
	print_k_max_sum_non_ovarlapping_contiguous_subarrays(arr, n, k);
	return 0;
}
