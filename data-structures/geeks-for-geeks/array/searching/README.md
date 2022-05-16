## Notes
    - intersection of unsorted arrays of size n:
        - https://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/
        - https://www.geeksforgeeks.org/union-and-intersection-of-two-sorted-arrays-2/
        - method 0: naive approach: time: O(n^2), memory: O(1)
        - method 1: sort the second array then use binary search for elements of first array in the second one: time: O(nlogn), memory: O(1)
            - To handle the duplicates, keep track of the previous element added to the intersection list.
        - method 2: sort both the arrays then use linear search: time: O(nlogn), memory: O(1) (two pointer technique)
            - To handle the duplicates, keep track of the previous element added to the intersection list.
        - method 3: use unorderd_set: time: O(n), memory: O(n)
            - To handle the duplicates, check whether the element is present in the intersection list.
    - sort (O(nlogn)) + less space (O(1)) ~= no sort (O(n)) + set (O(n))
        - when you see a problem around arrays, think about sort, binary search, two pointer technique, and set.
    - always remember you can replace linear search with instant search + hashmap
    - https://www.geeksforgeeks.org/find-common-elements-three-sorted-arrays/
    - https://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/
    - https://www.geeksforgeeks.org/find-element-appears-array-every-element-appears-twice/
    - https://www.geeksforgeeks.org/maximum-subarray-sum-excluding-certain-elements/
    - https://www.geeksforgeeks.org/majority-element/
        - https://www.geeksforgeeks.org/check-for-majority-element-in-a-sorted-array/
    - https://www.geeksforgeeks.org/find-a-peak-in-a-given-array/
    - https://www.geeksforgeeks.org/find-subarray-with-given-sum/
        - *** https://www.geeksforgeeks.org/find-subarray-with-given-sum-in-array-of-integers/ ***
        - *** https://www.geeksforgeeks.org/find-subarray-with-given-sum-with-negatives-allowed-in-constant-space/ ***
## Easy Problems
	- https://www.geeksforgeeks.org/search-insert-and-delete-in-an-unsorted-array/
	- https://www.geeksforgeeks.org/search-insert-and-delete-in-a-sorted-array/
    - https://www.geeksforgeeks.org/find-repetitive-element-1-n-1/
    - https://www.geeksforgeeks.org/maximum-equilibrium-sum-in-an-array/
        - https://www.geeksforgeeks.org/equilibrium-index-of-an-array/
    - https://www.geeksforgeeks.org/ceiling-in-a-sorted-array/
        - https://www.geeksforgeeks.org/floor-in-a-sorted-array/
        - https://www.geeksforgeeks.org/find-floor-ceil-unsorted-array/
    - https://www.geeksforgeeks.org/find-local-minima-array/
        - https://www.geeksforgeeks.org/find-a-fixed-point-in-a-given-array/
        - https://www.geeksforgeeks.org/find-fixed-point-value-equal-index-given-array-duplicates-allowed/
    - https://www.geeksforgeeks.org/maximum-triplet-sum-array/

## TODO
    - \*\*\*\* https://www.geeksforgeeks.org/array-data-structure/array-searching/ \*\*\*\*
    - https://practice.geeksforgeeks.org/company/Amazon/
    - https://www.geeksforgeeks.org/tag/amazon/

    - geeksforgeeks.org/smallest-difference-triplet-from-three-arrays/
    - https://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/
    - https://www.geeksforgeeks.org/find-triplets-array-whose-sum-equal-zero/

    - http://courses.csail.mit.edu/6.006/spring11/lectures/lec02.pdf
    - https://www.geeksforgeeks.org/unorderd_set-stl-uses/
    - https://www.geeksforgeeks.org/lower_bound-in-cpp/
    - https://www.geeksforgeeks.org/upper_bound-in-cpp/
