// https://www.geeksforgeeks.org/convert-a-binary-tree-into-doubly-linked-list-in-spiral-fashion/

#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>

using namespace std;

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
void convert(Node* root) {
    deque<Node*> q;
    q.push_front(0);
    q.push_front(root);

    bool right = false;
    Node* prv = 0;

    while(q.size() > 1) {
        Node* u = (right) ? q.back() : q.front();

        if (u == 0) {
            right = !right;
            continue;
        }

        if (prv) {
            prv -> right = u;
            prv = u;
        } else {
            prv = u;
        }
        // std::cout << u -> data << " ";

        if (right) {
            q.pop_back();

            if (u -> right) {
                q.push_front(u -> right);
            }

            if (u -> left) {
                q.push_front(u -> left);
            }
        } else {
            q.pop_front();

            if (u -> left) {
                q.push_back(u -> left);
            }
            if (u -> right) {
                q.push_back(u -> right);
            }
        }
    }
}

int main() {
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> left -> left -> left = new Node(8);
    root -> left -> left -> right = new Node(9);
    root -> left -> right -> left = new Node(10);
    root -> left -> right -> right = new Node(11);
    root -> right -> left = new Node(6);
    root -> right -> left -> right = new Node(13);
    root -> right -> right = new Node(7);
    root -> right -> right -> left = new Node(14);

    convert(root);
    Node* t = root;

    while(t) {
        std::cout << t -> data << " - ";
        t = t -> right;
    }

	return 0;
}
