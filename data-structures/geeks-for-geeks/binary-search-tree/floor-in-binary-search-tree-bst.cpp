// https://www.geeksforgeeks.org/floor-in-binary-search-tree-bst/#practice
#include "bits/stdc++.h"
using namespace std;

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node *right;
  Node *left;

  Node(int x) {
    data = x;
    right = NULL;
    left = NULL;
  }
};

int floor(Node *root, int x);

Node *insert(Node *tree, int val) {
  Node *temp = NULL;
  if (tree == NULL)
    return new Node(val);

  if (val < tree->data) {
    tree->left = insert(tree->left, val);
  } else if (val > tree->data) {
    tree->right = insert(tree->right, val);
  }

  return tree;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    Node *root = NULL;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
      int k;
      cin >> k;
      root = insert(root, k);
    }

    int s;
    cin >> s;

    cout << floor(root, s) << "\n";
  }
}

// } Driver Code Ends

// Function to search a node in BST.

int floor_rec(Node *root, int x) {
  if (!root) {
    return INT_MIN;
  }
  int data = root->data;
  if (data == x) {
    return x;
  }
  if (data > x) {
    return floor_rec(root->left, x);
  } else {
    int y = floor_rec(root->right, x);
    return max(data, y);
  }
}

int floor(Node *root, int x) {
  int f = floor_rec(root, x);
  if (f == INT_MIN) {
    return -1;
  }
  return f;
}
