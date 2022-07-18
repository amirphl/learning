// https://www.geeksforgeeks.org/minimum-removals-array-make-max-min-k/

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    // time: O(n*n), memory: O(n)
    int removals2(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int* dp = new int[n];
        int* nxt = new int[n];
        int i = n - 1;
        while(i >= 0) {
            dp[i] = 0;
            int j = i + 1;
            while(j < n) {
                if (arr[j] - arr[i] <= k) {
                    dp[j] = 0;
                } else {
                    int c1 = i < n - 1 ? nxt[j] : 0;
                    int c2 = dp[j - 1];
                    dp[j] = 1 + min(c1, c2);
                }
                j++;
            }
            int* temp = dp;
            dp = nxt;
            nxt = dp;
            i--;
        }
        // TODO delete dp[] and nxt[]
        return nxt[n - 1];
    }

    // time: O(logn), memory: O(1)
    int search(int i, int j, int k_prime, vector<int>& arr) {
        while(i <= j) {
            if (i == j) {
                return i;
            }
            if (i + 1 == j) {
                if (arr[j] <= k_prime) {
                    return j;
                } else {
                    return i;
                }
            }
            int mid = (i + j) / 2;
            if (arr[mid] <= k_prime) {
                i = mid;
            } else {
                j = mid - 1;
            }
        }
        return -1;
    }

    // time: O(nlogn), memory: O(1)
    int removals(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int i = 0, n = arr.size();
        int res = 1;
        while(i < n - 1) {
            int j = search(i, n - 1, k + arr[i], arr);
            res = max(res, j -  i + 1);
            i++;
        }
        return n - res;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin>>t;

    while(t--) {
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }

        Solution ob;
        int ans = ob.removals(a,k);

        cout<<ans<<endl;
    }
}



// } Driver Code Ends
