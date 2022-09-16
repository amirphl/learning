// https://www.geeksforgeeks.org/number-pairs-maximum-sum/

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    // time: O(n), memory: O(1)
    int MaximumSum(int arr[], int n)
    {
        if (n == 1) {
            return 0;
        }
        int max_1 = arr[0], max_2;
        int c_1 = 1, c_2 = 0;
        int i = 1;
        while(i < n && arr[i] == max_1) {
            c_1++;
            i++;
        }
        if (i == n) {
            return n * (n - 1) / 2;
        }
        if (arr[i] > max_1) {
            max_2 = max_1;
            c_2 = c_1;
            max_1 = arr[i];
            c_1 = 1;
        } else {
            max_2 = arr[i];
            c_2 = 1;
        }
        i++;
        while(i < n) {
            if (max_1 < arr[i]) {
                max_2 = max_1;
                c_2 = c_1;
                max_1 = arr[i];
                c_1 = 1;
            } else if (max_1 == arr[i]) {
                c_1++;
            } else if (max_2 < arr[i]) {
                max_2 = arr[i];
                c_2 = 1;
            } else if (max_2 == arr[i]) {
                c_2++;
            }
            i++;
        }
        if (1 < c_1) {
            return c_1 * (c_1 - 1) / 2;
        } else {
            return c_2;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n],i;
        for(i=0; i<n; i++)
            cin>>a[i];
        Solution ob;
        cout << ob.MaximumSum(a, n)<<endl;
    }

    return 0;
}



// } Driver Code Ends
