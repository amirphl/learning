// https://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers/
// https://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers-publish/
// https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/
// https://www.geeksforgeeks.org/rearrange-array-in-alternating-positive-negative-items-with-o1-extra-space-set-2/
// https://www.geeksforgeeks.org/rearrange-positive-negative-numbers-using-inbuilt-sort-function/
// https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/
// https://www.geeksforgeeks.org/move-ve-elements-end-order-extra-space-allowed/
// https://www.geeksforgeeks.org/positive-elements-at-even-and-negative-at-odd-positions-relative-order-not-maintained/
// https://www.geeksforgeeks.org/segregate-even-odd-numbers-set-3/

// other approaches:
// method 2 (doesn't maintain the order of appearance): using partition process of quick sort (pivot = 0): time: O(n), memory: O(1)
// method 3 (       maintains the order of appearance): right rotate the array starting at element at incorrect position with next element which should be replaced with it: time: O(n*n), memory: O(1)
// method 4 (doesn't maintain the order of appearance): sort then rearrange: time: O(nlogn), memory: O(1)
// method 5 (doesn't maintain the order of appearance): two pointer technique: time: O(n), memory: O(1)

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
      
        Rearrange( arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} // } Driver Code Ends

void left_shift(int arr[], int i, int j, int d)
{
    std::reverse(arr + i, arr + i + d);
    std::reverse(arr + i + d, arr + j + 1);
    std::reverse(arr + i, arr + j + 1);
}


// time: O(nlogn), memory: O(logn)
void rearr(int arr[], int low, int high)
{
    if (low >= high)
        return;
    
    if (low + 1 == high)
    {
        if (arr[low] >= 0 && arr[high] < 0)
        {
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }

        return;
    }

    int mid = (low + high) / 2;

    rearr(arr, low, mid);
    rearr(arr, mid + 1, high);

    int left_b = mid + 1;
    for (int i = low; i <= mid; i++)
        if (arr[i] >= 0)
        {
            left_b = i;
            break;
        }

    int right_b = mid;
    for (int i = high; i >= mid + 1; i--)
        if (arr[i] < 0)
        {
            right_b = i;
            break;
        }

    left_shift(arr, left_b, right_b, mid - left_b + 1);
}

// maintains the order of appearance
// time: O(nlogn)
// memory: O(logn)
void Rearrange(int arr[], int n)
{
    rearr(arr, 0, n - 1);
}
