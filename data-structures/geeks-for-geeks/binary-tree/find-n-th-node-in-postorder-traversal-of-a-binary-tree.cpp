// https://www.geeksforgeeks.org/find-n-th-node-in-postorder-traversal-of-a-binary-tree/

#include<bits/stdc++.h>
#include<iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

// time: O(n), memory: O(h)
int find(Node* root, int n) {
    if (root == NULL)
        return 0;

    int s1 = find(root -> left, n);

    if (s1 == INT_MIN)
        return s1;

    int s2 = find(root -> right, n - s1);

    if (s2 == INT_MIN)
        return s2;

    if (s1 + s2 + 1 == n) {
        std::cout << root -> data << " ";
        return INT_MIN;
    }

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

    for(int i = 1; i <= 13; i++)
        find(root, i);

    std::cout << std::endl;

    std::cout << find(root, 0) << std::endl;
    std::cout << find(root, 14) << std::endl;

    return 0;
}
