// https://www.geeksforgeeks.org/find-maximum-or-minimum-in-binary-tree/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
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
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

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
        if (currVal != "N")
        {

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
/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    int m_min = INT_MAX;
    int m_max = INT_MIN;

    int findMax(Node *root)
    {
        if (m_max == INT_MIN) {
            inorder(root);
        }
        return m_max;
    }
    int findMin(Node *root)
    {
        if (m_min == INT_MAX) {
            inorder(root);
        }
        return m_min;
    }

    // time: O(n), memory: O(1)
    void inorder(Node* curr) {
        int d_max = curr -> data;
        int d_min = curr -> data;

        while(curr) {
            if (curr -> left) {
                Node* r = curr -> left;
                while(r -> right && r -> right != curr) {
                    r = r -> right;
                }
                if (r -> right) {
                    r -> right = 0;
                    d_max = max(d_max, curr -> data);
                    d_min = min(d_min, curr -> data);
                    curr = curr -> right;
                } else {
                    r -> right = curr;
                    curr =  curr -> left;
                }
            } else {
                d_max = max(d_max, curr -> data);
                d_min = min(d_min, curr -> data);
                curr = curr -> right;
            }
        }
        m_max = d_max;
        m_min = d_min;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        int mx = obj.findMax(root);
        int mn = obj.findMin(root);
        cout << mx << " " << mn << "\n";
    }
    return 0;
}
// } Driver Code Ends
