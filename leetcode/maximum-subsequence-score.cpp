// https://leetcode.com/problems/maximum-subsequence-score/

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<vector<int>> pairs(n);

        for(int i = 0; i < n; i++)
            pairs[i] = {nums2[i], nums1[i]};

        sort(pairs.begin(), pairs.end(), greater<vector<int>>());

        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;

        for(int i = 0; i < k; i++) {
            sum += pairs[i][1];
            pq.push(pairs[i][1]);
        }

        long long ans = sum * pairs[k - 1][0];

        for(int i = k; i < n; i++) {
            if (pq.top() < pairs[i][1]) {
                int top = pq.top();
                pq.pop();
                sum = sum - top + pairs[i][1];
                pq.push(pairs[i][1]);
            }

            ans = max(ans, sum * pairs[i][0]);
        }

        return ans;
    }
};
