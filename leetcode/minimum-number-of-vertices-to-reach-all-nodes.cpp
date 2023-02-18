// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& e) {
        sort(e.begin(), e.end());

        int m = e.size();
        int index[n];
        memset(index, -1, sizeof(index));
        index[e[0][0]] = 0;

        for(int i = 1; i < m; i++) {
            if (e[i][0] != e[i - 1][0]) {
                index[e[i][0]] = i;
            }
        }

        int count = 0;
        bool prev[n];
        bool vis[n];
        memset(vis, 0, sizeof(vis));
        memset(prev, 0, sizeof(prev));

        for(int i = 0; i < n; i++) {
            if (!vis[i]) {
                queue<int> q;
                q.push(i);
                vis[i] = 1;

                while(!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for(int j = index[node]; j != -1 && j < m && e[j][0] == node; j++) {
                        int neigh = e[j][1];

                        if (!vis[neigh]) {
                            q.push(neigh);
                            vis[neigh] = 1;
                        } else if (prev[neigh]) {
                            prev[neigh] = 0;
                            count--;
                        }
                    }
                }

                prev[i] = 1;
                count++;
            }
        }

        vector<int> res(count);
        count = 0;

        for(int i = 0; i < n; i++) {
            if (prev[i]) {
                res[count++] = i;
            }
        }

        return res;
    }
};
