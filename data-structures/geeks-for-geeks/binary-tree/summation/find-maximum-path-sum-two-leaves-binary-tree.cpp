// https://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/

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
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    int maxPathSum(Node* root)
    {
        int s;
        int res = maxPathSumRec(root, s);

        if (root -> left && root -> right) {
        } else if (root -> left == 0 && root -> right == 0) {
            res = root -> data;
        } else if (root -> left || root -> right) {
            res = max({res, s});
        }

        return res;
    }
    // time: O(V), memory: O(V)
    int maxPathSumRec(Node* root, int &s)
    {
        if (!root) {
            s = INT_MIN;
            return INT_MIN;
        }

        int res = INT_MIN;
        s = root -> data;

        if (root -> left || root -> right) {
            int s1, s2;
            int left = maxPathSumRec(root -> left, s1);
            int right = maxPathSumRec(root -> right, s2);
            s = (s1 > s2) ? s1 : s2;
            s += root -> data;

            if (root -> left && root -> right)
                res = max({left, s1 + (root -> data) + s2, right});
            else if (root -> left)
                res = left;
            else if (root -> right)
                res = right;
        }

        return res;
    }
};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.maxPathSum(root) << "\n";
    }
    return 0;
}  // } Driver Code Ends
