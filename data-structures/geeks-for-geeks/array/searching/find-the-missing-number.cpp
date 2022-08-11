// https://www.geeksforgeeks.org/find-the-missing-number/

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




// } Driver Code Ends
// User function template for C++

class Solution {
public:
    // time: O(n), memory: O(1)
    int MissingNumber(vector<int>& arr, int n) {
        int i = 0, sum = 0;
        while(i < arr.size()) {
            sum += arr[i];
            i++;
        }
        return (n * (n + 1) / 2) - sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.MissingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends
