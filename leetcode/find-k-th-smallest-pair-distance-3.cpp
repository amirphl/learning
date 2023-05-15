// https://leetcode.com/problems/find-k-th-smallest-pair-distance/

#include "bits/stdc++.h"

using namespace std;
class Solution
{
      public:
	int smallestDistancePair(vector<int> &nums, int k)
	{
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int left = 0, right = nums[n - 1] - nums[0];
		while (left < right) {
			int mid = (left + right) >> 1;
			int c = 0;
			for (int j = 0, i = 0; i < n; i++) {
				while (j < n && nums[j] - nums[i] <= mid) {
					j++;
				}
				c += j - i - 1;
			}
			if (c < k) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		return left;
	}
};

