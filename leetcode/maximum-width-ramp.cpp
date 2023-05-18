// https://leetcode.com/problems/maximum-width-ramp/

#include "bits/stdc++.h"

using namespace std;

class Solution
{
      public:
	// TLE
	int maxWidthRamp(vector<int> &nums)
	{
		int rs = 0;
		int n = nums.size();
		int till[n];
		till[0] = nums[0];
		for (int k = 1; k < n; k++) {
			till[k] = min({till[k - 1], nums[k]});
		}
		int j = 0, i = 0;
		while (j < n) {
			while (i < n) {
				if (nums[i] >= nums[j]) {
					rs = i - j;
				}
				i++;
			}
			j++;
			while (j < n && till[j - 1] <= nums[j]) {
				j++;
			}
			i = j + rs;
		}
		return rs;
	}
};
