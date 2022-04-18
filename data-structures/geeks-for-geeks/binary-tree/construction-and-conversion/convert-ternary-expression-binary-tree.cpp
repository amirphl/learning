// https://www.geeksforgeeks.org/convert-ternary-expression-binary-tree/

#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>

using namespace std;

class Node{
    public:
        char data;
        Node* left;
        Node* right;

        Node(char d) {
            data = d;
            left = right = 0;
        }
};

// time: O(V), memory: O(V)
Node* build(string &in, int i, int &j) {
    if (i >= in.length()) {
        return 0;
    }

    Node* root = new Node(in[i]);

    if (i == in.length() - 1) {
        j = i;
        return root;
    }

    if (in[i + 1] == '?') {
        int k;
        root -> left = build(in, i + 2, k);
        root -> right = build(in, k + 2, k);
        j = k;
    } else {
        j = i;
    }

    return root;
}

void inorder(Node* root) {
    if (root) {
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }
}

int main() {
    string in = "a?b?c:d?1:2:e?f?3?4:5:6:g";
    int j;
    Node* root = build(in, 0, j);
    inorder(root);

	return 0;
}
