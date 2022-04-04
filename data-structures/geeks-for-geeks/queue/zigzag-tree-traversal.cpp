// https://www.geeksforgeeks.org/zigzag-tree-traversal/

// other approaches:
// 1- (TODO) recursive
// 2- using dequeue: file: zigzag-tree-traversal-2.cpp
// 3- (TODO) using queue

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
//User function Template for C++
/*Structure of the node of the binary tree is as
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

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    // time: O(V), memory: O(V)
    vector <int> zigZagTraversal(Node* root)
    {
    	std::stack<Node*> s1;
    	std::stack<Node*> s2;
    	std::vector<int> vec;
        int n = 0;
        Node* top;
        s1.push(root);

        while(!s1.empty() || !s2.empty()) {
            if (n == 0) {
                top = s1.top();
                vec.push_back(top -> data);
                s1.pop();
                if (top -> left)
                    s2.push(top -> left);
                if (top -> right)
                    s2.push(top -> right);
            } else {
                top = s2.top();
                vec.push_back(top -> data);
                s2.pop();
                if (top -> right)
                    s1.push(top -> right);
                if (top -> left)
                    s1.push(top -> left);
            }
            if (s1.empty())
                n = 1;
            if (s2.empty())
                n = 0;
        }

        return vec;
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
        ans = ob.zigZagTraversal(root) ;

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << endl;
     
    }
    return 0;
}
  // } Driver Code Ends
