// https://leetcode.com/problems/rearrange-words-in-a-sentence/

#include <bits/stdc++.h>
#include <boost/algorithm/string/join.hpp>

using namespace std;

class Solution
{
      public:
	string arrangeWords(string text)
	{
		if (text.length() == 0) {
			return text;
		}

		int n = text.size();
		text[0] = tolower(text[0]);
		int words = 1;

		for (auto &ch : text) {
			if (ch == ' ') {
				words++;
			}
		}

		vector<vector<int>> vstrings(words);
		int i = 0, j = 0, c = 0;

		for (; i < n; i++) {
			if (text[i] == ' ') {
				vstrings[c] = {j, i - 1, c};
				c++;
				j = i + 1;
			}
		}

		vstrings[c] = {j, i - 1, c};

		sort(vstrings.begin(), vstrings.end(),
		     [](const vector<int> &a, const vector<int> &b) {
			     if (a[1] - a[0] == b[1] - b[0]) {
				     return a[2] < b[2];
			     }

			     return a[1] - a[0] < b[1] - b[0];
		     });

		string joined_string(n, ' ');
		i = 0;
		for (auto &x : vstrings) {
			copy(text.begin() + x[0], text.begin() + x[1] + 1,
			     joined_string.begin() + i);
			i += x[1] - x[0] + 2;
		}

		joined_string[0] = toupper(joined_string[0]);

		return joined_string;
	}
};

int main()
{
	Solution sol;
	cout << sol.arrangeWords("Keep calm and code on") << endl;
	cout << sol.arrangeWords("To be or not to be") << endl;

	return 0;
}
