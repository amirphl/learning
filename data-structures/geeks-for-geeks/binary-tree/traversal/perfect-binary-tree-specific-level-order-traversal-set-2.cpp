// https://www.geeksforgeeks.org/perfect-binary-tree-specific-level-order-traversal-set-2/

#include<bits/stdc++.h>
#include<iostream>

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int d) {
            data = d;
            left = right = 0;
        }
};

// time: O(V), memory: O(V)
void traverse(Node* root) {
    std::stack<Node*> sta;
    sta.push(root);

    if (root -> left == 0 || root -> right == 0) {
        std::cout << sta.top() -> data << " ";
        sta.pop();
        return;
    }

    std::queue<Node*> q;
    q.push(root -> left);
    q.push(root -> right);

    while(!q.empty()) {
        Node* f = q.front();
        q.pop();
        Node* s = q.front();
        q.pop();

        sta.push(s);
        sta.push(f);

        if (f -> right)
            q.push(f -> right);
        if (s -> left)
            q.push(s -> left);
        if (f -> left)
            q.push(f -> left);
        if (s -> right)
            q.push(s -> right);
    }

    while(!sta.empty()) {
        std::cout << sta.top() -> data << " ";
        sta.pop();
    }
}

int main() {
    Node * n1 = new Node(1);
    Node * n2 = new Node(2);
    Node * n3 = new Node(3);
    Node * n4 = new Node(4);
    Node * n5 = new Node(5);
    Node * n6 = new Node(6);
    Node * n7 = new Node(7);
    Node * n8 = new Node(8);
    Node * n9 = new Node(9);
    Node * n10 = new Node(10);
    Node * n11 = new Node(11);
    Node * n12 = new Node(12);
    Node * n13 = new Node(13);
    Node * n14 = new Node(14);
    Node * n15 = new Node(15);

    n1 -> left  = n2;
    n1 -> right = n3;
    n2 -> left  = n4;
    n2 -> right = n5;
    n3 -> left  = n6;
    n3 -> right = n7;
    n4 -> left  = n8;
    n4 -> right = n9;
    n5 -> left  = n10;
    n5 -> right = n11;
    n6 -> left  = n12;
    n6 -> right = n13;
    n7 -> left  = n14;
    n7 -> right = n15;

    traverse(n1);

    return 0;
}
