// https://www.geeksforgeeks.org/sum-nodes-k-th-level-tree-represented-string/

#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = right = 0;
    }
};

// time: O(n), memory: O(n)
void calc(string in, int k) {
    int i = 0, level = 0;
    stack<char> s;

    while (i < in.length()) {
        if (in[i] == '(') {
            s.push(in[i]);
        } else if (in[i] == ')') {
            if (s.top() != '(') {
                level--;
                s.pop();
            }

            s.pop();
        } else {
            s.push(in[i]);
            level++;

            if (level == k) {
                cout << in[i] << " ";
            }
        }
        i++;
    }
}

void inorder(Node* root) {
    if (root) {
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }
}

void preorder(Node* root) {
    if (root) {
        cout << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}

// time: O(n), memory: O(n)
Node* build_tree(string in) {
    stack<pair<Node*, bool>> s;
    Node* root = new Node(in[1] - 48);
    s.push({root, false});
    s.push({root, true});
    int i = 2;
    while(i < in.length()) {
        if (in[i] == '(') {
            Node* par = s.top().first;
            bool append_left = s.top().second;
            s.pop();
            i++;
            Node* u = 0;
            if (in[i] != ')') {
                u = new Node(in[i] - 48);
                s.push({u, false});
                s.push({u, true});
            }
            if (append_left) {
                // cout << par -> data << "  l  " << (u == 0 ? -1 : u -> data) << endl;
                par -> left = u;
            } else {
                // cout << par -> data << "  r  " << (u == 0 ? -1 : u -> data) << endl;
                par -> right = u;
            }
        }
        i++;
    }

    return root;
}

int main() {
    string in("(0(5(6()())(4(3(2()(9()()))())(8()())))(7(1()())(5()())))");
    int k = 3;
    cin >> k;

    calc(in, k);
    cout << endl;
    Node* root = build_tree(in);
    cout << "inorder:" << endl;
    inorder(root);
    cout << endl;
    cout << "preorder: " << endl;
    preorder(root);
    cout << endl;

    return 0;
}
