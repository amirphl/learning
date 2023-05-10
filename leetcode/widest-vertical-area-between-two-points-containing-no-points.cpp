// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
      public:
	int maxWidthOfVerticalArea(vector<vector<int>> &points)
	{
		sort(points.begin(), points.end());
		int res = 0;
		int n = points.size();
		for (int i = 1; i < n; i++) {
			res = max(res, points[i][0] - points[i - 1][0]);
		}
		return res;
	}
};

int main()
{
	Solution sol;
	return 0;
}
