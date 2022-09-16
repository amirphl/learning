// https://www.geeksforgeeks.org/longest-increasing-subarray/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution {
public:
    // time: O(n), memory: O(1)
    long int lenOfLongIncSubArr(long int arr[], long int n) {
        long long res = 0;
        long long count = 0;
        long long i = 0;
        while(i < n - 1) {
            if (arr[i] < arr[i + 1]) {
                count++;
            } else {
                res = max(res, count);
                count = 0;
            }
            i++;
        }
        res = max(res, count) + 1;
        return res;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long int n;
        cin >> n;
        long int arr[n], i;
        for (i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.lenOfLongIncSubArr(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
