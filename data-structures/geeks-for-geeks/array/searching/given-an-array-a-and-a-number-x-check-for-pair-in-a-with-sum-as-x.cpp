// https://www.geeksforgeeks.org/given-an-array-a-and-a-number-x-check-for-pair-in-a-with-sum-as-x/
// TODO(amirphl) remainder approach
// TODO(amirphl) https://www.geeksforgeeks.org/given-two-unsorted-arrays-find-pairs-whose-sum-x/
// TODO(amirphl) https://www.geeksforgeeks.org/count-pairs-with-given-sum/
// TODO(amirphl) https://www.geeksforgeeks.org/count-pairs-difference-equal-k/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value

	// sort + two pointer technique
	// time: O(nlogn), memory: O(1)
	bool hasArrayTwoCandidates1(int arr[], int n, int x) {
	    if (n < 2)
	        return false;
	    std::sort(arr, arr + n);
	    int i = 0, j = n - 1;
	    while(i < n && j > -1 && j > i) {
	        if (arr[i] + arr[j] == x)
	            return true;
	        if (arr[i] + arr[j] < x)
	            i++;
	        else
	            j--;
 	    }
 	    return false;
	}

    // set
    // time: O(nlogn), memory: O(n)
    // You can also store index of the elements by using a Map instead of a set.
    bool hasArrayTwoCandidates(int arr[], int n, int x) {
        std::set<int> m;
        int i = -1;
        while(++i < n) {
            if (m.find(x - arr[i]) == m.end())
                m.insert(arr[i]);
            else
                return true;
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}
  // } Driver Code Ends
