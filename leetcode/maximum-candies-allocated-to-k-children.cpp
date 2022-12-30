// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1;
        int high = *max_element(candies.begin(), candies.end());
        int res = rec(candies, k, low, high);

        return  res == INT_MIN ? 0 : res;
    }

    bool check(vector<int>& candies, long long k, int div) {
        long long count = 0;

        for(int j = 0; j < candies.size(); j++) {
            count += candies[j] / div;

            if (count >= k) {
                return true;
            }
        }

        return false;
    }

    int rec(vector<int>& candies, long long k, int low, int high) {
        if (low == high) {
            return check(candies, k, low) ? low : INT_MIN;
        }

        if (low + 1 == high) {
            if (check(candies, k, high)) {
                return high;
            } else if (check(candies, k, low)) {
                return low;
            } else {
                return INT_MIN;
            }
        }

        int mid = (low + high) >> 1;

        bool possible = check(candies, k, mid);

        if (possible) {
            return rec(candies, k, mid, high);
        } else {
            return rec(candies, k, low, mid);
        }
    }
};
