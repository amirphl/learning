// https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/
// https://www.geeksforgeeks.org/duplicates-array-using-o1-extra-space-set-2/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    // time: O(n), memory: O(1)
    vector<int> duplicates(int arr[], int n) {
        vector<int> res;

        for(int i = 0; i < n; i++) {
            if (arr[i] <= -1) {
                continue;
            }

            int j = arr[i];
            arr[i] = -1;

            while(arr[j] > -1) {
                int temp = arr[j];
                arr[j] = -2;
                j = temp;
            }

            arr[j]--;
        }

        for(int i = 0; i < n; i++) {
            if (arr[i] <= -3) {
                res.push_back(i);
            }
        }

        if (res.empty()) {
            res.push_back(-1);
        }

        return res;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
