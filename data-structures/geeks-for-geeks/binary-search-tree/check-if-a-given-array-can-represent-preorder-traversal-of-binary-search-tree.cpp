// https://www.geeksforgeeks.org/check-if-a-given-array-can-represent-preorder-traversal-of-binary-search-tree/

// method 2: naive approach: time: O(n*n), memory: O(1)
// method 3: narrowing bound algorithm: time: O(n), memory: O(h)

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // time: O(n), memory: O(h)
    int canRepresentBST(int arr[], int N) {
        stack<int> lower;
        stack<int> upper;
        lower.push(INT_MIN);
        upper.push(INT_MAX);
        int i = 0;
        int low, high, found;
        while(i < N) {
            low = lower.top();
            high = upper.top();
            lower.pop();
            upper.pop();
            found = 1;
            while(low > arr[i] || high < arr[i]) {
                if (lower.empty()) {
                    found = 0;
                    break;
                }
                low = lower.top();
                high = upper.top();
                lower.pop();
                upper.pop();
            }
            if (!found) {
                break;
            }
            lower.push(arr[i]);
            lower.push(low);
            upper.push(high);
            upper.push(arr[i]);
            i++;
        }
        return i == N;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}  // } Driver Code Ends
