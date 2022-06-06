// https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

struct Node* deleteNode(struct Node* root, int key);

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorder(Node* root, vector<int>& v) {
    if (root == NULL) return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);
        getline(cin, s);
        int k = stoi(s);
        root1 = deleteNode(root1, k);
        vector<int> v;
        inorder(root1, v);
        for (auto i : v) cout << i << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends


Node* find_min(Node* root, Node*& par) {
    if (root -> left) {
        par = root;
        return find_min(root -> left, par);
    }
    return root;
}

Node* deleteNodeRec(Node *root, Node *par, int X) {
    if (!root) {
        return 0;
    }
    if (root -> data > X) {
        return deleteNodeRec(root -> left, root, X);
    } else if (root -> data < X) {
        return deleteNodeRec(root -> right, root, X);
    }
    if (root -> left == 0 && root -> right == 0) {
        if (par -> left == root) {
            par -> left = 0;
        }
        if (par -> right == root) {
            par -> right = 0;
        }
        return root;
    }
    if (root -> left && root -> right == 0) {
        if (par -> left == root) {
            par -> left = root -> left;
        }
        if (par -> right == root) {
            par -> right = root -> left;
        }
        return root;
    }
    if (root -> left == 0 && root -> right) {
        if (par -> left == root) {
            par -> left = root -> right;
        }
        if (par -> right == root) {
            par -> right = root -> right;
        }
        return root;
    }
    Node* p_min = root;
    Node* min = find_min(root -> right, p_min);
    if (p_min != root) {
        p_min -> left = min -> right;
    } else {
        p_min -> right = min -> right;
    }
    int temp = min -> data;
    min -> data = root -> data;
    root -> data = temp;
    return root;
}

// Function to delete a node from BST.
// time: O(logn) (in case of balanced BST)
// memory: O(logn) (in case of balanced BST) (use iterative approach to reduce time complexity to O(1))
// otherwise:
// time: O(n), memory: O(n)
Node* deleteNode(Node *root, int X) {
    if (root -> data > X) {
        deleteNodeRec(root -> left, root, X);
        return root;
    }
    if (root -> data < X) {
        deleteNodeRec(root -> right, root, X);
        return root;
    }
    if (root -> right) {
        Node* p_min = root;
        Node* min = find_min(root -> right, p_min);
        if (p_min != root) {
            p_min -> left = min -> right;
        } else {
            p_min -> right = min -> right;
        }
        int temp = min -> data;
        min -> data = root -> data;
        root -> data = temp;
        return root;
    } else {
        return root -> left;
    }
}
