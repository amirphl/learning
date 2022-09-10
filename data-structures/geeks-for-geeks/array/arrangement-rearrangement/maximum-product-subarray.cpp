// https://www.geeksforgeeks.org/maximum-product-subarray/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
public:
    // Function to find maximum product subarray
    // time: O(n), memory: O(1)
    long long maxProduct(vector<int> arr, int n) {
        int pos = 0, neg = 0, z = 0;
        long long all_product = 1;
        int i = 0;
        while(i < n) {
            pos += (arr[i] > 0 ? 1 : 0);
            neg += (arr[i] < 0 ? 1 : 0);
            z += (arr[i] == 0 ? 1 : 0);
            all_product *= arr[i];
            i++;
        }
        if (pos > 0 && neg > 0 && z > 0) {
            // *
            return max_segment(arr);
        } else if (pos > 0 && neg > 0 && z == 0) {
            if (neg % 2 == 0) {
                return all_product;
            } else {
                // *
                return max_segment(arr);
            }
        } else if (pos > 0 && neg == 0 && z > 0) {
            // *
            return max_segment(arr);
        } else if (pos > 0 && neg == 0 && z == 0) {
            return all_product;
        } else if (pos == 0 && neg > 0 && z > 0) {
            if (neg == 1) {
                return 0;
            } else {
                // *
                long long res = max_segment(arr);
                if (res < 0) {
                    return 0;
                } else {
                    return res;
                }
            }
        } else if (pos == 0 && neg > 0 && z == 0) {
            if (neg == 1 || neg % 2 == 0) {
                return all_product;
            } else {
                // *
                return max_segment(arr);
            }
        } else if (pos == 0 && neg == 0 && z > 0) {
            return 0;
        } else if (pos == 0 && neg == 0 && z == 0) {
            return 0;
        }
    }

    long long max_segment(vector<int>& arr) {
        long long res = INT_MIN;
        int i = 0, n = arr.size();
        while(i < n) {
            if (arr[i] != 0) {
                int j = i;
                int pos = 0, neg = 0;
                long long all_product = 1;
                while(j < n && arr[j] != 0) {
                    pos += (arr[j] > 0 ? 1 : 0);
                    neg += (arr[j] < 0 ? 1 : 0);
                    all_product *= arr[j];
                    j++;
                }
                if (all_product > 0) {
                    res = max(res, all_product);
                } else if (pos > 0 && neg > 0) {
                    // neg % 2 == 1
                    res = max(res, exclude(arr, i, j));
                } else if (pos == 0 && neg > 0) {
                    if (neg == 1) {
                        res = max(res, all_product);
                    } else {
                        // neg % 2 == 1
                        res = max(res, exclude(arr, i, j));
                    }
                }
                i = j;
            } else {
                i++;
            }
        }
        return res;
    }

    long long exclude(vector<int>& arr, int start, int end) {
        long long all_product = 1;
        int i = start;
        while(i < end) {
            all_product *= arr[i];
            i++;
        }
        long long res = all_product;
        long long prefix_product = 1;
        i = start;
        while(i < end) {
            long long suffix_product = all_product / (prefix_product * arr[i]);
            res = max({res, prefix_product, suffix_product});
            prefix_product *= arr[i];
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
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
