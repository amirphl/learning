// https://leetcode.com/problems/find-k-th-smallest-pair-distance/

#include "bits/stdc++.h"

using namespace std;

class Solution
{
      public:
	// TLE
	int smallestDistancePair(vector<int> &nums, int k)
	{
		int m = 1000000 + 1;
		int diff[m];
		memset(diff, 0, sizeof(diff));
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				diff[abs(nums[i] - nums[j])]++;
			}
		}
		int i = 0;
		for(; i < m; i++) {
			if (diff[i] != 0) {
				k -= diff[i];
			}
			if (k < 1) {
				break;
			}
		}
		return i;
	}
};
