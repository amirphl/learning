// https://leetcode.com/problems/most-beautiful-item-for-each-query/

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int n = items.size();
        int pre[n];
        pre[0] = items[0][1];

        // cout << items[0][0] << "," << items[0][1] << " ";
        for(int i = 1; i < n; i++) {
            pre[i] = max(pre[i - 1], items[i][1]);
            // cout << items[i][0] << "," << items[i][1] << " ";
        }
        // cout << endl;

        int m = queries.size();
        vector<int> res(m);

        for(int i = 0; i < m; i++) {
            int idx = upper_bound(items.begin(), items.end(), queries[i],[](double value, const vector<int>& item)
            {
                return value < item[0];
            }) - items.begin();
            // cout << idx << endl;

            if (idx == 0) {
                res[i] = 0;
            } else {
                res[i] = pre[idx - 1];
            }
        }

        return res;
    }
};
