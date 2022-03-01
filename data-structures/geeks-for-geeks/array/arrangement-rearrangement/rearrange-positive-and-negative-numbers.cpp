// https://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers/
// https://www.geeksforgeeks.org/move-ve-elements-end-order-extra-space-allowed/

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


// time: O(nlogn) - memory: O(1) - [We can say memory is O(logn) because of recursive calls]
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


void Rearrange(int arr[], int n)
{
    rearr(arr, 0, n - 1);
}

// other methods:
// Modified Partition Process of Quick Sort: time: O(n*n), memory: O(1)
// Modified Insertion Sort: time: O(n*n), memory: O(1)
