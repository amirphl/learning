// https://www.geeksforgeeks.org/print-all-root-to-leaf-paths-with-there-relative-positions/

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

// time: O(n*n), memory: O(n)
void print_paths(Node* root) {
    unordered_map<Node*, Node*> m;
    stack<Node*> s;
    Node* curr = root;
    while(curr) {
        if (curr -> left == 0 && curr -> right == 0) {
            vector<int> v1;
            vector<int> v2;
            v1.push_back(curr -> data);
            v2.push_back(0);
            Node* u = curr;
            Node* v;
            int min_elem = 0;
            while(m.find(u) != m.end()) {
                v = m[u];
                v1.push_back(v -> data);
                if (v -> left == u) {
                    v2.push_back(v2.back() + 1);
                } else {
                    v2.push_back(v2.back() - 1);
                }
                min_elem = min(min_elem, v2.back());
                u = v;
            }
            int i = 0, j, n = v1.size();
            while(i < n) {
                j = 0;
                while(j < v2[n - 1 - i] + abs(min_elem)) {
                    cout << "_";
                    j++;
                }
                cout << v1[n - 1 - i] << endl;
                i++;
            }
            cout << "-------------" << endl;
        }
        if (curr -> right) {
            m[curr -> right] = curr;
            s.push(curr -> right);
        }
        m[curr -> left] = curr;
        curr = curr -> left;
        if (!curr && !s.empty()) {
            curr = s.top();
            s.pop();
        }
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

    print_paths(root);

    return 0;
}
