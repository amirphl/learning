// https://leetcode.com/problems/multiply-strings/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
      public:
	string multiply(string num1, string num2)
	{
		vector<int> v(max(num1.size(), num2.size()), 0);
		int counter = 0;
		int carry = 0;
		int curr;

		for (auto it = num1.rbegin(); it != num1.rend();
		     it++, counter++) {
			carry = 0;
			curr = counter;
			for (auto it2 = num2.rbegin(); it2 != num2.rend();
			     it2++, curr++) {
				int p = (*it - '0') * (*it2 - '0') + carry;

				if (curr < v.size()) {
					p += v[curr];
				}

				int q = p % 10;

				if (curr < v.size()) {
					v[curr] = q;
				} else {
					v.push_back(q);
				}

				carry = p / 10;
			}

			if (carry != 0) {
				if (curr < v.size()) {
					v[curr] += carry;
				} else {
					v.push_back(carry);
				}
			}

			// cout << *it << " ";
		}

		string res(v.size(), ' ');
		int i = v.size() - 1;

		for (auto &x : v) {
			res[i] = x + '0';
			i--;
		}

		for(int i = 0; i < res.length(); i++) {
			if (res[i] != '0') {
				return res.substr(i, res.size() - i);
			}
		}

		return "0";
	}
};

int main()
{
	Solution sol;
	cout << sol.multiply("28734864374", "38473") << endl;
	cout << sol.multiply("999", "123456") << endl;
	cout << sol.multiply("9", "123456") << endl;
	cout << sol.multiply("38742937", "123") << endl;
	cout << sol.multiply("38742937", "38742937") << endl;
	cout << sol.multiply("9133", "0") << endl;

	return 0;
}
