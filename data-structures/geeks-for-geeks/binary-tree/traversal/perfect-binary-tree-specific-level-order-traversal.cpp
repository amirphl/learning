// https://www.geeksforgeeks.org/perfect-binary-tree-specific-level-order-traversal/

// other approaches:
// The standard level order traversal idea will slightly change here. Instead of processing ONE node at a time, we will process TWO nodes at a time. And while pushing children into queue, the enqueue order will be: 1st node’s left child, 2nd node’s right child, 1st node’s right child and 2nd node’s left child.

// TODO(amirphl)
// How will you do specific level order traversal from BOTTOM to TOP (Amazon Interview | Set 120 – Round 1 Last Problem)
// What if tree is not perfect, but complete.
// What if tree is neither perfect, nor complete. It can be any general binary tree.

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
    std::cout << root -> data << " ";

    if (root -> left == 0 && root -> right == 0) {
        return;
    }

    std::queue<Node*> q1;
    std::queue<Node*> q2;

    q1.push(root -> left);
    q2.push(root -> right);

    while(!q1.empty() && !q2.empty()) {
        Node* f1 = q1.front();
        Node* f2 = q2.front();
        q1.pop();
        q2.pop();

        std::cout << f1 -> data << " " << f2 -> data << " ";

        if (f1 -> left)
            q1.push(f1 -> left);
        if (f1 -> right)
            q1.push(f1 -> right);
        if (f2 -> right)
            q2.push(f2 -> right);
        if (f2 -> left)
            q2.push(f2 -> left);
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
