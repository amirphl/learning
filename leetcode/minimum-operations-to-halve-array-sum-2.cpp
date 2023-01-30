// https://leetcode.com/problems/minimum-operations-to-halve-array-sum/

class Solution {
public:
    int halveArray(vector<int>& nums) {
        double total = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            total += nums[i];
        }

        priority_queue<double> q(nums.begin(), nums.end());
        double reduced = 0;
        int opt = 0;

        while(!q.empty() && reduced < total / 2) {
            double top = q.top();
            q.pop();
            reduced += top / 2;
            q.push(top / 2);
            opt++;
        }

        return opt;
    }
};
