// https://www.geeksforgeeks.org/modify-binary-tree-get-preorder-traversal-using-right-pointers/

#include<algorithm>
#include<iostream>

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

// time: O(n*n)?, memory: O(n)
void modify(struct Node* root) {
    if (!root)
        return;

    modify(root -> left);
    modify(root -> right);
    Node* t = root -> left;

    if (t) {
        while(t -> right) {
            t = t -> right;
        }
        t -> right = root -> right;
        root -> right = root -> left;
    }
}

void printpre(struct Node* root) {
    while (root != NULL) {
        std::cout << root->data << " ";
        root = root->right;
    }
}

int main() {
    struct Node* root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);

    modify(root);
    printpre(root);
    return 0;
}
