// https://leetcode.com/problems/binary-subarrays-with-sum/

#include "bits/stdc++.h"

using namespace std;

class Solution
{
      public:
	int numSubarraysWithSum(vector<int> &nums, int goal)
	{
		int n = nums.size();
		if (n == 1) {
			if (goal == 0) {
				return (nums[0] == 0) ? 1 : 0;
			}
			if (goal == 1) {
				return (nums[0] == 1) ? 1 : 0;
			}
			return 0;
		}

		int res = 0, sum = 0;
		if (goal == 0) {
			int j = -1;
			for (int i = 0; i < n; i++) {
				if (nums[i] == 0) {
					if (j == -1) {
						j = i;
					}
				} else if (j != -1) {
					sum = i - j;
					res += sum * (sum + 1) / 2;
					j = -1;
				}
			}
			if (j != -1) {
				sum = n - j;
				res += sum * (sum + 1) / 2;
			}
			return res;
		}

		int curr = nums[0], next = nums[1];
		nums[0] = nums[1] = 0;
		for (int i = 0; i < n - 2; i++) {
			sum += curr;
			nums[sum]++;
			if (sum >= goal) {
				res += nums[sum - goal];
				if (sum == goal) {
					res++;
				}
			}
			curr = next;
			next = nums[i + 2];
			nums[i + 2] = 0;
		}

		// ----- n - 2
		sum += curr;
		nums[sum]++;
		if (sum >= goal) {
			res += nums[sum - goal];
			if (sum == goal) {
				res++;
			}
		}
		curr = next;

		// ----- n - 1
		sum += curr;
		if (sum < n) {
			nums[sum]++;
		}
		if (sum >= goal) {
			res += nums[sum - goal];
			if (sum == goal) {
				res++;
			}
		}

		return res;
	}
};
