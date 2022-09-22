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

// time: O(n), memory: O(1)
// Iterating from right to left
int find_max_diff_2(int arr[], int n) {
    int max_elem = arr[n - 1];
    int max = 0;
    int a;

    for (int i = n - 2; i >= 0; i--) {
        a = max_elem - arr[i];

        if (a > max)
            max = a;

        if (arr[i] > max_elem)
            max_elem = arr[i];
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

// geeks solution
// time: O(n), memory: O(1)
// Iterating from right to left
int maxDiff2(int arr[], int n)
{
    // Initialize Result
    int maxDiff = -1;

    // Initialize max element from right side
    int maxRight = arr[n-1];

    for (int i = n-2; i >= 0; i--)
    {
        if (arr[i] > maxRight)
            maxRight = arr[i];
        else
        {
            int diff = maxRight - arr[i];
            if (diff > maxDiff)
            {
                maxDiff = diff;
            }
        }
    }
    return maxDiff;
}

int main() {
    int arr[40] = {-1852834080, 32743, -1852834080, 32743, -1852833792, 32743, -1854027536, 32743, -1854799128, 32743, -1856545193, 32743, -1789468335, 21851, -1789468664, 21851, 905864872, 32765, 1, 0, 905864544, 32765, -1789479449, 21851, 640, 0, 65535, 1, 905864560, 32765, -1789479423, 21851, 2, 0, -1789479331, 21851, -1854799128, 32743, -1789479408, 21851};
    int n = sizeof(arr) / sizeof(arr[0]);

    print(arr, n);
    std::cout << "my solution:    " << find_max_diff(arr, n) << std::endl;
    std::cout << "my solution:    " << find_max_diff_2(arr, n) << std::endl;
    std::cout << "geeks solution: " << maxDiff(arr, n)      << std::endl;
    std::cout << "geeks solution: " << maxDiff2(arr, n)      << std::endl;

    return 0;
}

// Method 3 (Another Tricky Solution)
// time: O(n), memory: O(1)
// First find the difference between the adjacent elements of the array and store all differences in an auxiliary array diff[] of size n-1. Now this problems turns into finding the maximum sum subarray of this difference array
// We can modify the above method to work in O(1) extra space. Instead of creating an auxiliary array, we can calculate diff and max sum in same loop. Following is the space optimized version.
