// https://www.geeksforgeeks.org/rearrange-array-order-smallest-largest-2nd-smallest-2nd-largest/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    // time: O(nlogn), memory: O(n)
    void rearrangeArray(int arr[], int n) {
        std::sort(arr, arr + n);

        int mid = n / 2;
        int brr[n];

        for (int i = 0, j = 0; i < n; i += 2)
            brr[i] = arr[j++];

        for (int i = 1, j = n - 1; i < n; i += 2)
            brr[i] = arr[j--];

        for (int i = 0; i < n; i++)
            arr[i] = brr[i];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        obj.rearrangeArray(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
