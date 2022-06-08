// https://www.geeksforgeeks.org/full-and-complete-binary-tree-from-given-preorder-and-postorder-traversals/

#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = right = 0;
    }
};

// time: O(n), memory: O(h)
Node* cons(int pre[], int post[], int low, int high, int left, int right, unordered_map<int, int> &m) {
    if (low > high)
        return 0;

    Node* new_node = new Node(pre[low]);

    if (low == high) {
        return new_node;
    }

    int left_child_index = m[pre[low + 1]];

    new_node -> left = cons(pre, post, low + 1, low + 1 + left_child_index - left, left, left_child_index, m);
    new_node -> right = cons(pre, post, low + 1 + left_child_index - left + 1, high, left_child_index + 1, right - 1, m);

    return new_node;
}

void inorder(Node* root) {
    if (root) {
        std::cout << root -> data << " ";
        inorder(root -> left);
        inorder(root -> right);
    }
}

int main() {
    int pre[] = {1, 2, 4, 5, 8, 9, 12, 14, 15, 13, 3, 6, 7, 10, 11};
    int post[] = {4, 8, 14, 15, 12, 13, 9, 5, 2, 6, 10, 11, 3,1};
    int n = sizeof(pre) / sizeof(pre[0]);

    unordered_map<int, int> m;

    for(int i = 0; i < n; i++)
        m[post[i]] = i;

    Node* root = cons(pre, post, 0, n - 1, 0, n - 1, m);
    inorder(root);

    return 0;
}
