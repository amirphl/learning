// https://leetcode.com/problems/powx-n/

#include "bits/stdc++.h"

using namespace std;

class Solution
{
      public:
	double myPow(double x, int n)
	{
		if (x == 0) {
			return 0;
		}
		if (x == 1) {
			return 1;
		}
		uint64_t u = n;
		if (n < 0) {
			u = -1 * u;
			x = 1 / x;
		}
		if (x == -1) {
			return (u % 2 == 0) ? 1 : -1;
		}
		return rec(x, u);
	}

	double rec(double x, uint64_t n)
	{
		double y = x;
		if (n == 0) {
			return 1;
		}
		if (n == 1) {
			return x;
		}
		if (n == 2) {
			return x * x;
		}
		int i = 0;
		int m = (int)log2(n);

		for (; i < m; i++) {
			x *= x;
		}

		n -= (uint64_t)pow(2, i);
		return x * rec(y, n);
	}
};
