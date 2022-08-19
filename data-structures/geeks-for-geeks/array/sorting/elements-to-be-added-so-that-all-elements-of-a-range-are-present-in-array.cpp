// https://www.geeksforgeeks.org/elements-to-be-added-so-that-all-elements-of-a-range-are-present-in-array/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
public:
    // time: O(n), memory: O(n)
    int countElements(int n, int arr[]) {
        int max_elem = arr[0], min_elem = arr[0];
        int i = 0;
        unordered_set<int> s;
        while(i < n) {
            max_elem = max(max_elem, arr[i]);
            min_elem = min(min_elem, arr[i]);
            s.insert(arr[i]);
            i++;
        }
        return max_elem - min_elem + 1 - s.size();
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];
        Solution ob;
        cout << ob.countElements(N, A) << "\n";
    }
}
// } Driver Code Ends
