// https://www.geeksforgeeks.org/pairwise-swap-leaf-nodes-binary-tree/

// { Driver Code Starts
//Initial Template for C++

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
        return;
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
//User function Template for C++
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
    // time: O(n), memory: O(1)
    void pairwiseSwap(Node *root)
    {
        Node* curr = root;
        Node* prv = 0;
        while(curr) {
            if (curr -> left) {
                Node* r = curr -> left;
                while(r -> right && r -> right != curr) {
                    r = r -> right;
                }
                if (r -> right) {
                    r -> right = 0;
                    // cout << curr -> data << endl;
                    if (r -> left == 0) {
                        // cout << r -> data << endl;
                        if (prv) {
                            int temp = prv -> data;
                            prv -> data = r -> data;
                            r -> data = temp;
                            prv = 0;
                        } else {
                            prv = r;
                        }
                    }
                    curr = curr -> right;
                } else {
                    r -> right = curr;
                    curr = curr -> left;
                }
            } else {
                // cout << curr -> data << endl;
                if (curr -> right == 0) {
                    // cout << curr -> data << endl;
                    if (prv) {
                        int temp = prv -> data;
                        prv -> data = curr -> data;
                        curr -> data = temp;
                        prv = 0;
                    } else {
                        prv = curr;
                    }
                }
                curr = curr -> right;
            }
        }
    }
};

// { Driver Code Starts.

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
        obj.pairwiseSwap(root);
        printInorder(root);
        if (treeString.size() != 0)
            cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
