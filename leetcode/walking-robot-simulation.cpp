// https://leetcode.com/problems/walking-robot-simulation/

#include "bits/stdc++.h";

using namespace std;

class Solution
{
      public:
	uint64_t point(int x, int y)
	{
		uint64_t p = x;
		p = p << 32;
		p += y;
		return p;
	}
	int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
	{
		unordered_set<uint64_t> s;
		for (auto &obs : obstacles) {
			s.insert(point(obs[0], obs[1]));
		}
		uint64_t p;
		int res = 0;
		int x = 0, y = 0, dir = 0;
		for (auto &c : commands) {
			if (c == -1) {
				dir = (dir + 1) % 4;
			} else if (c == -2) {
				dir = (dir - 1 + 4) % 4;
			} else {
				int k = c;
				for (int i = 0; i < k; i++) {
					if (dir == 0) { // north
						p = point(x, y + 1);
						if (s.find(p) == s.end()) {
							y++;
						} else {
							break;
						}
					} else if (dir == 1) { // east
						p = point(x + 1, y);
						if (s.find(p) == s.end()) {
							x++;
						} else {
							break;
						}
					} else if (dir == 2) { // south
						p = point(x, y - 1);
						if (s.find(p) == s.end()) {
							y--;
						} else {
							break;
						}
					} else { // west
						p = point(x - 1, y);
						if (s.find(p) == s.end()) {
							x--;
						} else {
							break;
						}
					}
					res = max(res, x * x + y * y);
				}
			}
		}
		return res;
	}
};
