// https://www.geeksforgeeks.org/check-symmetric-binary-tree-iterative-approach/
// https://www.geeksforgeeks.org/symmetric-tree-tree-which-is-mirror-image-of-itself/

// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


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
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
Structure of the node of the tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
public:
    // return true/false denoting whether the tree is Symmetric or not
    // time: O(n), memory: O(n)
    bool isSymmetric(struct Node* root)
    {
        if(!root) {
            return true;
        }

        if (root -> left == 0 && root -> right == 0) {
            return true;
        }
        if (root -> left == 0 && root -> right) {
            return false;
        }
        if (root -> left && root -> right == 0) {
            return false;
        }

        queue<Node*> q;
        q.push(root -> left);
        q.push(root -> right);

        while(!q.empty()) {
            Node* u = q.front();
            q.pop();
            Node* v = q.front();
            q.pop();

            if (u -> data != v -> data) {
                return false;
            }
            if (u -> left && v -> right && u -> left -> data != v -> right -> data) {
                return false;
            }
            if (u -> right && v -> left && u -> right -> data != v -> left -> data) {
                return false;
            }
            if (u -> left && v -> right == 0) {
                return false;
            }
            if (u -> left == 0 && v -> right) {
                return false;
            }
            if (u -> right && v ->left == 0) {
                return false;
            }
            if (u -> right == 0 && v ->left) {
                return false;
            }

            if (u -> left) {
                q.push(u -> left);
            }
            if (v -> right) {
                q.push(v -> right);
            }

            if (u -> right) {
                q.push(u -> right);
            }
            if (v -> left) {
                q.push(v -> left);
            }
        }

        return true;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/



int main() {


    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);

        Node* root = buildTree(s);

        vector<int> ans;
        Solution ob;
        if(ob.isSymmetric(root)) {
            cout<<"True"<<endl;
        }
        else {
            cout<<"False"<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
