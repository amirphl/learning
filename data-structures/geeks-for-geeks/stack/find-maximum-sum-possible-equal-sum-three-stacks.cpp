// https://www.geeksforgeeks.org/find-maximum-sum-possible-equal-sum-three-stacks/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    // time: O(n), memory: O(1)
    int maxEqualSum(int N1,int N2,int N3,vector<int> &v1,vector<int> &v2,vector<int> &v3) {
        int i = 0, j = 0, k = 0;
        int s1 = 0, s2 = 0, s3 = 0;
        for (auto& x: v1) {
            s1 += x;
        }
        for (auto& x: v2) {
            s2 += x;
        }
        for (auto& x: v3) {
            s3 += x;
        }
        while(i < N1 && j < N2 && k < N3) {
            int m = min({s1, s2, s3});
            while(s1 > m && i < N1) {
                s1 -= v1[i];
                i++;
            }
            while(s2 > m && j < N2) {
                s2 -= v2[j];
                j++;
            }
            while(s3 > m && k < N3) {
                s3 -= v3[k];
                k++;
            }
            if (s1 == s2 && s2 == s3) {
                return s1;
            }
        }
        return 0;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin>>t;
    while(t--) {
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0; i<n1; i++) {
            cin>>s1[i];
        }
        for(int i=0; i<n2; i++) {
            cin>>s2[i];
        }
        for(int i=0; i<n3; i++) {
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }

    return 0;
}  // } Driver Code Ends
