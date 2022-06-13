// https://www.geeksforgeeks.org/sink-odd-nodes-binary-tree/

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

// time: O(n), memory: O(n)
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

    queue<Node*> q;
    stack<Node*> s;
    q.push(root);
    while(!q.empty()) {
        Node* u = q.front();
        q.pop();
        s.push(u);
        if (u -> left) {
            q.push(u -> left);
        }
        if (u -> right) {
            q.push(u -> right);
        }
    }
    q.push(root);
    while(!q.empty()) {
        Node* u = q.front();
        q.pop();
        if (u -> data % 2 == 1) {
            while(!s.empty() && s.top() -> data % 2 == 1 && s.top() != u) {
                s.pop();
            }
            if (s.empty() || s.top() == u) {
                break;
            }
            cout << "replace " << u -> data << " with " << s.top() -> data << endl;
            int temp = u -> data;
            u -> data = s.top() -> data;
            s.top() -> data = temp;
            s.pop();
        }
        if (u -> left) {
            q.push(u -> left);
        }
        if (u -> right) {
            q.push(u -> right);
        }
    }

    return 0;
}
