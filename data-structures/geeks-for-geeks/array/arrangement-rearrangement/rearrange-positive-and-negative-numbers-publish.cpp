// https://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers-publish/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
public:
    // time: O(n), memory: O(n)
    void rearrange(int arr[], int n) {
        int temp[n];
        int i = 0, j = 0, k = n - 1;
        while(i < n) {
            if (arr[i] >= 0) {
                temp[j] = arr[i];
                j++;
            } else {
                temp[k] = arr[i];
                k--;
            }
            i++;
        }
        i = 0, j = 0, k = n - 1;
        while(i < n) {
            if (i % 2 == 0) {
                if (temp[j] >= 0) {
                    arr[i] = temp[j];
                    j++;
                } else {
                    while(i < n) {
                        arr[i] = temp[k];
                        k--;
                        i++;
                    }
                    break;
                }
            } else {
                if (temp[k] < 0) {
                    arr[i] = temp[k];
                    k--;
                } else {
                    while(i < n) {
                        arr[i] = temp[j];
                        j++;
                        i++;
                    }
                    break;
                }
            }
            i++;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
