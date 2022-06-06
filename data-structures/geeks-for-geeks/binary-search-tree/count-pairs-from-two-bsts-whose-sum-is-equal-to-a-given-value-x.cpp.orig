// https://www.geeksforgeeks.org/count-pairs-from-two-bsts-whose-sum-is-equal-to-a-given-value-x/

// TODO(amirphl) How to handle duplicates?

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

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

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

/*Structure of the Node of the BST is as
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
*/

class Solution
{
public:
    // time: O(n)
    // memory: O(h) // use Morris traversal to reduce it to O(1)
    int countPairs(Node* root1, Node* root2, int x)
    {
        stack<Node*> s_left;
        stack<Node*> s_right;
        Node* u_right = root1;
        Node* u_left = root2;
        bool proc_left = 0;
        bool proc_right = 0;
        int count = 0;
        Node* a = inorder(s_left, u_left, proc_left, 1);
        Node* b = inorder(s_right, u_right, proc_right, 0);
        while(a && b) {
            if ((a -> data) + (b -> data) < x) {
                a = inorder(s_left, u_left, proc_left, 1);
            } else if ((a -> data) + (b -> data) == x) {
                a = inorder(s_left, u_left, proc_left, 1);
                b = inorder(s_right, u_right, proc_right, 0);
                count++;
            } else {
                b = inorder(s_right, u_right, proc_right, 0);
            }
        }
        return count;
    }
    Node* inorder(stack<Node*>& s, Node*& u, bool& proc, int dir) {
        Node* v;
        Node* w;
        while(u) {
            if (dir == 1) {
                v = u -> left;
                w = u -> right;
            } else {
                v = u -> right;
                w = u -> left;
            }
            if (v && !proc) {
                s.push(u);
                u = v;
            } else if (w) {
                Node* temp = u;
                u = w;
                proc = false;
                return temp;
            } else {
                Node* temp = u;
                u = 0;
                if (!s.empty()) {
                    proc = true;
                    u = s.top();
                    s.pop();
                }
                return temp;
            }
        }
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string tree1, tree2;
        getline(cin, tree1);
        getline(cin, tree2);
        Node* root1 = buildTree(tree1);
        Node* root2 = buildTree(tree2);
        int x;
        cin >> x;
        cin.ignore();
        Solution ob;
        cout << ob.countPairs(root1, root2, x) << "\n";
    }
    return 0;
}
  // } Driver Code Ends
