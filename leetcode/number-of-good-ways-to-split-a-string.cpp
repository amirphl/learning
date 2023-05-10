// https://leetcode.com/problems/number-of-good-ways-to-split-a-string/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
      public:
	int numSplits(string s)
	{
		int n = s.length();

		if (n == 1) {
			return 0;
		}

		int ua = 1;
		int ub = 0;
		int res = 0;
		int a[26];
		int b[26];
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));

		a[s[0] - 'a']++;
		for (int i = 1; i < n; i++) {
			if (b[s[i] - 'a'] == 0) {
				ub++;
			}
			b[s[i] - 'a']++;
		}

		for (int i = 1; i < n; i++) {
			if (ua == ub) {
				res++;
			}
			if (a[s[i] - 'a'] == 0) {
				ua++;
			}
			a[s[i] - 'a']++;
			if (b[s[i] - 'a'] == 1) {
				ub--;
			}
			b[s[i] - 'a']--;
		}
		return res;
	}
};

int main()
{
	Solution sol;
	return 0;
}
