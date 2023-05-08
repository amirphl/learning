// https://leetcode.com/problems/sum-root-to-leaf-numbers/

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
};

class Solution
{
      public:
	int sumNumbers(TreeNode *root)
	{
		int sum = 0;
		rec(root, 0, sum);
		return sum;
	}

	void rec(TreeNode *root, int curr, int &sum)
	{
		if (!root) {
			return;
		}

		int x = curr * 10 + root->val;
		if (!(root->left) && !(root->right))
			sum += x;
		rec(root->left, x, sum);
		rec(root->right, x, sum);
	}
};

int main()
{
	Solution sol;
	return 0;
}
