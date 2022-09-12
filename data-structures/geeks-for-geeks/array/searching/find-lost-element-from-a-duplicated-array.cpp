// https://www.geeksforgeeks.org/find-lost-element-from-a-duplicated-array/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // time: O(n), memory: O(n)
    vector<long long> findMissing(long long A[], long long B[],
                                  int N, int M)
    {
        unordered_set<long long> s(B, B + M);
        vector<long long> res;
        int i = 0;
        while(i < N) {
            if (s.find(A[i]) == s.end()) {
                res.push_back(A[i]);
            }
            i++;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main()
{


    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        long long a[n];
        long long b[m];
        for(int i=0; i<n; i++)
            cin>>a[i];
        for(int i=0; i<m; i++)
            cin >> b[i];
        vector<long long> ans;


        Solution ob;
        ans=ob.findMissing(a,b,n,m);
        for(int i=0; i<ans.size(); i++)
            cout<<ans[i]<<" ";


        cout << "\n";

    }
    return 0;
}
// } Driver Code Ends
