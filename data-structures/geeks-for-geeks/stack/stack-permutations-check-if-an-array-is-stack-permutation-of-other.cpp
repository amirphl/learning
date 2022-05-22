// https://www.geeksforgeeks.org/stack-permutations-check-if-an-array-is-stack-permutation-of-other/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    // time: O(n), memory: O(n)
    int isStackPermutation(int N, vector<int> &A, vector<int> &B){
        stack<int> s;
        int j = 0;
        for(int i = 0; i < N; i++) {
            if (s.empty()) {
                while(j < N) {
                    s.push(A[j]);
                    j++;
                    if (s.top() == B[i]) {
                        break;
                    }
                }
                if (s.top() == B[i]) {
                    s.pop();
                } else {
                    return 0;
                }
                continue;
            }
            if (s.top() == B[i]) {
                s.pop();
            } else {
                while(j < N) {
                    s.push(A[j]);
                    j++;
                    if (s.top() == B[i]) {
                        break;
                    }
                }
                if (s.top() == B[i]) {
                    s.pop();
                } else {
                    return 0;
                }
            }
        }
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends
