// https://www.geeksforgeeks.org/heap-sort/
// https://www.geeksforgeeks.org/heap-sort-for-decreasing-order-using-min-heap/

// { Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    // time: O(logn)
    // memory: O(logn) || O(1) (in case of iterative approach)
    void heapify(int arr[], int n, int i)  
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int m = arr[i];
        if (left < n) {
            m = max(m , arr[left]);
        }
        if (right < n) {
            m = max(m, arr[right]);
        }
        if (arr[i] == m) {
            return;
        } else {
            int temp = arr[i];
            arr[i] = m;
            if (left < n && m == arr[left]) {
                arr[left] = temp;
                heapify(arr, n, left);
            } else {
                arr[right] = temp;
                heapify(arr, n, right);
            }
        }
    }

    public:
    //Function to build a Heap from array.
    // fantastic, the actual time complexity is O(n)
    // memory: O(1)
    void buildHeap(int arr[], int n)  
    { 
        for(int i = (n - 2) / 2; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    // time: O(nlogn), memory: O(1)
    void heapSort(int arr[], int n)
    {
        buildHeap(arr, n);
        int temp;
        for(int i = 0; i < n - 1; i++) {
            temp = arr[n - i - 1];
            arr[n - i - 1] = arr[0];
            arr[0] = temp;
            heapify(arr, n - i - 1, 0);
        }
    }
};




// { Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
  // } Driver Code Ends
