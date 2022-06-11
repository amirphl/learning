// https://www.geeksforgeeks.org/remove-all-nodes-which-lie-on-a-path-having-sum-less-than-k/

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

void inorder(Node* root) {
    if (!root) {
        return;
    }
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void preorder(Node* root) {
    if (!root) {
        return;
    }
    cout << root -> data << " ";
    inorder(root -> left);
    inorder(root -> right);
}

// time: O(n), memory: O(h)
void prune(Node* root, int k, int& max_sum) {
    if (!root) {
        max_sum = 0;
        return;
    }
    int diff = k - root -> data;
    int left_max, right_max;
    prune(root -> left, diff, left_max);
    if (left_max < diff) {
        if (root -> left) {
            cout << root -> left -> data << " ";
        }
        delete(root -> left);
        root -> left = 0;
    }
    prune(root -> right, diff, right_max);
    if (right_max < diff) {
        if (root -> right) {
            cout << root -> right -> data << " ";
        }
        delete(root -> right);
        root -> right = 0;
    }
    max_sum = root -> data + max(left_max, right_max);
}

int main() {
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

    int k;
    cin >> k;
    int h;
    cout << "deleted:" << endl;
    prune(root, k, h);
    cout << endl;
    if (h < k) {
        delete(root);
        root = 0;
    }
    cout << "inorder: " << endl;
    inorder(root);
    cout << endl;
    cout << "preorder: " << endl;
    preorder(root);
    cout << endl;

    return 0;
}
