// https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/

class Solution {
public:

    // This doesn't work!

    const int len = 16;
    int countTriplets(vector<int>& nums) {
        vector<unordered_map<uint16_t, int>> v(len);
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            uint16_t c = (uint16_t) nums[i];
            // cout << nums[i] << " ";
            for(int j = 0; j < len; j++) {
                if ((c & 1) == 0) {
                    // cout << j << " ";
                    v[j][(uint16_t) nums[i]]++;
                }
                c = c >> 1;
            }
            // cout << endl;
        }

        int ans = 0;

        for (auto& it: v[0]) {
            uint16_t a = it -> first;
            int a_freq = it -> second;

            int i = 1;
            for(; i < len && v[i].find(a) != v[i].end(); i++);
            if (i == len) {
                int d = n - a_freq;
                // ans += 3 * (n - 1) * (n - 2);
                continue;
            }

            for(auto& it2: v[i]) {
                uint16_t b = it2 -> first;
                int b_freq = it2 -> second;

                int j = i + 1;
                for(; j < len && v[j].find(second) != v[j].end(); j++);
                if (j == len) {
                    int d = n - freq_a - freq_b;
                    ans += a_freq * b_freq * d * 6;
                    d = a_freq + b_freq - 2;
                    if (d > 0) {
                        ans += a_freq * b_freq * 3;
                    }
                    continue;
                }

                for(auto& it3: v[j]) {
                    uint16_t c = it3 -> first;
                    int c_freq = it3 -> second;

                    int k = j + 1;
                    for(; k < len && v[k].find(c) != v[k].end(); k++);
                    if (k == len) {
                        ans += a_freq * b_freq * c_freq * 6;
                    }
                }
            }
        }

        return ans;
    }
};
