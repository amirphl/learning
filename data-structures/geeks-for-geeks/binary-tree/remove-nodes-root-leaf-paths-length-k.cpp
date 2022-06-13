// https://www.geeksforgeeks.org/remove-nodes-root-leaf-paths-length-k/

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

class Data {
public:
    Node* par;
    Node* node;
    int type, k;
    Data(Node* p, Node* n, int t, int _k) {
        par = p;
        node = n;
        type = t;
        k = _k;
    }
};

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

    // added myself
    root -> right -> left -> right -> right -> right -> right = new Node(202);

    root -> right -> right -> left = new Node(22);
    root -> right -> right -> right = new Node(23);

    int k = 4;
    cin >> k;
    stack<Data*> s;
    Node* fake = new Node(-1);
    fake -> left = root;
    s.push(new Data(fake, root, 1, k));
    s.push(new Data(root, root -> right, 0, k - 1));
    s.push(new Data(root, root -> left, 0, k - 1));
    while(!s.empty()) {
        Data* d = s.top();
        s.pop();
        if (d -> node == 0) {
            continue;
        }
        if (d -> type == 0) {
            if (d -> k != 0) {
                s.push(new Data(d -> par, d -> node, 1, d -> k));
                s.push(new Data(d -> node, d -> node -> right, 0, d -> k - 1));
                s.push(new Data(d -> node, d -> node -> left, 0, d -> k - 1));
            } else {

            }
        } else {
            if (d -> k != 0) {
                if (d -> node -> left == 0 && d -> node -> right == 0) {
                    if (d -> par -> left == d -> node) {
                        d -> par -> left = 0;
                    } else {
                        d -> par -> right = 0;
                    }
                    cout << d -> node -> data << " ";
                    delete(d -> node);
                }
            } else {

            }
        }
    }
    cout << endl;
    return 0;
}
