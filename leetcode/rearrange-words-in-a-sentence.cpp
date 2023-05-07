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

		text[0] = tolower(text[0]);

		stringstream ss(text);
		istream_iterator<string> begin(ss);
		istream_iterator<string> end;
		vector<pair<int, string>> vstrings;
		int c = 0;
		for (auto it = begin; it != end; it++, c++) {
			vstrings.push_back({c, *it});
		}

		sort(
		    vstrings.begin(), vstrings.end(),
		    [](const pair<int, string> &a, const pair<int, string> &b) {
			    if (a.second.length() == b.second.length()) {
				    return a.first < b.first;
			    }

			    return a.second.length() < b.second.length();
		    });

		/*
		string joined_string = boost::algorithm::join(vstrings, " ");
		joined_string[0] = toupper(joined_string[0]);

		return joined_string;
		*/
		/*
		ostringstream imploded;
		copy(vstrings.begin(), vstrings.end(),  )
		copy(vstrings.begin(), vstrings.end(),
		     ostream_iterator<string>(imploded, " "));

		string joined_string = imploded.str();
		joined_string[0] = toupper(joined_string[0]);
		joined_string.pop_back();
		*/

		string joined_string;

		for (auto &p : vstrings) {
			joined_string += p.second + " ";
		}

		joined_string[0] = toupper(joined_string[0]);
		joined_string.pop_back();

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
