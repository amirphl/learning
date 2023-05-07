// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr)
	{
	}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr)
	{
	}
	TreeNode(int x, TreeNode *left, TreeNode *right)
	    : val(x), left(left), right(right)
	{
	}
};

class Solution
{
      public:
	int sumEvenGrandparent(TreeNode *root)
	{
		int val = 0;
		rec(-1, -1, root, val);

		return val;
	}
	void rec(int g, int p, TreeNode *root, int &val)
	{
		if (!root) {
			return;
		}

		if (g % 2 == 0) {
			val += root->val;
		}

		rec(p, root->val, root->left, val);
		rec(p, root->val, root->right, val);
	}
};

int main()
{
	Solution sol;
	return 0;
}
