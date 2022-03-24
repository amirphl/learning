// https://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/
// TODO(amirphl) to handle duplicates: https://ideone.com/LaJnN5      O(n)

#include<algorithm>
#include<iostream>

// time: O(logn), memory: O(logn)
// use iterative approach to reduce the memory to O(1)
int find_minimum(int arr[], int l, int r) {
    // std::cout << l << " " << r << std::endl;

    if (r < l)
        // exit
        return -1;

    if (l == r)
        return arr[l];

    if (l == r - 1)
        return (arr[l] < arr[r]) ? arr[l] : arr[r];

    int mid = (l + r) / 2;

    if (arr[mid] > arr[mid + 1])
        return arr[mid + 1];

    // This is very important to compare arr[r] with arr[mid] instead of arr[l] to
    // handle strictly sorted arrays. (My first submissions failed because of this mistake!)
    if (arr[mid] < arr[r]) {
        return find_minimum(arr, l, mid);
    } else {
        return find_minimum(arr, mid, r);
    }
}

int main() {
    int arr[] = {42, 18, 31, 47, 124, 165, 178, 183, 227, 228, 302, 304, 335, 367, 385, 399, 420, 424, 446, 494, 497, 533, 549, 558, 576, 577, 644, 663, 699, 703, 721, 742, 757, 761, 768, 773, 801, 810, 827, 897, 929, 981, 997};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << find_minimum(arr, 0, n - 1) << std::endl;

    int arr1[] = {5, 6, 1, 2, 3, 4};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    std::cout << "The minimum element is " << find_minimum(arr1, 0, n1-1) << std::endl;

    int arr2[] = {1, 2, 3, 4};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    std::cout << "The minimum element is " << find_minimum(arr2, 0, n2-1) << std::endl;

    int arr3[] = {1};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    std::cout << "The minimum element is " << find_minimum(arr3, 0, n3-1) << std::endl;

    int arr4[] = {1, 2};
    int n4 = sizeof(arr4)/sizeof(arr4[0]);
    std::cout << "The minimum element is " << find_minimum(arr4, 0, n4-1) << std::endl;

    int arr5[] = {2, 1};
    int n5 = sizeof(arr5)/sizeof(arr5[0]);
    std::cout << "The minimum element is " << find_minimum(arr5, 0, n5-1) << std::endl;

    int arr6[] = {5, 6, 7, 1, 2, 3, 4};
    int n6 = sizeof(arr6)/sizeof(arr6[0]);
    std::cout << "The minimum element is " << find_minimum(arr6, 0, n6-1) << std::endl;

    int arr7[] = {1, 2, 3, 4, 5, 6, 7};
    int n7 = sizeof(arr7)/sizeof(arr7[0]);
    std::cout << "The minimum element is " << find_minimum(arr7, 0, n7-1) << std::endl;

    int arr8[] = {2, 3, 4, 5, 6, 7, 8, 1};
    int n8 = sizeof(arr8)/sizeof(arr8[0]);
    std::cout << "The minimum element is " << find_minimum(arr8, 0, n8-1) << std::endl;

    int arr9[] = {3, 4, 5, 1, 2};
    int n9 = sizeof(arr9)/sizeof(arr9[0]);
    std::cout << "The minimum element is " << find_minimum(arr9, 0, n9-1) << std::endl;

    int arr10[] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2};
    int n10 = sizeof(arr10)/sizeof(arr10[0]);
    std::cout << "*(wrong answer) The minimum element is " << find_minimum(arr10, 0, n10-1) << std::endl;

    int arr11[] = {1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    int n11 = sizeof(arr11)/sizeof(arr11[0]);
    std::cout << "*(wrong answer) The minimum element is " << find_minimum(arr11, 0, n11-1) << std::endl;

    int arr12[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int n12 = sizeof(arr12)/sizeof(arr12[0]);
    std::cout << "* The minimum element is " << find_minimum(arr12, 0, n12-1) << std::endl;

    return 0;
}
