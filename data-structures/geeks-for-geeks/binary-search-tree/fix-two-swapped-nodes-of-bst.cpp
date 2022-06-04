// https://www.geeksforgeeks.org/fix-two-swapped-nodes-of-bst/

// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

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
    Node* root = new Node(stoi(ip[0]));

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

bool isBST(Node* n, int lower, int upper)
{
    if (!n) return true;
    if ( n->data <= lower || n->data >= upper ) return false;
    return (  isBST( n->left, lower, n->data )  &&  isBST( n->right, n->data, upper )  );
}

bool compare( Node* a, Node* b, vector<pair<int, int>> &mismatch )
{
    if ( !a && !b ) return true;
    if ( !a || !b ) return false;

    if ( a->data != b->data )
        mismatch.push_back( pair<int, int> (a->data, b->data) );

    return ( compare( a->left, b->left, mismatch ) && compare( a->right, b->right, mismatch ) );
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    // some testcases:
    // 1 N 52 5 62 4 26 2 66 58
    // 93 61 87 9
    // corner case: two nodes reside near each other: 16 1 55 8
    // corner case: one nodes is minimum and the other one is maximum: 87 61 9 93
    // time: O(n), memory: O(1)
    void correctBST(struct Node* root) {
        struct Node* curr = root;
        struct Node* u = 0;
        struct Node* v = 0;
        struct Node* prv = (struct Node*) malloc(sizeof(struct Node));
        prv -> data = INT_MIN;
        bool first = true;
        while(curr) {
            if (curr -> left) {
                Node* r = curr -> left;
                while(r -> right && r -> right != curr) {
                    r = r -> right;
                }
                if (r -> right) {
                    r -> right = 0;
                    // cout << curr -> data << endl;
                    if (curr -> data < prv -> data) {
                        if (first) {
                            u = prv;
                            first = false;
                        }
                        v = curr;
                    }
                    prv = curr;
                    curr = curr -> right;
                } else {
                    r -> right = curr;
                    curr = curr -> left;
                }
            } else {
                // cout << curr -> data << endl;
                if (curr -> data < prv -> data) {
                    if (first) {
                        u = prv;
                        first = false;
                    }
                    v = curr;
                }
                prv = curr;
                curr = curr -> right;
            }
        }
        // cout << endl;
        // if (u)
        //     cout << u -> data << endl;
        // if (v)
        //     cout << v -> data << endl;
        // return;
        int temp = u -> data;
        u -> data = v -> data;
        v -> data = temp;
        // curr = root;
        // while(curr) {
        //     if (curr -> left) {
        //         Node* r = curr -> left;
        //         while(r -> right && r -> right != curr) {
        //             r = r -> right;
        //         }
        //         if (r -> right) {
        //             r -> right = 0;
        //             cout << curr -> data << endl;
        //             prv = curr;
        //             curr = curr -> right;
        //         } else {
        //             r -> right = curr;
        //             curr = curr -> left;
        //         }
        //     } else {
        //         cout << curr -> data << endl;
        //         prv = curr;
        //         curr = curr -> right;
        //     }
        // }
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    getchar();

    while (t--)
    {
        string s;
        getline(cin, s);

        Node* root = buildTree(s);
        Node* duplicate = buildTree(s);

        Solution ob;
        ob.correctBST(root);

        // check 1: is tree now a BST
        if ( ! isBST(root, INT_MIN, INT_MAX) )
        {
            cout << "0\n";
            continue;
        }

        // check 2: comparing with duplicate tree

        vector<pair<int, int>> mismatch;
        // a vector to store data of mismatching nodes

        if ( ! compare( root, duplicate, mismatch) )
        {
            // false output from this function indicates change in structure of tree
            cout << "0\n";
            continue;
        }

        // finally, analysing the mismatching nodes
        if ( mismatch.size() != 2 || mismatch[0].first != mismatch[1].second || mismatch[0].second != mismatch[1].first )
            cout << "0\n";
        else cout << "1\n";
    }
    return 0;
}
// } Driver Code Ends
