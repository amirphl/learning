// https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // time O(n) memory O(n)
    int findSubArraySum(int arr[], int n, int k)
    {
        int res = 0;
        unordered_map<int, int> m;
        int cum[n];
        cum[0] = arr[0];
        m[cum[0]]++;

        for(int i = 1; i < n; i++) {
            cum[i] = cum[i - 1] + arr[i];
            res += m[cum[i] - k];
            m[cum[i]]++;
            if (cum[i] == k) {
                res++;
            }
        }

        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends
