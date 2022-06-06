// https://www.geeksforgeeks.org/find-distance-between-two-nodes-of-a-binary-tree/

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
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        bool f_a, f_b;
        return findDistRec(root, a, b, f_a, f_b);
    }
    // time: O(n), memory: O(h)
    int findDistRec(Node* root, int a, int b, bool& found_a, bool& found_b) {
        if (!root) {
            found_a = 0;
            found_b = 0;
            return -1;
        }
        bool f_a_left, f_b_left;
        int left = findDistRec(root -> left, a, b, f_a_left, f_b_left);
        if (f_a_left && f_b_left) {
            found_a = true;
            found_b = true;
            return left;
        }
        bool f_a_right, f_b_right;
        int right = findDistRec(root -> right, a, b, f_a_right, f_b_right);
        if (f_a_right && f_b_right) {
            found_a = true;
            found_b = true;
            return right;
        }
        found_a = root -> data == a || f_a_left || f_a_right;
        found_b = root -> data == b || f_b_left || f_b_right;
        if (found_a && found_b) {
            return find_min_h(root, a, 0) + find_min_h(root, b, 0);
        } else {
            return -1;
        }
    }
    int find_min_h(Node* root, int key, int lvl) {
        if(!root) {
            return INT_MAX;
        }
        if (root -> data == key) {
            return lvl;
        }
        int left_h = find_min_h(root -> left, key, lvl + 1);
        int right_h = find_min_h(root -> right, key, lvl + 1);
        return min(left_h, right_h);
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
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}
  // } Driver Code Ends
