// https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
      public:
	bool checkPowersOfThree(int n)
	{
		int m = log2(n) / log2(3);
		int arr[m + 1];
		arr[0] = 1;
		for (int i = 1; i < m + 1; i++) {
			arr[i] = arr[i - 1] * 3;
		}
		unordered_map<uint64_t, bool> dp;
		return rec(n, m, dp, arr);
	}

	uint64_t to(int n, int m)
	{
		uint64_t res = n;
		res = res << 32;
		res += m;
		return res;
	}
	bool rec(int n, int m, unordered_map<uint64_t, bool> visited, int arr[])
	{
		const uint64_t p = to(n, m);
		if (n <= 1) {
			return visited[p] = 1;
		}
		if (visited.find(p) != visited.end()) {
			return visited[p];
		}
		int rem;
		for (int i = 1; i < m + 1; i++) {
			rem = n - arr[i];
			if (rem < 0) {
				break;
			}
			if (rec(rem, i - 1, visited, arr)) {
				return visited[p] = 1;
			}
		}
		return visited[p] = 0;
	}
};

int main()
{
	int n = 10000000;
	Solution sol;
	cout << sol.checkPowersOfThree(n) << endl;
	return 0;
}
