// https://www.geeksforgeeks.org/given-two-unsorted-arrays-find-pairs-whose-sum-x/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // time: O(nlogn), memory: O(1)
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        vector<pair<int,int>> res;
        sort(A, A + N);
        sort(B, B + M);
        int i = 0, j = M - 1;
        while(i < N && j > -1) {
            if (A[i] + B[j] < X) {
                i++;
            } else if (A[i] + B[j] == X) {
                res.push_back({A[i], B[j]});
                i++;
                j--;
            } else {
                j--;
            }
        }
        return res;
    }
};


// { Driver Code Starts.
int main() {
    long long t;
    cin >> t;

    while(t--) {
        int N, M, X;
        cin >> N >> M >> X;
        int A[N], B[M];

        for(int i = 0; i<N; i++)
            cin >> A[i];
        for(int i = 0; i<M; i++)
            cin >> B[i];

        Solution ob;
        vector<pair<int,int>> vp = ob.allPairs(A, B, N, M, X);
        int sz = vp.size();
        if(sz==0)
            cout<<-1<<endl;
        else {
            for(int i=0; i<sz; i++) {
                if(i==0)
                    cout<<vp[i].first<<" "<<vp[i].second;
                else
                    cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends
