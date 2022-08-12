// https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(n), memory: O(1)
    int *findTwoElement(int *arr, int n) {
        int i = 0;
        int X = 0;
        while(i < n) {
            X += (arr[i] - (i + 1));
            i++;
        }
        i = 0;
        while(i < n) {
            if (arr[i] != -1) {
                int j = arr[i] - 1;
                do {
                    int temp = arr[j];
                    arr[j] = -1;
                    j = temp - 1;
                } while(j > -1);
            }
            i++;
        }
        int* res = new int[2];
        i = 0;
        while(i < n) {
            if (arr[i] != -1) {
                res[1] = i + 1;
                break;
            }
            i++;
        }
        res[0] = res[1] + X;
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
