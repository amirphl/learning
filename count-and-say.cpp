// https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        queue<int> q;
        q.push(1);
        for(int i = 0; i < n - 1; i++) {
            int m = q.size();
            for(int j = 0, k = 0; j < m; j++) {
                int f = q.front();
                q.pop();
                if (j + 1 < m && f == q.front()) {
                    k++;
                } else {
                    char freq = k + 1;
                    q.push(k + 1);
                    q.push(f);
                    k = 0;
                }
            }
        }

        string s(q.size(), ' ');
        int i = 0;
        while(!q.empty()) {
            s[i] = '0' + q.front();
            q.pop();
            i++;
        }

        return s;
    }
};
