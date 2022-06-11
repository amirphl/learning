// https://www.geeksforgeeks.org/maximum-sum-tree-adjacent-levels-not-allowed/

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

// time: O(n), memory: O(h)
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

    vector<int> sums;
    sums.push_back(0);
    queue<Node*> q;
    int level = 0;
    q.push(root);
    q.push(0);
    while(q.size() > 1) {
        Node* u = q.front();
        q.pop();
        if (!u) {
            level++;
            sums.push_back(0);
            q.push(0);
            continue;
        }
        sums[level] += u -> data;
        if (u -> left) {
            q.push(u -> left);
        }
        if (u -> right) {
            q.push(u -> right);
        }
    }

    if (sums.size() == 1) {
        cout << sums[0] << endl;
        return 0;
    }

    int dp[sums.size()];
    dp[0] = sums[0];
    dp[1] = max(sums[0], sums[1]);
    int i = 2;
    while(i < sums.size()) {
        dp[i] = max(sums[i] + dp[i - 2], sums[i - 1]);
        i++;
    }
    cout << dp[i - 1] << endl;
    return 0;
}
