// https://www.geeksforgeeks.org/maximum-difference-between-two-elements/

#include<algorithm>
#include<iostream>

void print(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

// time: O(n), memory: O(1)
int find_max_diff(int arr[], int n) {
	int min_elem = arr[0];
	int max = 0;
	int a;

	for (int i = 1; i < n; i++) {
		a = arr[i] - min_elem;

		if (a > max)
			max = a;

		if (arr[i] < min_elem)
			min_elem = arr[i];
	}

	return max;
}

// geeks solution
// time: O(n), memory: O(1)
int maxDiff(int arr[], int arr_size)
{
     // Maximum difference found so far
     int max_diff = arr[1] - arr[0];
      
     // Minimum number visited so far
     int min_element = arr[0];
     for(int i = 1; i < arr_size; i++)
     {    
       if (arr[i] - min_element > max_diff)                            
       max_diff = arr[i] - min_element;
        
       if (arr[i] < min_element)
       min_element = arr[i];                    
     }
      
     return max_diff;
}

int main() {
	int arr[40];
	int n = sizeof(arr) / sizeof(arr[0]);

	print(arr, n);
	std::cout << "my solution:    " << find_max_diff(arr, n) << std::endl;
	std::cout << "geeks solution: " << maxDiff(arr, n)      << std::endl;

	return 0;
}
