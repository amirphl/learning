// https://www.geeksforgeeks.org/temple-offerings/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // time: O(n), memory: O(n)
    // We can reduce memory to O(1)
    int offerings(int N, int arr[]) {
        vector<int> res(N, 1);
        int i = N - 2;
        while(i >= 0) {
            if (arr[i] > arr[i + 1]) {
                res[i] = res[i + 1] + 1;
            }
            i--;
        }
        int count = 0;
        i = 0;
        while(i < N - 1) {
            if (arr[i] < arr[i + 1] && res[i] >= res[i + 1]) {
                res[i + 1] = res[i] + 1;
            }
            count += res[i];
            i++;
        }
        count += res[N - 1];
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) {
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0; i < N; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.offerings(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
