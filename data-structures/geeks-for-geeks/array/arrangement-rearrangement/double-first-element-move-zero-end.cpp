// https://www.geeksforgeeks.org/double-first-element-move-zero-end/

// { Driver Code Starts
//Initial Template for C++

// C++ implementation to rearrange the array
// elements after modification
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // time: O(n), memory: O(1)
    void modifyAndRearrangeArr(int arr[], int n)
    {
    	for (int i = 0; i < n - 1; i++)
    	    if (arr[i + 1] != 0 && arr[i + 1] == arr[i])
    	    {
    	        arr[i] *= 2;
    	        i++;
    	        arr[i] = 0;
    	    }

        for (int i = 0, j = 0; i < n && j < n; i++)
        {
            if (arr[i] == 0)
            {
                if (j <= i)
                {
                    j = i;

                    while (++j < n)
                        if (arr[j] != 0)
                            break;

                    if (j == n)
                        break;
                }

                arr[i] = arr[j];
                arr[j] = 0;

                while (++j < n)
                    if (arr[j] != 0)
                        break;
            }
        }
    }
};


// { Driver Code Starts.
// Driver program to test above
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        ob.modifyAndRearrangeArr(arr, n);
        for(int i=0;i<n;i++)
            cout << arr[i] << " ";
        cout << endl;

    }

	return 0;
}
  // } Driver Code Ends
