// https://www.geeksforgeeks.org/bottom-view-binary-tree/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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


vector <int> bottomView(Node *root);

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
//Function to return a list containing the bottom view of the given tree.

class Solution {
public:
    // time: O(n), memory: O(n)
    void fill(Node* root, unordered_map<int, pair<int, int>>& m, int v_lvl, int h_lvl, int& min_level) {
        if (!root) {
            return;
        }
        min_level = min(min_level, v_lvl);
        fill(root -> left, m, v_lvl - 1, h_lvl + 1, min_level);
        if (m.find(v_lvl) == m.end() || m[v_lvl].second <= h_lvl) {
            m[v_lvl] = {root -> data, h_lvl};
        }
        fill(root -> right, m, v_lvl + 1, h_lvl + 1, min_level);
    }

    vector<int> bottomView(Node *root) {
        int min_level = 0;
        unordered_map<int, pair<int, int>> m;
        fill(root, m, 0, 0, min_level);
        vector<int> v;
        while(m.find(min_level) != m.end()) {
            v.push_back(m[min_level].first);
            min_level++;
        }
        return v;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends
