// https://www.geeksforgeeks.org/longest-subsequence-difference-adjacents-one-set-2/
// https://www.geeksforgeeks.org/longest-subsequence-such-that-difference-between-adjacents-is-one/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    // time: O(n), memory: O(n)
    int longLenSub(int arr[], int n)
    {
        unordered_map<int, int> m;
        int max_ends_so_far = arr[0];
        int len_ends_so_far = 1;
        m[arr[0]] = 1;

        for(int i = 1; i < n; i++) {
            if (abs(max_ends_so_far - arr[i]) == 1) {
                max_ends_so_far = arr[i];
                len_ends_so_far++;
                m[arr[i]] = len_ends_so_far;
            } else {
                m[arr[i]] = max({m[arr[i] - 1], m[arr[i] + 1]}) + 1;

                if (m[arr[i]] > len_ends_so_far) {
                    max_ends_so_far = arr[i];
                    len_ends_so_far = m[arr[i]];
                }
            }
        }

        return len_ends_so_far;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n],i;
        for(i=0;i<n;i++)
        cin>>a[i];
        Solution ob;
        cout<< ob.longLenSub(a, n)<<endl;
        
    }
    
    return 0;
}
  // } Driver Code Ends
