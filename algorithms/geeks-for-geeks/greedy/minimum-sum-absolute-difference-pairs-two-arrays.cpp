// https://www.geeksforgeeks.org/minimum-sum-absolute-difference-pairs-two-arrays/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    // time: O(nlogn), memory: O(1)
    long long findMinSum(vector<int>& arr1, vector<int>& arr2, int n) {
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        long long res = 0;
        int i = 0;
        while(i < n) {
            res += abs(arr1[i] - arr2[i]);
            i++;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) {
        int N;
        cin>>N;
        vector<int> A(N),B(N);
        for(int i=0; i<N; i++) {
            cin>>A[i];
        }
        for(int i=0; i<N; i++) {
            cin>>B[i];
        }
        Solution ob;
        cout<<ob.findMinSum(A,B,N)<<endl;
    }
}
// } Driver Code Ends
