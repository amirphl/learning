// https://www.geeksforgeeks.org/level-order-traversal-direction-change-every-two-levels/

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
    root -> left -> left -> right -> left -> left = new Node(-4);
    root -> left -> left -> right -> left -> right = new Node(99);
    root -> left -> right -> left = new Node(3);
    root -> left -> right -> right = new Node(1);
    root -> left -> right -> right -> left = new Node(17);
    root -> left -> right -> right -> left -> right = new Node(0);
    root -> left -> right -> right -> right = new Node(18);
    root -> left -> right -> right -> right -> left = new Node(21);
    root -> right -> left -> left = new Node(4);
    root -> right -> left -> right = new Node(2);
    root -> right -> left -> right -> right = new Node(19);
    root -> right -> left -> right -> right -> right = new Node(9);
    root -> right -> right -> left = new Node(7);
    root -> right -> right -> right = new Node(2);

    int level = 0;
    Node* u;
    deque<Node*> q;
    q.push_front(root);
    q.push_front(0);
    while(q.size() > 1) {
        if (level % 4 > 1) {
            u = q.front();
            q.pop_front();
            if (u == 0) {
                if (level % 4 == 2)
                    q.push_back(0);
                else
                    q.push_front(0);
                level++;
                cout << endl;
                continue;
            }
            cout << u -> data << " ";
            if (u -> right) {
                q.push_back(u -> right);
            }
            if (u -> left) {
                q.push_back(u -> left);
            }
        } else {
            u = q.back();
            q.pop_back();
            if (u == 0) {
                if (level % 4 == 0)
                    q.push_front(0);
                else
                    q.push_back(0);
                level++;
                cout << endl;
                continue;
            }
            cout << u -> data << " ";
            if (u -> left) {
                q.push_front(u -> left);
            }
            if (u -> right) {
                q.push_front(u -> right);
            }
        }
    }
    cout << endl;
    return 0;
}
