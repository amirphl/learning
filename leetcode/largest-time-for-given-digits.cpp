// https://leetcode.com/problems/largest-time-for-given-digits/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
      public:
	short v[4];
	short gen[24][4];
	int c = 0;
	string res = "  :  ";

	bool is_valid(int i)
	{
		int a = gen[i][0] * 10 + gen[i][1];
		int b = gen[i][2] * 10 + gen[i][3];
		return a < 24 && b < 60;
	}

	bool less_than(int i)
	{
		int a = gen[i][0] * 10 + gen[i][1];
		int b = gen[i][2] * 10 + gen[i][3];
		int c = (res[0] - '0') * 10 + (res[1] - '0');
		int d = (res[3] - '0') * 10 + (res[4] - '0');
		return a * 60 + b > c * 60 + d;
	}

	string largestTimeFromDigits(vector<int> &arr)
	{
		rec(arr, 0);
		// print();
		for (int i = 0; i < c; i++) {
			if (is_valid(i) && (res == "  :  " || less_than(i))) {
				for (int j = 0; j < 2; j++) {
					res[j] = gen[i][j] + '0';
				}
				for (int j = 2; j < 4; j++) {
					res[j + 1] = gen[i][j] + '0';
				}
			}
		}
		if (res == "  :  ") {
			res = "";
		}
		return res;
	}

	void rec(vector<int> &arr, int i)
	{
		if (i == 4) {
			for (int j = 0; j < 4; j++) {
				gen[c][j] = v[j];
			}
			c++;
			return;
		}
		for (int j = 0; j < 4; j++) {
			if (arr[j] == -1) {
				continue;
			}
			int backup = arr[j];
			v[i] = arr[j];
			arr[j] = -1;
			rec(arr, i + 1);
			arr[j] = backup;
		}
	}

	void print()
	{
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < 4; j++) {
				cout << gen[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	Solution sol;
	vector<int> in{0, 5, 9, 7};
	sol.largestTimeFromDigits(in);
	return 0;
}

