// https://www.geeksforgeeks.org/find-the-count-of-unvisited-indices-in-an-infinite-array/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution {
public:
    int candies(int m, int n)
    {
        queue<int> q;
        unordered_set<int> un_visited;
        q.push(m * n - m - n);
        un_visited.insert(m * n - m - n);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if (u - m > 0 && un_visited.find(u - m) == un_visited.end()) {
                q.push(u - m);
                un_visited.insert(u - m);
            }
            if (u - n > 0 && un_visited.find(u - n) == un_visited.end()) {
                q.push(u - n);
                un_visited.insert(u - n);
            }
        }
        return un_visited.size();
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        Solution obj;
        cout << obj.candies(m,n)<<endl;
    }
    return 0;
}



// } Driver Code Ends
