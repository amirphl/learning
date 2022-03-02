// https://www.geeksforgeeks.org/move-zeroes-end-array/
// https://www.geeksforgeeks.org/move-zeroes-end-array-set-2-using-single-traversal/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    // time: O(n), memory: O(1)
	void pushZerosToEnd(int arr[], int n) {
	    int i = 0, j = 0;

	    while (i < n) {
	        if (arr[i] != 0) {
	            arr[i - j] = arr[i];
	            i++;
	            continue;
	        }

            i++;
	        j++;
	    }

	    while (j > 0) {
	        arr[n - j] = 0;
	        j--;
	    }
	}

    // time: O(n), memory: O(1)
	void pushZerosToEndZeroTraversal(int arr[], int n) {
	    int i = 0, j = 0;

	    while (i < n) {
	        if (arr[i] != 0) {
	            arr[i - j] = arr[i];

	            if (j != 0)
	                arr[i] = 0;

	            i++;
	            continue;
	        }

            i++;
	        j++;
	    }
	}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
