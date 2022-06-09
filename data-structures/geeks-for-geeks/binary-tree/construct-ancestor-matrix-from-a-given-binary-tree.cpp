// https://www.geeksforgeeks.org/construct-ancestor-matrix-from-a-given-binary-tree/

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

// time: O(n*n), memory: O(n*n)
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

    int n = 24;
    int mat[24][24] = {0};
    vector<Node*> path(50);
    stack<pair<Node*, int>> s;
    s.push({root, 0});
    while(!s.empty()) {
        Node* u = s.top().first;
        int lvl = s.top().second;
        path[lvl] = u;
        s.pop();
        cout << "path to " << u -> data << " : ";
        for(int i = 0; i < lvl; i++) {
            cout << path[i] -> data << " ";
            mat[path[i] -> data][u -> data] = 1;
        }
        cout << endl;
        if (u -> left) {
            s.push({u -> left, lvl + 1});
        }
        if (u -> right) {
            s.push({u -> right, lvl + 1});
        }
    }
    int i = 0, j;
    cout << "mat:" << endl;
    while(i < n) {
        j = 0;
        while(j < n) {
            cout << mat[i][j] << " ";
            j++;
        }
        cout << endl;
        i++;
    }
    cout << endl;
    return 0;
}
