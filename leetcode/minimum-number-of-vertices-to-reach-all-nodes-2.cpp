// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& e) {
        int count = n;
        int indegree[n];
        memset(indegree, 0, sizeof(indegree));

        for(int i = 0; i < e.size(); i++) {
            if (indegree[e[i][1]] == 0) {
                count--;
            }

            indegree[e[i][1]]++;
        }

        vector<int> res(count);
        count = 0;

        for(int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                res[count++] = i;
            }
        }

        return res;
    }
};
