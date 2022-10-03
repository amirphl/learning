// https://www.geeksforgeeks.org/connect-nodes-at-same-level-with-o1-extra-space/

#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    Node* next;
    int data;
    Node(int d) {
        data = d;
        left = 0;
        right = 0;
        next = 0;
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

    Node* res[500];
    Node* fir[500];
    memset(res, 0, sizeof(res));
    memset(res, 0, sizeof(fir));
    int lvl = 0;
    Node* curr = root;
    while(curr) {
        if (curr -> left) {
            int to_up = 0;
            Node* r = curr -> left;
            while(r -> right && r -> right != curr) {
                r = r -> right;
                to_up++;
            }
            if (r -> right) {
                r -> right = 0;
                lvl -= to_up + 1;
                curr = curr -> right;
            } else {
                r -> right = curr;
                if (res[lvl]) {
                    res[lvl] -> next = curr;
                } else {
                    fir[lvl] = curr;
                }
                res[lvl] = curr;
                cout << curr -> data << ":" << lvl << " ";
                lvl++;
                curr = curr -> left;
            }
        } else {
            if (res[lvl]) {
                res[lvl] -> next = curr;
            } else {
                fir[lvl] = curr;
            }
            res[lvl] = curr;
            cout << curr -> data << ":" << lvl << " ";
            lvl++;
            curr = curr -> right;
        }
    }
    cout << endl;
    if (fir[lvl + 1] != 0) {
        lvl++;
    }
    while(lvl >= 0) {
        Node* u = fir[lvl];
        while(u) {
            cout << u -> data << " ";
            u = u -> next;
        }
        cout << endl;
        lvl--;
    }
    cout << endl;
    return 0;
}
