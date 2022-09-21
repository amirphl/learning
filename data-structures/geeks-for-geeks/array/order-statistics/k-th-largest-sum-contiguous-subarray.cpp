// https://www.geeksforgeeks.org/k-th-largest-sum-contiguous-subarray/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    // time: O(n*n + klogn), memory: O(n*n)
    int kthLargest(vector<int>& arr, int n, int k) {
        map<int, int> sums;
        int i = 0;
        while(i < n) {
            int j = i;
            int s = 0;
            while(j < n) {
                s += arr[j];
                sums[s]++;
                j++;
            }
            i++;
        }
        for(auto it = sums.rbegin(); it != sums.rend(); it++) {
            if (k <= it -> second) {
                return it -> first;
            } else {
                k -= it -> second;
            }
        }
        return -1;
    }
};

// { Driver Code Starts.

int main() {

    int T;
    cin>>T;
    while(T--) {
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0; i<N; i++) {
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}  // } Driver Code Ends
