// https://www.geeksforgeeks.org/longest-span-sum-two-binary-arrays/

// other method: https://www.geeksforgeeks.org/largest-subarray-with-equal-number-of-0s-and-1s/

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    // time: O(n*n), memory: O(n)
    int longestCommonSum2(bool arr1[], bool arr2[], int n) {
        int res = 0;
        int pre_1[n];
        int pre_2[n];
        pre_1[0] = arr1[0] ? 1 : 0;
        pre_2[0] = arr2[0] ? 1 : 0;
        if (pre_1[0] == pre_2[0]) {
            res = 1;
        }
        for(int i = 1; i < n; i++) {
            pre_1[i] = pre_1[i - 1] + (arr1[i] ? 1 : 0);
            pre_2[i] = pre_2[i - 1] + (arr2[i] ? 1 : 0);
            if (pre_1[i] == pre_2[i]) {
                res = i + 1;
            }
        }
        int i = 1, j = 0;
        while(i < n) {
            if (pre_1[i] - pre_1[j] == pre_2[i] - pre_2[j]) {
                res = max(res, i - j);
            }
            if (i == n - 1) {
                if (res == n) {
                    break;
                }
                i = j + res;
                j++;
                continue;
            }
            // cout << res << " ";
            i++;
        }
        // cout << endl;
        return res;
    }
    // time: O(n), memory: O(n)
    int longestCommonSum(bool arr1[], bool arr2[], int n) {
        int diff[2 * n + 1];
        memset(diff, -1, sizeof(diff));
        int max_len = 0;
        int i = 0;
        int d, pos;
        int sum_a = 0, sum_b = 0;
        while(i < n) {
            sum_a += arr1[i];
            sum_b += arr2[i];
            d = sum_a - sum_b;
            pos = (d + n) % (2 * n + 1);
            if (diff[pos] == -1) {
                diff[pos] = i;
            }
            if (d == 0) {
                max_len = i + 1;
            } else {
                // cout << i << " " << d << " " << pos << " " << diff[pos] << endl;
                max_len = max(max_len, i - diff[pos]);
            }
            i++;
            // cout << sum_a << " " << sum_b << " " << d << " " << max_len << endl;
        }
        return max_len;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        bool arr1[n], arr2[n];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.longestCommonSum(arr1, arr2, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
