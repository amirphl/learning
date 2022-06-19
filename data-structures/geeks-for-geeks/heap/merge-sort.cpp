// https://www.geeksforgeeks.org/merge-sort

// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
public:
    // time: O(n), memory: O(n)
    void merge(int arr[], int l, int m, int r)
    {
        int brr[r - l + 1];
        int i = l;
        int j = m + 1;
        int c = 0;
        while(i <= m || j <= r) {
            int x = i <= m ? arr[i] : INT_MAX;
            int y = j <= r ? arr[j] : INT_MAX;
            if (x < y) {
                brr[c] = arr[i];
                i++;
            } else {
                brr[c] = arr[j];
                j++;
            }
            c++;
        }
        i = l;
        while(i <= r) {
            arr[i] = brr[i - l];
            i++;
        }
    }
public:
    // time: O(nlogn), memory: O(n)
    void mergeSort(int arr[], int l, int r)
    {
        if (l >= r) {
            return;
        }
        if (l == r - 1) {
            int first = arr[l];
            int second = arr[r];
            arr[l] = min(first, second);
            arr[r] = max(first, second);
            return;
        }
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--) {

        scanf("%d",&n);
        int arr[n+1];
        for(i=0; i<n; i++)
            scanf("%d",&arr[i]);

        Solution ob;
        ob.mergeSort(arr, 0, n-1);
        printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends
