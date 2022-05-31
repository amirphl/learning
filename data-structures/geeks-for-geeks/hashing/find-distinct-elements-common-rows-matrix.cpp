// https://www.geeksforgeeks.org/find-distinct-elements-common-rows-matrix/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // time: O(n*n), memory: O(n*n)
    int distinct(vector<vector<int>> M, int N)
    {
        vector<unordered_set<int>> v(N);
        int i = 0;
        while(i < N) {
            int j = 0;
            while(j < N) {
                v[i].insert(M[i][j]);
                j++;
            }
            i++;
        }
        i = 0;
        int count = 0;
        for(auto& x: v[0]) {
            bool common = true;
            int j = 1;
            while(j < N) {
                if (v[j].find(x) == v[j].end()) {
                    common = false;
                    break;
                }
                j++;
            }
            if (common) {
                count++;
            }
            i++;
        }
        return count;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> M(N, vector<int>(N, 0));
        for(int i = 0;i < N*N; i++)
            cin>>M[i/N][i%N];
        
        Solution ob;
        cout<<ob.distinct(M, N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
