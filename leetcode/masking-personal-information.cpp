// https://leetcode.com/problems/masking-personal-information/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
      public:
	string maskPII(string s)
	{
		string res = "";

		if (s.find('@') != string::npos) {
			int at_index = s.find("@");
			string first_part = s.substr(0, at_index);
			string second_part = s.substr(at_index + 1, s.length());
			res.insert(0, 1, tolower(first_part[0]));

			int last = first_part.length() - 1;
			if (first_part.length() > 1) {
				res.insert(1, 5, '*');
				res.insert(6, 1, tolower(first_part[last]));
			} else {
				res.insert(1, 1, tolower(first_part[last]));
			}

			res += "@";
			transform(second_part.begin(), second_part.end(),
				  second_part.begin(),
				  [](unsigned char c) { return tolower(c); });
			res += second_part;
		} else {
			stack<char> sta;
			for (auto &ch : s) {
				if ('0' <= ch && ch <= '9') {
					sta.push(ch);
				}
			}
			string r(12, ' ');
			for (int i = 11; i >= 0; i--) {
				if (i == 7) {
					r[i] = '-';
					i--;
				}
				if (i == 3) {
					r[i] = '-';
					i--;
				}
				if (i > 7)
					r[i] = sta.top();
				else
					r[i] = '*';
				sta.pop();
			}

			if (!sta.empty()) {
				r.insert(0, 1, '-');

				while (!sta.empty()) {
					r.insert(0, 1, '*');
					sta.pop();
				}

				r.insert(0, 1, '+');
			}

			res = r;
		}

		return res;
	}
};

int main()
{
	vector<string> tests = {"LeetCode@LeetCode.com", "AB@qq.com",
				"1(234)567-890",	 "15(234)567-890",
				"121(234)567-890",	 "1231(234)567-890",
				"a@gmaIIl.com"};
	Solution sol;
	for (auto &t : tests) {

		string res = sol.maskPII(t);
		cout << res << endl;
	}
	return 0;
}
