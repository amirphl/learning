// https://www.geeksforgeeks.org/print-k-sum-paths-binary-tree/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* right;
    Node* left;
    Node(int d) {
        data = d;
        left = right = 0;
    }
};

void print_path(vector<Node*> vec) {
    for(auto it = vec.begin(); it != vec.end(); it++) {
        cout << (*it) -> data << " ";
    }

    cout << endl;
}

// time: O(n), memory: O(n)
void print_from_root(Node* root, vector<Node*> &vec, int rem) {
    vec.push_back(root);

    if(root -> data == rem) {
        print_path(vec);
    }
    if (root -> left) {
        print_from_root(root -> left, vec, rem - root -> data);
    }
    if (root -> right) {
        print_from_root(root -> right, vec, rem - root -> data);
    }

    vec.pop_back();
}

// time: O(n*h), memory: O(n)
void print(Node* root, vector<Node*> &vec, int k) {
    vec.push_back(root);

    if (root -> left) {
        print(root -> left, vec, k);
    }
    if (root -> right) {
        print(root -> right, vec, k);
    }

    vector<Node*> v;
    print_from_root(root, v, k);
    vec.pop_back();
}

int main() {
    Node* root = new Node(1);
    root -> left = new Node(3);
    root -> right = new Node(-1);
    root -> left -> left = new Node(2);
    root -> left -> right = new Node(1);
    root -> left -> right -> left = new Node(1);
    root -> right -> right = new Node(5);
    root -> right -> right -> right = new Node(6);
    root -> right -> left = new Node(4);
    root -> right -> left -> left = new Node(1);
    root -> right -> left -> right = new Node(2);

    int k = 5;
    vector<Node*> vec;
    print(root, vec, k);

    return 0;
}
