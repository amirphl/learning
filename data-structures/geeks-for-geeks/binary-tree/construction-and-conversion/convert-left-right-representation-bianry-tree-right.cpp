// https://www.geeksforgeeks.org/convert-left-right-representation-bianry-tree-right/

#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>

using namespace std;

// time: O(V), memory: O(V)
void convert(Node* root) {
    if(!root) {
        return;
    }

    convert(root -> left);
    convert(root -> right);

    if (root -> left) {
        root -> left -> right = root -> right;
    } else {
        root -> left = root -> right;
    }

    root -> right = 0;
}

int main() {
	return 0;
}
