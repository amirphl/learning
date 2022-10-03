// https://www.geeksforgeeks.org/modify-binary-tree-get-preorder-traversal-using-right-pointers/

#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = new struct Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

void preorder(struct Node* root) {
    stack<Node*> s;
    Node* prv = 0;
    Node* curr = root;
    while(curr) {
        cout << curr -> data << " ";
        if (curr -> right) {
            s.push(curr -> right);
        }
        if (curr -> left) {
            curr = curr -> left;
        } else {
            if (!s.empty()) {
                curr = s.top();
                s.pop();
            } else {
                break;
            }
        }
    }
    cout << endl;
}

void modify(struct Node* root) {
    stack<Node*> s;
    Node* prv = 0;
    Node* curr = root;
    while(curr) {
        if (prv) {
            prv -> right = curr;
        }
        prv = curr;
        if (curr -> right) {
            s.push(curr -> right);
        }
        if (curr -> left) {
            curr = curr -> left;
        } else {
            if (!s.empty()) {
                curr = s.top();
                s.pop();
            } else {
                break;
            }
        }
    }
}

void printpre(struct Node* root) {
    while (root != NULL) {
        std::cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    /*
    struct Node* root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    */
    struct Node *root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    root -> right -> left = newNode(6);
    root -> right -> right = newNode(7);
    root -> left -> left -> left = newNode(8);
    root -> left -> left -> right = newNode(9);
    root -> left -> left -> right -> left = newNode(16);
    root -> left -> left -> right -> left -> left = newNode(-4);
    root -> left -> left -> right -> left -> right = newNode(99);
    root -> left -> right -> left = newNode(3);
    root -> left -> right -> right = newNode(1);
    root -> left -> right -> right -> left = newNode(17);
    root -> left -> right -> right -> left -> right = newNode(0);
    root -> left -> right -> right -> right = newNode(18);
    root -> left -> right -> right -> right -> left = newNode(21);
    root -> right -> left -> left = newNode(4);
    root -> right -> left -> right = newNode(2);
    root -> right -> left -> right -> right = newNode(19);
    root -> right -> left -> right -> right -> right = newNode(9);
    root -> right -> right -> left = newNode(7);
    root -> right -> right -> right = newNode(2);
    preorder(root);
    modify(root);
    printpre(root);
    return 0;
}
