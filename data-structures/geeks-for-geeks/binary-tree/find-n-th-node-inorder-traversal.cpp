// https://www.geeksforgeeks.org/find-n-th-node-inorder-traversal/

#include<bits/stdc++.h>
#include<iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int left_size;
    int right_size;

    Node(int d) {
        data = d;
        left = right = NULL;
        left_size = right_size = 0;
    }
};

void fill_size(Node* root) {
    if (root == NULL)
        return;

    fill_size(root -> left);
    fill_size(root -> right);

    if (root -> left)
        root -> left_size = root -> left -> left_size + root -> left -> right_size + 1;

    if (root -> right)
        root -> right_size = root -> right -> left_size + root -> right -> right_size + 1;

    // std::cout << root -> data << ":" << root -> left_size + root -> right_size + 1 << std::endl;
}

// inefficient approach
int find(Node* root, int n) {
    if (root == NULL)
        return INT_MIN;

    if (root -> left_size < n) {
        if (root -> left_size + 1 == n) {
            return root -> data;
        }
        return find(root -> right, n - 1 - root -> left_size);
    } else {
        return find(root -> left, n);
    }
}

// time: O(n), memory: O(h)
int find_2(Node* root, int n) {
    if (root == NULL)
        return 0;

    int s1 = find_2(root -> left, n);

    if (s1 == INT_MIN)
        return s1;

    if (s1 + 1 == n) {
        std::cout << root -> data << " ";
        return INT_MIN;
    }

    int s2 = find_2(root -> right, n - 1 - s1);

    if (s2 == INT_MIN)
        return s2;

    return s1 + s2 + 1;
}

int main() {
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> left -> right -> left = new Node(8);
    root -> left -> right -> left -> left = new Node(9);
    root -> left -> right -> left -> right = new Node(10);
    root -> right = new Node(3);
    root -> right -> left = new Node(6);
    root -> right -> left -> right = new Node(3);
    root -> right -> right = new Node(7);
    root -> right -> right -> right = new Node(11);
    root -> right -> right -> right -> left = new Node(12);

    // fill_size(root);
    // for(int i = 1; i <= 13; i++)
    // std::cout << i << " " << find(root, i) << std::endl;

    for(int i = 1; i <= 13; i++)
        find_2(root, i);

    return 0;
}
