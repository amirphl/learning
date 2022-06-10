// https://www.geeksforgeeks.org/iterative-method-check-two-trees-mirror/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* Node structure
struct Node
{
    int data;
    Node* left, *right;
}; */

/* Given two trees, should return true if they are
   mirror of each other. */
class Solution
{
    public:
    // time: O(n), memory: O(h)
    int areMirror(Node* a, Node* b) {
        queue<vector<Node*>> q1;
        queue<vector<Node*>> q2;
        q1.push({a, 0});
        q2.push({b, 0});
        while(!q1.empty() || !q2.empty()) {
            if (q1.empty() || q2.empty()) {
                return false;
            }
            Node* u = q1.front()[0];
            Node* v = q2.front()[0];
            Node* u_par = q1.front()[1];
            Node* v_par = q2.front()[1];
            q1.pop();
            q2.pop();
            // checking parents are important!
            if (u -> data != v -> data || (u_par && v_par && u_par -> data != v_par -> data)) {
                return false;
            }
            if (u -> left) {
                q1.push({u -> left, u});
            }
            if (u -> right) {
                q1.push({u -> right, u});
            }
            if (v -> right) {
                q2.push({v -> right, v});
            }
            if (v -> left) {
                q2.push({v -> left, v});
            }
        }
        return true;
    }

};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);

        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);

        Solution ob;
        cout << ob.areMirror(root1, root2) << "\n";
    }
    return 0;

}  // } Driver Code Ends
