// https://www.geeksforgeeks.org/construct-binary-tree-string-bracket-representation/

#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>

using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;
    Node(char d) {
        data = d;
        left = right = 0;
    }
};

// time: O(n), memory: O(h)
Node* build(string in) {
    if (in.length() == 0)
        return 0;

    stack<Node*> s;
    Node* root = new Node(in[0]);
    s.push(root);
    Node* u;

    for(int i = 1; i < in.length(); i++) {
        if (in[i] == '(') {
            u = s.top();
        } else if (in[i] == ')') {
            s.pop();
        } else {
            Node* new_node = new Node(in[i]);
            s.push(new_node);

            if (u -> left) {
                u -> right = new_node;
            } else {
                u -> left = new_node;
            }
        }
    }

    return root;
}

void inorder(Node* root) {
    if (root) {
        inorder(root -> left);
        std::cout << root -> data << " ";
        inorder(root -> right);
    }
}

int main() {
    string in = "4(2(3(7(1)(2)))(1(8)(9)))(6(5(3(9(8))(7(6)))))";
    Node* root = build(in);
    inorder(root);

    return 0;
}
