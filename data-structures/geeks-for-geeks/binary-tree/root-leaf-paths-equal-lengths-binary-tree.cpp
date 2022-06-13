// https://www.geeksforgeeks.org/root-leaf-paths-equal-lengths-binary-tree/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


void pathCounts( Node* node);

/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
    if (node==NULL)
        return 0;
    else
        return 1 + max(height(node->left), height(node->right));
}

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
    Node *root = new Node(stoi(ip[0]));

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

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
/* Driver program to test size function*/
int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string treeString;
        getline(cin,treeString);
        Node* root = buildTree(treeString);
        pathCounts(root);
        cout<< endl;
    }
    return 0;
}

// } Driver Code Ends


/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*You are required to complete below method */
// time: O(n), memory: O(n)
void pathCounts(Node *root)
{
    int max_h = INT_MIN;
    unordered_map<int, int> m;
    stack<pair<Node*, int>> s;
    s.push({root, 1});
    while(!s.empty()) {
        Node* u = s.top().first;
        int d = s.top().second;
        s.pop();
        if (u -> left == 0 && u -> right == 0) {
            m[d]++;
        }
        max_h = max(max_h, d);
        if (u -> right) {
            s.push({u -> right, d + 1});
        }
        if (u -> left) {
            s.push({u -> left, d + 1});
        }
    }
    int i = 1;
    while(i <= max_h) {
        if (m.find(i) != m.end()) {
            cout << i << " " << m[i] << " $";
        }
        i++;
    }
}
