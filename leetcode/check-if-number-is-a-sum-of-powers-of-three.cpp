// https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
      public:
	// TLE
	bool checkPowersOfThree(int n)
	{
		int m = log2(n) / log2(3);
		int arr[m + 1];
		arr[0] = 1;
		for (int i = 1; i < m + 1; i++) {
			arr[i] = arr[i - 1] * 3;
		}
		auto dp = new bool[n + 1][15];
		memset(dp, 0, sizeof(dp));
		for (int j = 0; j < m + 1; j++) {
			dp[0][j] = 1;
		}
		for (int i = 1; i < n + 1; i++) {
			for (int j = 0; j < m + 1; j++) {
				int rem = i - arr[j];
				if (rem < 0) {
					dp[i][j] = dp[i][j - 1];
					continue;
				}
				if (rem == 0) {
					dp[i][j] = 1;
					continue;
				}
				for (int k = 0; k < j; k++) {
					if (rem - arr[k] < 0) {
						break;
					}
					if (dp[rem][k]) {
						dp[i][j] = 1;
						break;
					}
				}
			}
		}
		return dp[n][m];
	}
};

int main()
{
	int n = 10000000;
	Solution sol;
	cout << sol.checkPowersOfThree(n) << endl;
	return 0;
}
