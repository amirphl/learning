// https://www.geeksforgeeks.org/closest-leaf-to-a-given-node-in-binary-tree/

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

int shortest_leaf(Node* root, int& dist) {
    if (!root) {
        dist = 0;
        return INT_MIN;
    }
    if (root -> left == 0 && root -> right == 0) {
        dist = 1;
        return root -> data;
    }
    int d_left, d_right;
    int leaf_left = shortest_leaf(root -> left, d_left);
    int leaf_right = shortest_leaf(root -> right, d_right);
    dist = 1 + max(d_left, d_right);
    return d_left > d_right ? leaf_left : leaf_right;
}

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

    for(int x = 0; x <= 25; x++) {
        cout << "x = " << x << endl;
        Node* path[500];
        int d = 0;
        stack<pair<Node*, int>> s;
        s.push({root, d});
        while(!s.empty()) {
            Node* u = s.top().first;
            d = s.top().second;
            s.pop();
            path[d] = u;
            if (u -> data == x) {
                break;
            }
            // cout << u -> data << " ";
            if (u -> left) {
                s.push({u -> left, d + 1});
            }
            if (u -> right) {
                s.push({u -> right, d + 1});
            }
        }

        Node* u = path[d];
        if (u -> data == x) {
            int dist, leaf;
            if (u -> left) {
                leaf = shortest_leaf(u -> left, dist);
                cout << leaf << " --- " << dist << endl;
            }
            if (u -> right) {
                leaf = shortest_leaf(u -> right, dist);
                cout << leaf << " ___ " << dist << endl;
            }
            Node* prv = u;
            d--;
            int i = 0;
            while(d >= 0) {
                u = path[d];
                if (u -> left == prv) {
                    leaf = shortest_leaf(u -> right, dist);
                } else {
                    leaf = shortest_leaf(u -> left, dist);
                }
                cout << leaf << " " << dist + i + 1 << endl;
                i++;
                d--;
                prv = u;
            }
        } else {
            cout << x << " not found!" << endl;
        }
        cout << "----------------" << endl;
    }

    cout << endl;
    return 0;
}
