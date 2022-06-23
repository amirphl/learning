// https://www.geeksforgeeks.org/minimum-steps-reach-target-knight/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find out minimum steps Knight needs to reach target position.
    // time: O(n*n), memory: O(n*n)
    int minStepToReachTarget(vector<int>& k, vector<int>& t, int n)
    {
        k[0]--;
        k[1]--;
        t[0]--;
        t[1]--;
        int level = 0;
        vector<vector<bool>> visited(n);
        int i = 0;
        while(i < n) {
            visited[i] = vector<bool>(n, false);
            i++;
        }
        queue<vector<int>> q;
        q.push(k);
        q.push({-1, -1});
        while(q.size() > 1) {
            int i = q.front()[0];
            int j = q.front()[1];
            q.pop();
            if (i == -1) {
                level++;
                q.push({-1, -1});
                continue;
            }
            if (i == t[0] && j == t[1]) {
                return level;
            }
            if (-1 < i - 2 && j + 1 < n && !visited[i - 2][j + 1]) {
                visited[i - 2][j + 1] = true;
                q.push({i - 2, j + 1});
            }
            if (-1 < i - 1 && j + 2 < n && !visited[i - 1][j + 2]) {
                visited[i - 1][j + 2] = true;
                q.push({i - 1, j + 2});
            }
            if (i + 1 < n && j + 2 < n && !visited[i + 1][j + 2]) {
                visited[i + 1][j + 2] = true;
                q.push({i + 1, j + 2});
            }
            if (i + 2 < n && j + 1 < n && !visited[i + 2][j + 1]) {
                visited[i + 2][j + 1] = true;
                q.push({i + 2, j + 1});
            }
            if (i + 2 < n && -1 < j - 1 && !visited[i + 2][j - 1]) {
                visited[i + 2][j - 1] = true;
                q.push({i + 2, j - 1});
            }
            if (i + 1 < n && -1 < j - 2 && !visited[i + 1][j - 2]) {
                visited[i + 1][j - 2] = true;
                q.push({i + 1, j - 2});
            }
            if (-1 < i - 1 && -1 < j - 2 && !visited[i - 1][j - 2]) {
                visited[i - 1][j - 2] = true;
                q.push({i - 1, j - 2});
            }
            // if (level == 1) {
            //     cout << i << " " << j << endl;
            //     return 100;
            // }
            if (-1 < i - 2 && -1 < j - 1 && !visited[i - 2][j - 1]) {
                visited[i - 2][j - 1] = true;
                q.push({i - 2, j - 1});
            }
        }
        return -1;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        vector<int>KnightPos(2);
        vector<int>TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans <<"\n";
    }
    return 0;
}  // } Driver Code Ends
