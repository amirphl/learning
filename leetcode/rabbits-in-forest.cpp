// https://leetcode.com/problems/rabbits-in-forest/

#include "bits/stdc++.h"

using namespace std;

class Solution
{
      public:
	int numRabbits(vector<int> &answers)
	{
		int c = 0;
		unordered_map<int, int> s;
		for (auto &x : answers) {
			if (x == 0) {
				c++;
			} else if (s.find(x) == s.end()) {
				s[x] = x;
			} else {
				if (s[x] == 0) {
					c += x + 1;
					s[x] = x;
				} else {
					s[x]--;
				}
			}
		}
		for (auto &it : s) {
			c += it.first + 1;
		}
		return c;
	}
};
