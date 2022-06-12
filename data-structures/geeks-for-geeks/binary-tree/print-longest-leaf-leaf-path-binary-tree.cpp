// https://www.geeksforgeeks.org/print-longest-leaf-leaf-path-binary-tree/

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

void func(Node* root, vector<int>& path, vector<int>& longest) {
    if (!root) {
        return;
    }

    vector<int> left_path, right_path, left_longest, right_longest;
    func(root -> left, left_path, left_longest);
    func(root -> right, right_path, right_longest);
    longest = left_longest.size() > right_longest.size() ? left_longest : right_longest;
    longest.push_back(root -> data);

    if (left_path.size() >= right_path.size() && left_path.size() >= 1 + left_longest.size() + right_longest.size()) {
        path = left_path;
    } else if (right_path.size() >= left_path.size() && right_path.size() >= 1 + left_longest.size() + right_longest.size()) {
        path = right_path;
    } else {
        path = left_longest;
        path.push_back(root -> data);
        reverse(right_longest.begin(), right_longest.end());
        path.insert(path.end(), right_longest.begin(), right_longest.end());
    }
}

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

    vector<int> path, longest;
    func(root, path, longest);
    for(auto& it: path) {
        cout << it << " ";
    }
    cout << endl;
    for(auto& it: longest) {
        cout << it << " ";
    }
    cout << endl;

    path.clear();
    longest.clear();
    func(root -> left, path, longest);
    for(auto& it: path) {
        cout << it << " ";
    }
    cout << endl;
    for(auto& it: longest) {
        cout << it << " ";
    }
    cout << endl;


    return 0;
}
