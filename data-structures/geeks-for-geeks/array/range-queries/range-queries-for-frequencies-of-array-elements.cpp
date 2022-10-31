// https://www.geeksforgeeks.org/range-queries-for-frequencies-of-array-elements/

#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>

// preprocessing: time: O(n), memory: O(n)
// query: time: O(logn) ---> binary search
int find_freq(int arr[], int n, int k, int low, int high) {
    std::unordered_map<int, std::vector<int>> m; // no need to use ordered map!

    for (int i = 0; i < n; i++) {
        m[arr[i]].push_back(i);
    }

    std::cout << "k: " << k << "  low: " << low << "  high: " << high << std::endl;
    /*
    for (auto it = m.begin(); it != m.end(); it++) {
    	auto vec = it -> second;
    	std::cout << it -> first << " : ";
    	for (auto u = vec.begin(); u != vec.end(); u++) {
    		std::cout << *u << " ";
    	}
    	std::cout << std::endl;
    }
    */

    int a = std::lower_bound(m[k].begin(), m[k].end(), low)  - m[k].begin(); // TODO
    int b = std::upper_bound(m[k].begin(), m[k].end(), high) - m[k].begin(); // TODO
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "----------------" << std::endl;
    return b - a;
}

int main() {
    int arr[] = {12, 13, 6, 18, 2, 12, 15, 11, 11, 12, 14, 11, 15, 17, 12, 11, 20, 17, 14, 5, -1, 0,-2, 5, 6, -3, 13, 3, 10, 11, 8, 15, 1, 14, 5, 6, 13, 13, 9, 1, 7, 2, 3, 10, 12, 1, 15, 6, 15, 19, 17, 3, 2, 6, 13, 17, 9, 5, 8, 1, 13, 19, 17, 20, 20, 19, 3, 1, 9, 10, 19, 1, 5, 5, 5, 9, 12, 9, 8, 19, 9, 15, 18, 7, 14, 6, 11, 8, 14, 3, 5, 15, 19, 8, 10, 1, 7, 8, 17, 14, 3, 7, 15, 3, 14, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    find_freq(arr, n, 17, 5, 12);
    find_freq(arr, n, 17, 5, 13);
    find_freq(arr, n, 17, 5, 14);
    find_freq(arr, n, 17, 5, 16);
    find_freq(arr, n, 17, 5, 17);
    find_freq(arr, n, 17, 5, 18);
    find_freq(arr, n, 17, 5, 19);
    find_freq(arr, n, 17, 5, 20);
    find_freq(arr, n, 17, 5, 48);
    find_freq(arr, n, 17, 5, 49);
    find_freq(arr, n, 17, 5, 50);
    find_freq(arr, n, 17, 5, 51);
    find_freq(arr, n, 17, 5, 52);
    find_freq(arr, n, 17, 5, 55);
    find_freq(arr, n, 17, 5, 97);
    find_freq(arr, n, 17, 5, 98);
    find_freq(arr, n, 17, 5, 99);
    find_freq(arr, n, 17, 5, 100);
    find_freq(arr, n, 17, 13, 12);
    find_freq(arr, n, 17, 13, 13);
    find_freq(arr, n, 17, 13, 14);
    find_freq(arr, n, 17, 14, 13);
    find_freq(arr, n, 17, 14, 14);
    find_freq(arr, n, 17, 14, 15);
    find_freq(arr, n, 17, 16, 15);
    find_freq(arr, n, 17, 17, 15);
    find_freq(arr, n, 17, 18, 15);
    find_freq(arr, n, 17, 55, 15);
    find_freq(arr, n, 17, 97, 15);
    find_freq(arr, n, 17, 98, 15);
    find_freq(arr, n, 17, 99, 15);
    find_freq(arr, n, 17, 100, 15);
    return 0;
}
