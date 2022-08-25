// https://www.geeksforgeeks.org/find-a-peak-in-a-given-array/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
class Solution
{
public:
    // time: O(logn), memory: O(1)
    int peakElement(int arr[], int n)
    {
        if (n == 1) {
            return 0;
        }
        int i = 0, j = n - 1;
        while(i < j) {
            if (i + 1 == j) {
                int res = arr[i] <= arr[j] ? j : i;
                return res;
            }
            int mid = (i + j) / 2;
            if (arr[mid] >= max(arr[mid - 1], arr[mid + 1])) {
                return mid;
            }
            if (arr[mid - 1] >= arr[mid] && arr[mid] >= arr[mid + 1]) {
                j = mid;
            } else {
                i = mid;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n], tmp[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            tmp[i] = a[i];
        }
        bool f=0;
        Solution ob;

        int A = ob. peakElement(tmp,n);

        if(A<0 and A>=n)
            cout<<0<<endl;
        else
        {
            if(n==1 and A==0)
                f=1;
            else if(A==0 and a[0]>=a[1])
                f=1;
            else if(A==n-1 and a[n-1]>=a[n-2])
                f=1;
            else if(a[A]>=a[A+1] and a[A]>= a[A-1])
                f=1;
            else
                f=0;
            cout<<f<<endl;
        }

    }

    return 0;
}
// } Driver Code Ends
