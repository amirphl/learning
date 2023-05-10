// https://leetcode.com/problems/number-of-substrings-with-only-1s/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
      public:
	int mod = (1e9 + 7);
	int numSub(string s)
	{
		int n = s.length();
		int dp[n];
		dp[0] = 1;
		int res = 0;
		int last_1 = -1;
		for (int i = 0; i < n; i++) {
			if (i < n - 1)
				dp[i + 1] = (dp[i] + i + 2) % mod;
			if (s[i] == '0') {
				if (i != 0 && s[i - 1] == '1') {
					int j = i - last_1 - 1;
					res = (res + dp[j]) % mod;
					last_1 = -1;
				}
			} else {
				if (last_1 == -1) {
					last_1 = i;
				}
			}
		}
		if (s[n - 1] == '1') {
			int j = n - last_1 - 1;
			res = (res + dp[j]) % mod;
		}
		return res;
	}
};

int main()
{
	Solution sol;
	return 0;
}
