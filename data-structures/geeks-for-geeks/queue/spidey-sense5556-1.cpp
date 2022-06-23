// https://practice.geeksforgeeks.org/problems/spidey-sense5556/1/

// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

public:
    // time: O(nm), memory: O(nm)
    vector<vector<int>> findDistance(vector<vector<char>>& mat, int m, int n) {
        vector<vector<int>> res(m);
        int i = 0, j = 0;
        while(i < m) {
            res[i] = vector<int>(n, -2);
            i++;
        }

        i = 0;
        queue<vector<int>> q;
        while(i < m) {
            j = 0;
            while(j < n) {
                if (mat[i][j] == 'B') {
                    q.push({i, j, 0});
                    res[i][j] = 0;
                } else if (mat[i][j] == 'W') {
                    res[i][j] = -1;
                }
                j++;
            }
            i++;
        }

        while(!q.empty()) {
            int u = q.front()[0];
            int v = q.front()[1];
            int dist = q.front()[2];
            q.pop();
            int p = u - 1;
            while(p <= u + 1) {
                int c = v - 1;
                while(c <= v + 1) {
                    int d = abs(p - u) + abs(c - v); // (p == u && c == v) is covered
                    if (d != 1 || p < 0 || m <= p || c < 0 || n <= c || res[p][c] == 0 || res[p][c] == -1) {
                        c++;
                        continue;
                    }
                    // This is very important: d + dist
                    if (res[p][c] == -2 || d + dist < res[p][c]) {
                        q.push({p, c, d + dist});
                        res[p][c] = d + dist;
                    }
                    c++;
                }
                p++;
            }
        }

        i = 0;
        while(i < m) {
            j = 0;
            while(j < n) {
                if (res[i][j] == -2) {
                    res[i][j] = -1;
                }
                j++;
            }
            i++;
        }

        return res;
    }
};

// { Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
        int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N);
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}  // } Driver Code Ends
