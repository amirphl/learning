// https://www.geeksforgeeks.org/find-the-maximum-repeating-number-in-ok-time/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:
    // Returns maximum repeating element in arr[0..n-1].
    // The array elements are in range from 0 to k-1
    // time: O(n), memory: O(1)
    int maxRepeating(int *arr, int n, int k) {
        int i = 0;
        while(i < n) {
            if (arr[i] >= 0) {
                int j = arr[i];
                arr[i] = -1;
                do {
                    int t = arr[j];
                    if (arr[j] < 0) {
                        arr[j]--;
                    } else {
                        arr[j] = -2;
                    }
                    j = t;
                } while(j >= 0);
            }
            i++;
        }
        int freq = arr[0], res = 0;
        i = 0;
        while(i < n) {
            if (arr[i] < freq) {
                freq = arr[i];
                res = i;
            }
            i++;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxRepeating(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
