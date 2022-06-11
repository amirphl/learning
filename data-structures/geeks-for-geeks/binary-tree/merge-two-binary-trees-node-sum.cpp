// https://www.geeksforgeeks.org/merge-two-binary-trees-node-sum/

#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    int data;
    Node(int d) {
        data = d;
        left = 0;
        right = 0;
    }
};

// time: O(n), memory: O(h)
void join(Node* u, Node* v) {
    u -> data += v -> data;
    if (u -> left && v -> left) {
        join(u -> left, v -> left);
    } else if (u -> left == 0 && v -> left) {
        u -> left = v -> left;
    }
    if (u -> right && v -> right) {
        join(u -> right, v -> right);
    } else if (u -> right == 0 && v -> right) {
        u -> right = v -> right;
    }
}

Node* build_tree_1() {
    Node *root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);
    root -> left -> left -> left = new Node(8);
    root -> left -> left -> right = new Node(9);
    root -> left -> left -> right -> left = new Node(16);
    root -> left -> left -> right -> left -> left = new Node(10);
    root -> left -> left -> right -> left -> right = new Node(21);
    root -> left -> right -> left = new Node(13);
    root -> left -> right -> right = new Node(11);
    root -> left -> right -> right -> left = new Node(17);
    root -> left -> right -> right -> left -> right = new Node(0);
    root -> left -> right -> right -> right = new Node(18);
    root -> left -> right -> right -> right -> left = new Node(12);
    root -> right -> left -> left = new Node(14);
    root -> right -> left -> right = new Node(15);
    root -> right -> left -> right -> right = new Node(19);
    root -> right -> left -> right -> right -> right = new Node(20);
    root -> right -> right -> left = new Node(22);
    root -> right -> right -> right = new Node(23);
    return root;
}

Node* build_tree_2() {
    Node* root2 = new Node(4);
    root2 -> left = new Node(1);
    root2 -> right = new Node(7);
    root2 -> left -> left = new Node(3);
    root2 -> right -> left = new Node(2);
    root2 -> right -> right = new Node(6);
    return root2;
}

void inorder(Node* u) {
    if (u) {
        inorder(u -> left);
        cout << u -> data << " ";
        inorder(u -> right);
    }
}

void preorder(Node* u) {
    if (u) {
        cout << u -> data << " ";
        preorder(u -> left);
        preorder(u -> right);
    }
}

int main() {
    Node* root1 = build_tree_1();
    Node* root2 = build_tree_2();
    join(root1, root2);
    inorder(root1);
    cout << endl;
    preorder(root1);
    cout << endl;
    return 0;
}
