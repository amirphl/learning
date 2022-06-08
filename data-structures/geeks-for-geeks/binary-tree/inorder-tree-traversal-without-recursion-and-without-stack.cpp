// https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/

#include<bits/stdc++.h>
#include<iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* p;
    short s;

    Node(int d) {
        data = d;
        s = 0;
        left = right = p = NULL;
    }
};


// time: O(n), memory: O(1)
void inorder(Node* root) {
    Node* u = root;

    while(u) {
        if (u -> left) {
            if (u -> s == 0) {
                u -> s = 1;
                u = u -> left;
            } else if (u -> s == 1) {
                std::cout << u -> data << " ";
                u -> s = 2;

                if (u -> right) {
                    u = u -> right;
                } else {
                    u = u -> p;
                }
            } else {
                u = u -> p;
            }
        } else if (u -> right) {
            if (u -> s == 0) {
                std::cout << u -> data << " ";
                u -> s = 2;
                u = u -> right;
            } else if (u -> s == 1) {
                std::cout << u -> data << " ";
                u -> s = 2;
                u = u -> right;
            } else {
                u = u -> p;
            }
        } else {
            std::cout << u -> data << " ";
            u -> s = 2;
            u = u -> p;
        }
    }
}

void inorder_recur(Node* root) {
    if (root) {
        if (root -> left)
            inorder_recur(root -> left);
        std::cout << root -> data << " ";
        if (root -> right)
            inorder_recur(root -> right);
    }
}

int main() {
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> left -> p = root;
    root -> left -> left = new Node(4);
    root -> left -> left -> p = root -> left;
    root -> left -> right = new Node(5);
    root -> left -> right -> p = root -> left;
    root -> left -> right -> left = new Node(8);
    root -> left -> right -> left -> p = root -> left -> right;
    root -> left -> right -> left -> left = new Node(9);
    root -> left -> right -> left -> left -> p = root -> left -> right -> left;
    root -> left -> right -> left -> right = new Node(10);
    root -> left -> right -> left -> right -> p= root -> left -> right -> left;
    root -> right = new Node(3);
    root -> right -> p = root;
    root -> right -> left = new Node(6);
    root -> right -> left -> p = root -> right;
    root -> right -> left -> right = new Node(3);
    root -> right -> left -> right -> p = root -> right -> left;
    root -> right -> right = new Node(7);
    root -> right -> right -> p = root -> right;
    root -> right -> right -> right = new Node(11);
    root -> right -> right -> right -> p = root -> right -> right;
    root -> right -> right -> right -> left = new Node(12);
    root -> right -> right -> right -> left -> p = root -> right -> right -> right;

    std::cout << "recursive: \n";
    inorder(root);
    std::cout << std::endl;
    std::cout << "no recursive, no stack: \n";
    inorder_recur(root);

    return 0;
}
