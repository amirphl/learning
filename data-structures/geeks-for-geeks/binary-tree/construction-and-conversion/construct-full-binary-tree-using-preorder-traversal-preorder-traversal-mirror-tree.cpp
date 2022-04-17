// https://www.geeksforgeeks.org/construct-full-binary-tree-using-preorder-traversal-preorder-traversal-mirror-tree/

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

// time: O(VlogV), memory: O(V)
Node* cons(int pre[], int pre_mir[], int low, int high, int left, int right, map<int, int> &m) {
    if (low > high)
        return 0;

    Node* new_node = new Node(pre[low]);

    if (low == high) {
        return new_node;
    }

    int index = m[pre[low + 1]];

    new_node -> left = cons(pre, pre_mir, low + 1, low + 1 + right - index, index, right, m);
    new_node -> right = cons(pre, pre_mir, low + 1 + right - index + 1, high, left + 1, index - 1, m);

    return new_node;
}

void inorder(Node* root) {
    if (root) {
        std::cout << root -> data << " ";
        inorder(root -> left);
        inorder(root -> right);
    }
}

int main() {
    int pre[] = {1, 2, 4, 5, 8, 9, 12, 14, 15, 13, 3, 6, 7, 10, 11};
    int pre_mir[] = {1, 3, 7, 11, 10, 6, 2, 5, 9, 13, 12, 15, 14, 8, 4};
    int n = sizeof(pre) / sizeof(pre[0]);

    map<int, int> m;

    for(int i = 0; i < n; i++)
        m[pre_mir[i]] = i;

    Node* root = cons(pre, pre_mir, 0, n - 1, 0, n - 1, m);
    inorder(root);

	return 0;
}
