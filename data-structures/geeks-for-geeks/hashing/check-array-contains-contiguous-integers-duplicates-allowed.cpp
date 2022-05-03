// https://www.geeksforgeeks.org/check-array-contains-contiguous-integers-duplicates-allowed/

// method 2: sorting
// method 3: unordered_set, min, max, max - min + 1 == unordered_set.size()

// { Driver Code Starts
// C++ implementation to check whether the array
// contains a set of contiguous integers
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    // Function to check whether the array contains
    // a set of contiguous integers
    // time: O(n), memory: O(n)
    bool areElementsContiguous(int arr[], int n)
    {
        int min = arr[0];
        int max = arr[0];
        unordered_set<int> s;
        s.insert(min);

	    for(int i = 1; i < n; i++) {
	        if (s.find(arr[i]) == s.end()) {
	            if (arr[i] < min) {
	                min = arr[i];
	            }
	            if (max < arr[i]) {
	                max = arr[i];
	            }
	            s.insert(arr[i]);
	        }
	    }
	    while(min <= max) {
	        if (s.find(min) == s.end()) {
	            return false;
	        }
	        min++;
	    }
	    return true;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n + 1];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        if (ob.areElementsContiguous(arr, n))
            cout << "Yes" <<endl;
        else
            cout << "No" <<endl;
    }
	return 0;
}
  // } Driver Code Ends
