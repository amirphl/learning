// https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1/?page=1&difficulty[]=1&status[]=unsolved&category[]=Tree&sortBy=submissions#

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
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
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
// User Fuction template for C++

class Solution {
public:
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root) {
        int max_ending_here, max_seen;
        findMaxSumRec(root, max_ending_here, max_seen);
        return max_seen;
    }

    // time: O(n), memory: O(h)
    void findMaxSumRec(Node* root, int& max_ending_here, int& max_seen) {
        if (!root) {
            max_ending_here = 0;
            max_seen = INT_MIN;
            return;
        }
        int max_ending_left, max_ending_right;
        int max_seen_left, max_seen_right;
        findMaxSumRec(root -> left, max_ending_left, max_seen_left);
        findMaxSumRec(root -> right, max_ending_right, max_seen_right);
        int x = max(max_ending_left, max_ending_right);
        max_ending_here = x > 0 ? x + root -> data : root -> data;
        int y = root -> data;
        y += max_ending_left > 0 ? max_ending_left : 0;
        y += max_ending_right > 0 ? max_ending_right : 0;
        max_seen = max({y, max_seen_left, max_seen_right});
        // cout << root -> data << " " << max_seen << " " << max_ending_here << endl;
    }
};

// { Driver Code Starts.


int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        cout << ob.findMaxSum(root) << "\n";

    }


    return 0;
}  // } Driver Code Ends
