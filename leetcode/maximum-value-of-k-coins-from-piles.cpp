// https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/

struct hashFunction
{
    size_t operator()(const vector<int>
                      &myVector) const
    {
        std::hash<int> hasher;
        size_t answer = 0;

        for (int i : myVector)
        {
            answer ^= hasher(i) + 0x9e3779b9 +
                      (answer << 6) + (answer >> 2);
        }
        return answer;
    }
};

class Solution {
public:
    // Time Limit Exceeded
    int maxValueOfCoins(vector<vector<int>>& piles, int x) {
        int n = piles.size();
        int dp[n][x + 1];
        int i = n - 1;

        while(i >= 0) {
            dp[i][0] = 0;
            int j = 1;

            while(j <= x) {
                dp[i][j] = INT_MIN;
                int k = 0, mid = 0;

                while(k < piles[i].size() && k < j) {
                    mid += piles[i][k];

                    if (i == n - 1) {
                        if (k == j - 1) {
                            dp[i][j] = mid;
                            break;
                        }
                    } else if (dp[i + 1][j - k - 1] != INT_MIN) {
                        dp[i][j] = max(dp[i][j], mid + dp[i + 1][j - k - 1]);
                    }

                    k++;
                }

                if (i < n - 1 && dp[i + 1][j] != INT_MIN) {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j]);
                }

                j++;
            }
            i--;
        }

        // i = 0;
        // while(i < n) {
        //     int j = 0;
        //     while(j <= x) {
        //         cout << dp[i][j] << " ";
        //         j++;
        //     }
        //     cout << endl;
        //     i++;
        // }

        return dp[0][x];
    }



    vector<int> sizes;
    // Time Limit Exceeded
    int maxValueOfCoins2(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        unordered_map<vector<int>, int, hashFunction> v;
        vector<int> state = vector<int>(n + 1, 0);
        state[n] = k;
        sizes = vector<int>(n, 0);
        int i = 0;

        while(i < n) {
            sizes[i] = piles[i].size();
            i++;
        }

        return rec(piles, state, v);
    }

    int rec(vector<vector<int>>& piles, vector<int>& state, unordered_map<vector<int>, int, hashFunction>& v) {
        if (v.find(state) != v.end()) {
            return v[state];
        }

        int n = state.size();

        if (state[n - 1] <= 0) {
            return 0;
        }

        int res = INT_MIN, i = 0;

        while(i < n - 1) {
            if (state[i] < sizes[i]) {
                int b = state[i];
                state[i]++;
                state[n - 1]--;
                res = max(res, piles[i][b] + rec(piles, state, v));
                state[n - 1]++;
                state[i]--;
            }
            i++;
        }

        // int j = 0;
        // while(j < n) {
        //     cout << state[j] << " ";
        //     j++;
        // }
        // cout << res << endl;

        return v[state] = res;
    }
};
