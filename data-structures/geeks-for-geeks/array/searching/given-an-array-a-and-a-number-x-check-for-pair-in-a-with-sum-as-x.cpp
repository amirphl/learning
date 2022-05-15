// https://www.geeksforgeeks.org/given-an-array-a-and-a-number-x-check-for-pair-in-a-with-sum-as-x/
// https://www.geeksforgeeks.org/given-two-unsorted-arrays-find-pairs-whose-sum-x/
// https://www.geeksforgeeks.org/count-pairs-with-given-sum/
//
// other approaches:
// method 1: Using remainders of the elements less than x: time: O(n + x), memory: O(x)
// notes:
// To handle the duplicates, use hashmap of frequencies.

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

    // approach: using set
    // time: O(n), memory: O(n)
    // You can also store index of the elements by using a Map instead of a set.
    bool hasArrayTwoCandidates(int arr[], int n, int x) {
        std::unordered_set<int> m;
        int i = -1;
        while(++i < n) {
            if (m.find(x - arr[i]) == m.end())
                m.insert(arr[i]);
            else
                return true;
        }
        return false;
    }

    // to find all pairs (A has distinct elements, B has distinct elements also):
    // time: O(nlogn), memory: O(n)
    // notes:
    // A and B are not sorted.
    // The output is sorted by the first element of the pair. The time complexity can be reduced to O(n) if ignoring the sorted output.
    // More info: https://practice.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x5808/1/
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X) {
        vector<pair<int,int>> res;
        set<int> s1(A, A + N);
        unordered_set<int> s2(B, B + M);
        for(auto &it: s1) {
            if (s2.find(X - it) != s2.end()) {
                res.push_back({it, X - it});
            }
        }
        return res;
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
