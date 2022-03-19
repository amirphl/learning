// https://www.geeksforgeeks.org/rearrange-array-maximum-minimum-form/

// { Driver Code Starts
// C++ program to rearrange an array in minimum
// maximum form
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange the array elements alternately.
    // time: O(n), space: O(n)
    void rearrange2(long long *arr, int n)
    {
        long long brr[n];

        for (int i = n - 1, j = 0; i >= 0, j < n; i--, j += 2)
        {
            brr[j] = arr[i];
        }

        for (int i = 0, j = 1; i < n, j < n; i++, j += 2)
        {
            brr[j] = arr[i];
        }

        for(int i = 0; i < n; i++)
            arr[i] = brr[i];
    }

    // by geeksforgeeks
    // time: O(n), space: O(n)
    void rearrange(long long arr[], int n)
    {
        // Auxiliary array to hold modified array
        long long temp[n];

        // Indexes of smallest and largest elements
        // from remaining array.
        int small = 0, large = n - 1;

        // To indicate whether we need to copy remaining
        // largest or remaining smallest at next position
        int flag = true;

        // Store result in temp[]
        for (int i = 0; i < n; i++) {
            if (flag)
                temp[i] = arr[large--];
            else
                temp[i] = arr[small++];

            flag = !flag;
        }

        // Copy temp[] to arr[]
        for (int i = 0; i < n; i++)
            arr[i] = temp[i];
    }
};

// { Driver Code Starts.

// Driver program to test above function
int main()
{
    int t;

    //testcases
    cin >> t;

    while(t--){

        //size of array
        int n;
        cin >> n;

        long long arr[n];

        //adding elements to the array
        for(int i = 0;i<n;i++){
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
