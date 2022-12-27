// https://leetcode.com/problems/delete-and-earn/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int freq[nums.size()];
        int k = 0;

        for(int i = 0; i < nums.size();) {
            int j = i, f = 0;
            for(; j < nums.size() && nums[j] == nums[i]; j++) {
                f++;
            }
            nums[k] = nums[i];
            freq[k] = f;
            k++;
            i = j;
        }

        if (k == 1) {
            return nums[0] * freq[0];
        }

        int prev_prev = nums[0] * freq[0];
        int curr, prev;

        if (nums[1] - nums[0] == 1) {
            prev = max(nums[1] * freq[1], prev_prev);
        } else {
            prev = prev_prev + nums[1] * freq[1];
        }

        for(int i = 2; i < k; i++) {
            if (nums[i] - nums[i - 1] == 1) {
                curr = max(prev_prev + nums[i] * freq[i], prev);
            } else {
                curr = prev + nums[i] * freq[i];
            }

            prev_prev = prev;
            prev = curr;
        }

        return prev;
    }

    // greedy doesn't work for [1,1,1,2,4,5,5,5,6]
    int deleteAndEarn2(vector<int>& nums) {
        map<int, int> s;

        for(int& x: nums) {
            s[x]++;
        }

        int count_1 = 0;
        int skip_1 = INT_MAX;

        for(auto it = s.rbegin(); it != s.rend(); it++) {
            if (it -> first != skip_1) {
                count_1 += (it -> first) * (it -> second);
                skip_1 = it -> first - 1;
            }
        }

        int count_2 = 0;
        auto it2 = s.rbegin();
        int skip_2 = it2 -> first;

        for(auto it = s.rbegin(); it != s.rend(); it++) {
            if (it -> first != skip_2) {
                count_2 += (it -> first) * (it -> second);
                skip_2 = it -> first - 1;
            }
        }
        return max(count_1, count_2);
    }
};
