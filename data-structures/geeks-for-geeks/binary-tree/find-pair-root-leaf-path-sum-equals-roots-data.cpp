// https://www.geeksforgeeks.org/find-pair-root-leaf-path-sum-equals-roots-data/

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
void print_pair(Node* root) {
    stack<pair<Node*, bool>> s;
    s.push({root, false});
    unordered_map<int, int> u_set;
    while(!s.empty()) {
        Node* u = s.top().first;
        bool remove = s.top().second;
        s.pop();
        if (!remove) {
            s.push({u, true});
        } else {
            // cout << u -> data << " : " << u_set[u -> data] << endl;
            u_set[u -> data]--;
            if (u_set[u -> data] == 0) {
                u_set.erase(u -> data);
            }
            continue;
        }
        u_set[u -> data]++;
        if (u -> left) {
            s.push({u -> left, false});
        }
        if (u -> right) {
            s.push({u -> right, false});
        }
        if (u -> left == 0 && u -> right == 0) {
            cout << "path: ";
            pair<int, int> p = {INT_MAX, INT_MAX};
            for(auto& it: u_set) {
                int key = it.first;
                int freq = it.second;
                // cout << it.first << "_" << it.second << " ";
                cout << key << " ";
                if (u_set.find(root -> data - key) != u_set.end()) {
                    if (key == root -> data - key) {
                        if (freq > 1) {
                            p = {key, key};
                        }
                    } else {
                        p = {key, root -> data - key};
                    }
                }
            }
            cout << endl;
            cout << "pair: " << p.first << " " << p.second << endl;
            cout << endl;
        }
    }
}

int main() {
    Node *root = new Node(34);
    root -> left = new Node(17);
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

    print_pair(root);

    cout << endl;
    return 0;
}
