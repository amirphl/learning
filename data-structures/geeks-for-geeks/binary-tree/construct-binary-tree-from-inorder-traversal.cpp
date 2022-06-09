// https://www.geeksforgeeks.org/construct-binary-tree-from-inorder-traversal/

#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    int low, idx, high, data;
    Node(int l, int i, int h, int d) {
        low = l;
        idx = i;
        high = h;
        data = d;
    }
};

int find_max_idx(int arr[], int low, int high) {
    int idx = low, i = low;
    int cand = arr[low];
    while(i <= high) {
        if(arr[i] > cand) {
            cand = arr[i];
            idx = i;
        }
        i++;
    }
    return idx;
}

void preorder(Node* root) {
    if (root) {
        cout << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}

void inorder(Node* root) {
    if (root) {
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }
}

// time: O(n*n), memory: O(n)
int main() {
    int arr[] = {1, 5, 10, 40, 30, 15, 28, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    stack<Node*> s;
    int idx = find_max_idx(arr, 0, n - 1);
    Node* root = new Node(0, idx, n - 1, arr[idx]);
    s.push(root);
    while(!s.empty()) {
        Node* u = s.top();
        s.pop();
        if (u -> low < u -> idx) {
            idx = find_max_idx(arr, u -> low, (u -> idx) - 1);
            u -> left = new Node(u -> low, idx, (u -> idx) - 1, arr[idx]);
            s.push(u -> left);
        }
        if (u -> idx < u -> high) {
            idx = find_max_idx(arr, (u -> idx) + 1, u -> high);
            u -> right = new Node((u -> idx) + 1, idx, u -> high, arr[idx]);
            s.push(u -> right);
        }
    }
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    return 0;
}
