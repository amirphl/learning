// https://www.geeksforgeeks.org/print-root-leaf-path-without-using-recursion/

// other approach: Use map to maintain the path to the root like linkedlist

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

void print_recu(stack<Node*> &s) {
    if (s.empty())
        return;

    Node* u = s.top();
    s.pop();
    print_recu(s);

    if (u != (Node*)1 && u != (Node*)2) {
        cout << u -> data << " ";
    }

    s.push(u);
}

// time: O(V), memory: O(V)
// assumed that printing takes O(1)
void print(Node* root) {
    Node* u = root;
    stack<Node*> s;

    while(u) {
        // std::cout << u << " " << u -> data << " ";
        // if (u != (Node*)1 && u != (Node*)2 && u -> data == 9)
        //      break;
        if (u == (Node*)2) {
            s.pop();
            u = s.top();
            s.push((Node*)1);

            if (u -> right) {
                u = u -> right;
            } else {
                u = (Node*)1;
            }
        } else if (u == (Node*)1) {
            s.pop();
            s.pop();
            u = 0;

            if (!s.empty()) {
                u = s.top();
            }
        } else if (u -> left) {
            s.push(u);
            s.push((Node*)2);
            u = u -> left;
        } else if (u -> right) {
            s.push(u);
            s.push((Node*)1);
            u = u -> right;
        } else {
            // cout << u -> data << " ";
            print_recu(s);
            cout << u -> data << endl;

            if (!s.empty()) {
                Node* top = s.top();

                if (top == (Node*)2) {
                    s.pop();
                    u = s.top();
                    s.push((Node*)1);
                    if (u -> right) {
                        u = u -> right;
                    } else {
                        u = (Node*)1;
                    }
                } else if (top == (Node*)1) {
                    u = (Node*)1;
                }
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

    print(root);

	return 0;
}
