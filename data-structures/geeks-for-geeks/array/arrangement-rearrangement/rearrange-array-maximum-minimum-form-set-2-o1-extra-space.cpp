// https://www.geeksforgeeks.org/rearrange-array-maximum-minimum-form-set-2-o1-extra-space/

// { Driver Code Starts
// C++ program to rearrange an array in minimum
// maximum form
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    // time: O(n), memory: O(1)
    void rearrange(long long *arr, int n)
    {
        long long max_ele = *max_element(arr, arr + n) + 1;
        int i = 0, j = 0, k = n - 1;
        while(i < n) {
            if (i % 2 == 0) {
                arr[i] += (arr[k] % max_ele) * max_ele;
                k--;
            } else {
                arr[i] += (arr[j] % max_ele) * max_ele;
                j++;
            }
            i++;
        }
        i = 0;
        while(i < n) {
            arr[i] /= max_ele;
            i++;
        }
    }
};

// { Driver Code Starts.

// Driver program to test above function
int main()
{
    int t;

    //testcases
    cin >> t;

    while(t--) {

        //size of array
        int n;
        cin >> n;

        long long arr[n];

        //adding elements to the array
        for(int i = 0; i<n; i++) {
            cin >> arr[i];
        }

        Solution ob;

        //calling rearrange() function
        ob.rearrange(arr, n);

        //printing the elements
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
