// https://www.geeksforgeeks.org/print-nodes-distance-k-leaf-node/

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


int printKDistantfromLeaf(Node* node, int k);

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


int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s, ks;
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, ks);
        int k=stoi(ks);
        cout<<printKDistantfromLeaf(root, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends


//Node Structure
/*struct Node
{
	int key;
	Node *left, *right;
};*/


//Function to return count of nodes at a given distance from leaf nodes.
// time: O(n), memory: O(n)
int printKDistantfromLeaf(Node* root, int k)
{
    unordered_set<Node*> res;
    unordered_map<Node*, Node*> m;
    stack<pair<Node*, Node*>> s;
    Node* curr = root;
    Node* par = 0;
    while(curr) {
        m[curr] = par;
        if (curr -> left == 0 && curr -> right == 0) {
            Node* u = curr;
            // cout << u -> data << " : ";
            int i = 0;
            while(i < k && m.find(u) != m.end()) {
                u = m[u];
                i++;
            }
            if (u) {
                // cout << u -> data;
                res.insert(u);
            }
            // cout << endl;
        }
        if (curr -> right) {
            s.push({curr -> right, curr});
        }
        par = curr;
        curr = curr -> left;
        if (!curr && !s.empty()) {
            curr = s.top().first;
            par = s.top().second;
            s.pop();
        }
    }
    return res.size();
}
