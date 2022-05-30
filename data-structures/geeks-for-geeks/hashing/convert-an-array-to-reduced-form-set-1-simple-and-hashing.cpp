// https://www.geeksforgeeks.org/convert-an-array-to-reduced-form-set-1-simple-and-hashing/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
	// time: O(nlogn), memory: O(n)
	void convert(int arr[], int n) {
	    array<int, 2> temp[n];
	    int i = 0;
	    while(i < n) {
	        temp[i] = {arr[i], i};
	        i++;
	    }
	    sort(temp, temp + n);
	    i = 0;
	    while(i < n) {
	        arr[temp[i][1]] = i;
	        i++;
	    }
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.convert(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
