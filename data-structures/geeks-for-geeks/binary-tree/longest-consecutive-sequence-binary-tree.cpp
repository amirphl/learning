// https://www.geeksforgeeks.org/longest-consecutive-sequence-binary-tree/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

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
struct Node
{
	int data;
	Node *left, *right;
};
*/
class Solution {
public:
    // your task is tp complete this function
    // function should return the length of the longestConsecutive
    // sequence
    // time: O(n), memory: O(h)
    int longestConsecutive(Node* root)
    {
        int x, y;
        longestConsecutiveRec(root, x, y);
        if (x == 1) {
            return -1;
        }
        return x;
    }

    void longestConsecutiveRec(Node* root, int &x, int &y) {
        if (!root) {
            x = 0;
            y = 0;
            return;
        }
        int u, v, w, z;
        longestConsecutiveRec(root -> left, u, v);
        longestConsecutiveRec(root -> right, w, z);
        y = 1;
        if (root -> left && root -> data + 1 == root -> left -> data) {
            y = max(y, 1 + v);
        }
        if (root -> right && root -> data + 1 == root -> right -> data) {
            y = max(y, 1 + z);
        }
        x = max({u, w, y});
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution obj;
        cout<<obj.longestConsecutive(root)<<endl;
    }
    return 0;
}

// } Driver Code Ends
