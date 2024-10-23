// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> v(1e5);
const int sep = 1001;

class Codec {
public:
  string serialize(TreeNode *root) {
    std::ostringstream oss;
    int pos{0};
    fn(root, oss, pos);

    return oss.str();
  }

  void deserializeVector(const string &str) {
    istringstream iss(str);
    string token;

    int i{0};
    while (std::getline(iss, token, ',')) {
      v[i++] = std::stoi(token);
    }
  }

  void fn(TreeNode *root, std::ostringstream &oss, int &pos) {
    if (!root) {
      oss << sep << ",";
      ++pos;
      return;
    }

    oss << root->val << ",";
    ++pos;
    fn(root->left, oss, pos);
    fn(root->right, oss, pos);
  }

  TreeNode *deserialize(string &data) {
    deserializeVector(data);
    int i{0};

    return gn(i);
  }

  TreeNode *gn(int &i) {
    if (v[i] == sep) {
      ++i;
      return nullptr;
    }

    TreeNode *root = new TreeNode(v[i++]);
    root->left = gn(i);
    root->right = gn(i);

    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
