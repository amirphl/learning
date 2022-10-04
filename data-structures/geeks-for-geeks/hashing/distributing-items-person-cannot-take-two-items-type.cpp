// https://www.geeksforgeeks.org/distributing-items-person-cannot-take-two-items-type/

// { Driver Code Starts
// Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int isPossible(int N, int arr[], int K) {
        unordered_map<int, int> m;

        for(int i = 0; i < N; i++) {
            m[arr[i]]++;
        }

        for(auto &it: m) {
            if (it.second > 2 * K) {
                return false;
            }
        }

        return true;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) {
        int N, K;
        cin>>N;
        int arr[N];
        for(int i = 0; i < N; i++)
            cin>>arr[i];
        cin>>K;

        Solution ob;
        cout<<ob.isPossible(N, arr, K)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
