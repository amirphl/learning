// https://www.geeksforgeeks.org/inorder-succesor-node-binary-tree/

#include<bits/stdc++.h>
#include<iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

// time: O(n), memory: O(n)
void find(Node* root, Node* u) {
    if (u -> right) {
        Node* temp = u;
        u = u -> right;

        while(u -> left) {
            u = u -> left;
        }

        std::cout << temp -> data << ":" << u -> data << " ";
        return;
    }

    std::stack<Node*> path;
    std::stack<Node*> s;
    s.push(root);

    while(!s.empty()) {
        Node* top = s.top();
        s.pop();
        path.push(top);

        if (top -> left == u) {
            std::cout << u -> data << ":" << top -> data << " ";
            return;
        }

        if (top -> right == u) {
            Node* t;
            Node* next = top;

            while(!path.empty()) {
                t = path.top();
                path.pop();

                if (t -> left == next) {
                    std::cout << u -> data << ":" << t -> data << " ";
                    return;
                }

                next = t;
            }

            std::cout << u -> data << ":" << "NULL" << " ";
            return;
        }

        if (top -> left)
            s.push(top -> left);
        if (top -> right)
            s.push(top -> right);
        if (top -> left == NULL && top -> right == NULL) {
            Node* t;

            while(!path.empty()) {
                t = path.top();
                if (t -> left == s.top() || t -> right == s.top()) {
                    break;
                }
                path.pop();
            }
        }
    }
}

int main() {
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> left -> right -> left = new Node(8);
    root -> left -> right -> left -> left = new Node(9);
    root -> left -> right -> left -> right = new Node(10);
    root -> right = new Node(3);
    root -> right -> left = new Node(6);
    root -> right -> left -> right = new Node(3);
    root -> right -> right = new Node(7);
    root -> right -> right -> right = new Node(11);
    root -> right -> right -> right -> left = new Node(12);

    std::queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();
        find(root, front);

        if (front -> left)
            q.push(front -> left);
        if (front -> right)
            q.push(front -> right);
    }
    return 0;
}
