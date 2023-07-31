// https://www.geeksforgeeks.org/median-of-all-nodes-from-a-given-range-in-a-binary-search-tree-bst/

#include "bits/stdc++.h"
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = right = 0;
  }
};

float inorder_wrapper(struct Node *root, int size) {
  struct Node *curr = root;
  struct Node *prv = 0;
  int count = 0;
  while (curr) {
    if (curr->left) {
      struct Node *r = curr->left;
      while (r->right && r->right != curr) {
        r = r->right;
      }
      if (r->right) {
        r->right = 0;
        count++;
        if (size % 2 == 0 && count == (size / 2) + 1) {
          // cout << curr -> data << " " << prv -> data << endl;
          return (curr->data + prv->data) / 2.0;
        }
        if (size % 2 == 1 && count == (size / 2) + 1) {
          return curr->data;
        }
        prv = curr;
        curr = curr->right;
      } else {
        r->right = curr;
        curr = curr->left;
      }
    } else {
      count++;
      if (size % 2 == 0 && count == (size / 2) + 1) {
        return (curr->data + prv->data) / 2.0;
      }
      if (size % 2 == 1 && count == (size / 2) + 1) {
        return curr->data;
      }
      prv = curr;
      curr = curr->right;
    }
  }
  return count;
}

// your task is to complete the Function
// Function should return median of the BST
float findMedian(struct Node *root) {
  int size = (int)inorder_wrapper(root, INT_MIN);
  return inorder_wrapper(root, size);
}

int main() { return 0; }
