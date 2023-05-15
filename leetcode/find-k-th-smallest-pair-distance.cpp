// https://leetcode.com/problems/find-k-th-smallest-pair-distance/

#include "bits/stdc++.h"

using namespace std;

class Solution
{
      public:
	// TLE
	int smallestDistancePair(vector<int> &nums, int k)
	{
		priority_queue<int> pq;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (pq.size() < k) {
					pq.push(abs(nums[i] - nums[j]));
				} else {
					int a = pq.top();
					int b = abs(nums[i] - nums[j]);
					if (b < a) {
						pq.pop();
						pq.push(b);
					}
				}
			}
		}
		return pq.top();
	}
};
