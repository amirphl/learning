// https://www.geeksforgeeks.org/maximum-sum-pairs-specific-difference/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // time: O(nlogn), memory: O(1)
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        sort(arr, arr + N);
        int sum = 0;
        int i = N - 1;
        while(i > 0) {
            if (arr[i] - arr[i - 1] < K) {
                sum += arr[i] + arr[i - 1];
                i -= 2;
            } else {
                i--;
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        int K;
        cin>>K;
        Solution ob;
        cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
    }
    return 0;
}

// } Driver Code Ends
