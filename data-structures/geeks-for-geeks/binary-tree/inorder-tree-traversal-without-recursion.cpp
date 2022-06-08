// https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/

// other approache: using two while loops: time: O(n), memory: O(n)

#include<bits/stdc++.h>
#include<iostream>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node (int data) {
        this -> data = data;
        left = right = NULL;
    }
};

// iterative version
// time: O(n), memory: O(n)
void inorder(struct Node* root) {
    std::stack<struct Node*> s;
    struct Node* u = new Node(INT_MIN);
    if (root -> right)
        s.push(root -> right);
    s.push(root);
    s.push(u);
    if (root -> left)
        s.push(root -> left);
    while(!s.empty()) {
        Node* top = s.top();
        s.pop();
        if (top == u) {
            std::cout << s.top() -> data << " ";
            s.pop();
            continue;
        }
        if (top -> right)
            s.push(top -> right);
        s.push(top);
        s.push(u);
        if (top -> left)
            s.push(top -> left);
    }
}

int main() {
    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(8);
    root->right->right= new Node(0);
    root->left->left->right  = new Node(7);
    root->left->left->right->right  = new Node(8);
    root->left->left->right->left  = new Node(1);
    root->left->left->right->left->right = new Node(2);
    root->left->left->right->right->right = new Node(6);

    inorder(root);
    return 0;
}
