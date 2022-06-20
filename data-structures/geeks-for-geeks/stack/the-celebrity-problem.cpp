// https://www.geeksforgeeks.org/the-celebrity-problem/

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    //Function to find if there is a celebrity in the party or not.
    // time: O(n), memory: O(1)
    int celebrity(vector<vector<int> >& M, int n)
    {
        int curr = 0;
        int next = 1;
        while(next <= n - 1) {
            if ((M[curr][next] == 1 && M[next][curr] == 1) || M[curr][next] == 0 && M[next][curr] == 0) {
                curr = next + 1;
                next = next + 2;
            } else if (M[curr][next] == 1) {
                curr = next;
                next++;
            } else {
                next++;
            }
        }
        int i = 0;
        bool candid = curr < n;
        while(i < n && candid) {
            if (i == curr) {
                i++;
                continue;
            }
            if (M[curr][i] == 1 || M[i][curr] == 0) {
                candid = false;
                break;
            }
            i++;
        }
        if (candid) {
            return curr;
        }
        i = 0;
        candid = next < n;
        while(i < n && candid) {
            if (i == next) {
                i++;
                continue;
            }
            if (M[next][i] == 1 || M[i][next] == 0) {
                candid = false;
                break;
            }
            i++;
        }
        if (candid) {
            return next;
        }
        return -1;
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
        vector<vector<int> > M( n, vector<int> (n, 0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
// } Driver Code Ends
