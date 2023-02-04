// https://leetcode.com/problems/construct-target-array-with-multiple-sums/

class Solution {
public:
    bool isPossible(vector<int>& arr) {
        // 9,3,5 ; 1 3 5 : 1 3 1 : 1 1 1
        // 8 5 : 3 5 : 3 2 : 1 2 : 1 1
        // 9000 3 5 : 8992 : 3 5 : 8984 3 5: ... : 0 3 5
        int64_t total = 0;
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            total += arr[i];
        }

        priority_queue<int> pq(arr.begin(), arr.end());

        while(!pq.empty() && pq.top() > 1) {
            int top = pq.top();
            pq.pop();
            int64_t diff = total - top;
            // cout << top << " " << diff << " " << total << endl;

            if (diff < 1 || (top - diff) < 1) {
                return false;
            }

            if (diff == 1) {
                return true;
            }

            top = top % diff;

            if (top == 0) {
                return false;
            }

            total = top + diff;
            pq.push(top);
            // cout << top << " " << diff << " " << total << " __ " << endl;
        }

        return true;
    }
};
