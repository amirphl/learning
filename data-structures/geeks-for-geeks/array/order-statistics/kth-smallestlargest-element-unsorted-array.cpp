// https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/
// https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-2-expected-linear-time/
// https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-3-worst-case-linear-time/

// https://www.geeksforgeeks.org/kth-smallestlargest-element-using-stl/
// https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/
// https://www.geeksforgeeks.org/c-program-find-largest-element-array/
// https://www.geeksforgeeks.org/program-find-minimum-maximum-element-array/
// https://www.geeksforgeeks.org/find-the-largest-three-elements-in-an-array/
// https://www.geeksforgeeks.org/find-elements-array-least-two-greater-elements/
// https://www.geeksforgeeks.org/minimum-product-k-integers-array-positive-integers/
// https://www.geeksforgeeks.org/find-second-largest-element-array/
// https://www.geeksforgeeks.org/to-find-smallest-and-second-smallest-element-in-an-array/


// sorting:
// time: O(nlogn), memory: O(1)
// modifies original array

// set (BST):
// time: O(nlogn), memory: O(n)
// doesn't modifiy original array
// doesn't handle duplicates

// map (BST):
// time: O(nlogn), memory: O(n)
// doesn't modifiy original array

// min heap:
// O(n + (k)logn), memory: O(1) (We can build a MinHeap in O(n) in practice, O(nlogn) in theory) (in-place)
// modifies original array

// max heap:
// time: O(k + (n - k)log(k)), memory: O(1)
// modifies original array

// modified bubble sort:
// time: O(k*n), memory: O(1)
// modifies original array

// temporary array:
// time: O((n - k)*k), memory: O(k)
// doesn't modifiy original array

// quick sort:
// time: O(n*n), memory: O(1)
// modifies original array

// modified quick sort: https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-2-expected-linear-time/
// time: O(n), memory: O(1)
// modifies original array

// median: https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-3-worst-case-linear-time/
// time: O(n), memory: O(1)
// modifies original array

#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<queue>

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

template<typename T>
void print_queue(T q) { // NB: pass by value so the print uses a copy
    while(!q.empty()) {
        std::cout << q.top() << ' ';
        q.pop();
    }
    std::cout << '\n';
}

// MinHeap approach
int find_kth(std::vector<int> vec, int k) {
    std::priority_queue <int, std::vector<int>, std::greater<int>> min_heap(vec.begin(), vec.end());
    int i = 0;
    int n = vec.size();

    while (i++ < k - 1)
        min_heap.pop();

    return min_heap.top();
}

// Map approach
int find_kth2(std::vector<int> vec, int k) {
    std::map<int, int> m;
    int n = vec.size();

    for(int i = 0; i < n; i++)
        m[vec[i]]++;

    int f = 0;

    for(auto it = m.begin(); it != m.end(); it++) {
        f += it -> second;

        if (f >= k)
            return it -> first;
    }

    return -1;
}

// Set approach
// Note that set in STL uses a self-balancing BST internally and therefore time complexity of search and insert operations is O(log n).
int find_kth3(int arr[], int n, int k) {
    std::set<int> s(arr, arr + n);

    /*
    std::set<int> s;
    for (int i = 0; i < n; i++)
    	s.insert(arr[i]);
    */

    auto it = s.begin();

    // TODO(amirphl) O(klogn) or O(k)?
    for (int i = 0; i < k - 1; i++)
        it++;

    return *it;
}

int main() {
    int src[40];
    int n = sizeof(src) / sizeof(src[0]);
    std::vector<int> vec(src, src + n);
    int k = 15;
    // int kth = find_kth(vec, k);
    // int kth = find_kth2(vec, k);
    int kth = find_kth3(src, n, k);
    std::sort(src, src + n);
    print(src, n );
    std::cout << kth << std::endl;
    return 0;
}
