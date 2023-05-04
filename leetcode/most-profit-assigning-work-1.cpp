// https://leetcode.com/problems/most-profit-assigning-work/

#include<bits/stdc++.h>

using namespace std;

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to rearrange array (find the partition point)
int partition(vector<int>& arr, vector<int>& brr, int low, int high) {
    
  // select the rightmost element as pivot
  int pivot = arr[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&arr[i], &arr[j]);
      swap(&brr[i], &brr[j]);
    }
  }
  
  // swap pivot with the greater element at i
  swap(&arr[i + 1], &arr[high]);
  swap(&brr[i + 1], &brr[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(vector<int>& arr, vector<int>& brr, int low, int high) {
  if (low < high) {
      
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
    int pi = partition(arr, brr, low, high);

    // recursive call on the left of pivot
    quickSort(arr, brr, low, pi - 1);

    // recursive call on the right of pivot
    quickSort(arr, brr, pi + 1, high);
  }
}

void print_vec(vector<int>& v) {
	for(auto& x: v) {
		cout << x << " ";
	}
	cout << endl;
}

class Solution {
public:
	int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
		int n = difficulty.size();
		quickSort(difficulty, profit, 0, n - 1); 

		int max_till[n];
		max_till[0] = profit[0];

		for(int i = 1; i < n; i++) {
			max_till[i] = max(max_till[i - 1], profit[i]);
		}

		int p = 0;
		for(auto& w: worker) {
			int x = upper_bound(difficulty.begin(), difficulty.end(), w) - difficulty.begin() - 1;
			if (x >= 0)
				p += max_till[x];
		}

		return p;
	}
};

void test_1() {
		vector<int> difficulty = {2,4,6,8,10};
		vector<int> profit = {10,20,30,40,50};
		vector<int> worker = {4,5,6,7};
		Solution sol;
		int ans = sol.maxProfitAssignment(difficulty, profit, worker);
		cout << ans << endl;
}

void test_2() {
		vector<int> difficulty = {85,47,57};
		vector<int> profit = {24,66,99};
		vector<int> worker = {40,25,25};
		Solution sol;
		int ans = sol.maxProfitAssignment(difficulty, profit, worker);
		cout << ans << endl;
}

void test_3() {
		vector<int> difficulty = {34, 2, 33, 26, 25, 47, 48, 31, 19, 31, 22, 36, 49, 21, 5, 34, 15, 33, 4, 26, 37, 50, 14, 48, 5, 37, 16, 40, 25, 48, 32, 36, 22, 43, 30, 26, 39, 37, 28, 33, 43, 34, 43, 13, 21, 8, 49, 1, 8, 18, 31, 40, 30, 6, 25, 15, 8, 15, 42, 17, 29, 48, 30, 28, 17, 11, 44, 39, 43, 23, 18, 26, 38, 30, 49, 24, 49, 6, 30, 23, 33, 22, 18, 14, 50, 38, 14, 10, 15, 36, 9, 27, 11, 6, 32, 27, 11, 1, 34, 45};
		vector<int> profit = {9, 41, 35, 9, 28, 34, 46, 46, 44, 6, 44, 27, 15, 19, 41, 42, 43, 5, 16, 23, 28, 47, 14, 10, 8, 6, 20, 12, 27, 4, 23, 4, 29, 26, 3, 20, 38, 24, 2, 31, 18, 33, 25, 44, 15, 39, 30, 20, 36, 50, 4, 1, 34, 1, 29, 35, 36, 19, 26, 17, 2, 20, 39, 16, 50, 42, 24, 48, 3, 34, 19, 34, 20, 29, 47, 6, 48, 36, 32, 17, 7, 43, 35, 34, 45, 40, 48, 7, 9, 33, 14, 12, 25, 36, 2, 8, 15, 14, 24, 8};
		vector<int> worker = {41, 32, 13, 29, 39, 47, 23, 34, 38, 42, 41, 24, 22, 11, 43, 43, 12, 8, 40, 28, 23, 34, 7, 12, 40, 30, 27, 43, 9, 6, 11, 16, 38, 23, 45, 31, 40, 34, 11, 41, 8, 44, 23, 12, 29, 13, 31, 36, 5, 2, 40, 22, 21, 43, 9, 22, 15, 43, 27, 20, 37, 19, 33, 5, 46, 42, 20, 47, 19, 9, 46, 7, 45, 10, 47, 50, 9, 18, 33, 18, 44, 26, 33, 3, 9, 28, 11, 50, 15, 26, 40, 34, 17, 14, 17, 8, 50, 18, 42, 1, 9, 42, 31, 4, 43, 27, 36, 31, 6, 40, 35, 46, 48, 44, 30, 24, 26, 29, 45, 8, 6, 41, 16, 13, 23, 19, 23, 42, 1, 33, 34, 32, 15, 13, 16, 29, 34, 10, 6, 39, 26, 9, 9, 6, 25, 48, 11, 20, 4, 32, 16, 49, 42, 42, 34, 44, 1, 24, 9, 30, 25, 34, 26, 10, 32, 24, 16, 30, 15, 36, 8, 48, 43, 19, 39, 5, 1, 26, 32, 7, 31, 8, 48, 26, 29, 23, 18, 50, 4, 25, 39, 16, 34, 41, 45, 28, 9, 8, 30, 41};
		Solution sol;
		int ans = sol.maxProfitAssignment(difficulty, profit, worker);
		cout << ans << endl;
}
int main() {
		test_1();
		test_2();
		test_3();
		return 0;
}
