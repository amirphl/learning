// https://leetcode.com/problems/subarray-product-less-than-k/

#include "bits/stdc++.h"

using namespace std;

class Solution
{
      public:
	int numSubarrayProductLessThanK(vector<int> &nums, int k)
	{
		uint64_t mul = 1;
		int n = nums.size();
		int res = 0;
		int j = 0, i = 0;
		for (; i < n && j < n;) {
			if (i == j) {
				if (k <= nums[i]) {
					j++;
				} else {
					mul = nums[j];
				}
				i++;
			} else if (mul * nums[i] < k) {
				mul *= nums[i];
				i++;
			} else {
				// cout << i << " " << j << endl;
				res += i - j;
				mul /= nums[j];
				j++;
			}
		}
		if (i > j) {
			// cout << i << " " << j << endl;
			res += (i - j + 1) * (i - j) / 2;
		}
		return res;
	}
};

