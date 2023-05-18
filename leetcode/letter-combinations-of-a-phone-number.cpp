// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include "bits/stdc++.h"

using namespace std;

class Solution
{
      public:
	vector<string> letterCombinations(string digits)
	{
		if (digits.length() == 0) {
			return {};
		}
		vector<string> res;
		string s(digits.size(), ' ');
		rec(digits, 0, s, res);
		return res;
	}

	void rec(string &digites, int i, string &s, vector<string> &res)
	{
		if (i == digites.length()) {
			res.push_back(s);
			return;
		}
		char ch = digites[i];
		char next = (ch - '2') * 3 + 'a';
		if (ch == '8') {
			next = 't';
		}
		if (ch == '9') {
			next = 'w';
		}
		s[i] = next;
		rec(digites, i + 1, s, res);
		s[i] = next + 1;
		rec(digites, i + 1, s, res);
		s[i] = next + 2;
		rec(digites, i + 1, s, res);
		if (ch == '7') {
			s[i] = 's';
			rec(digites, i + 1, s, res);
		}
		if (ch == '9') {
			s[i] = 'z';
			rec(digites, i + 1, s, res);
		}
	}
};
