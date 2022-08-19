// https://www.geeksforgeeks.org/minimum-product-pair-an-array-of-positive-integers/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution {
public:
    // time: O(n), memory: O(1)
    long long int printMinimumProduct(int arr[], int n) {
        if (n == 1) {
            return -1;
        }

        int f_min = arr[0], s_min = arr[1];
        if (arr[1] < arr[0]) {
            f_min = arr[1];
            s_min = arr[0];
        }
        int i = 2;

        while(i < n) {
            if (arr[i] < s_min) {
                if (arr[i] < f_min) {
                    s_min = f_min;
                    f_min = arr[i];
                } else {
                    s_min = arr[i];
                }
            }
            i++;
        }
        return (long long int) f_min * (long long int) s_min;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int i, a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        cout << obj.printMinimumProduct(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
