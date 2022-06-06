// https://www.geeksforgeeks.org/avl-tree-set-1-insertion/

// { Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;

    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
    if(!n) return 1;
    if( n->data <= lower || n->data >= upper ) return 0;
    return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
    if(!n) return pair<int,bool> (0,1);

    pair<int,bool> l = isBalanced(n->left);
    pair<int,bool> r = isBalanced(n->right);

    if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

    return pair<int,bool> ( 1 + max(l.first, r.first), l.second && r.second );
}

bool isBalancedBST(Node* root)
{
    if( !isBST(root, INT_MIN, INT_MAX) )
        cout<< "BST voilated, inorder traversal : ";

    else if ( ! isBalanced(root).second )
        cout<< "Unbalanced BST, inorder traversal : ";

    else return 1;
    return 0;
}

void printInorder(Node* n)
{
    if(!n) return;
    printInorder(n->left);
    cout<< n->data << " ";
    printInorder(n->right);
}


// } Driver Code Ends
/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

class Solution {
public:
    /*You are required to complete this method */
    // 100
    // 84 -1 51 83 67 4 97 -8 77 27 25 15 26 49 38 87 64 44 65 86 1 37 -2 100 52 59 73 23 0 -7 54 58 92 91 48 99 96 57 79 6 70 90 19 53 32 18 8 50 10 3 -6 42 82 39 69 12 29 95 85 9 21 22 78 75 63 89 13 68 66 -5 56 94 20 72 71 76 36 2 41 93 5 81 74 98 11 31 -10 16 43 24 -4 -9 -3 55 62 14 30 61 46 60
    // 21
    // 84 -1 51 83 67 4 97 -8 77 27 25 15 26 49 38 87 64 44 65 86 1
    // 5
    // 5 1 3 2 1
    // time: O(logn), memory: O(logn)
    Node* insertToAVL(Node* root, int data)
    {
        if (!root) {
            return new Node(data);
        }
        // unordered_map<Node*, int> heights;
        // unordered_map<Node*, bool> bal;
        stack<Node*> s;
        stack<Node*> t;
        s.push(root);
        bool duplicate = insert(s, root, data);
        if (duplicate) {
            return root;
        }
        while(!s.empty()) {
            Node* z = s.top();
            s.pop();
            // is_balanced(z, heights, bal);
            int h_l = z -> left ? z -> left -> height : 0;
            int h_r = z -> right ? z -> right -> height : 0;
            // if (!bal[z]) {
            if (abs(h_l - h_r) > 1) {
                // cout << "un: " << z -> data << endl;
                Node* y = t.top();
                t.pop();
                Node* x = t.top();
                t.pop();
                Node* u = balance(z, y, x);
                // preorder(u);
                // cout << endl;
                if (z == root) {
                    root = u;
                } else {
                    Node* par = s.top();
                    s.pop();
                    if (par -> left == z) {
                        par -> left = u;
                    } else {
                        par -> right = u;
                    }
                    do {
                        par -> height = 1 + max(par -> right ? par -> right -> height : 0, par -> left ? par -> left -> height : 0);
                        par = 0;
                        if (!s.empty()) {
                            par = s.top();
                            s.pop();
                        }
                    } while(par);
                }
                break;
            } else {
                t.push(z);
            }
        }
        // cout << "all\n";
        // preorder(root);
        // cout << endl;
        // if (data == 87) {
        //     preorder(root);
        //     cout << endl;
        // }
        return root;
    }

    void preorder(Node* root) {
        if (!root) {
            return;
        }
        cout << root -> data << ":" << root -> height << " ";
        preorder(root -> left);
        preorder(root -> right);
    }

    // I forgot to change the heights!
    Node* balance(Node* z, Node* y, Node* x) {
        if (z -> left == y && y -> left == x) {
            z -> left = y -> right;
            z -> height = 1 + max(z -> right ? z -> right -> height : 0, z -> left ? z -> left -> height : 0);
            y -> left = x;
            y -> right = z;
            y -> height = 1 + max(x -> height, z -> height);
            return y;
        } else if (z -> right == y && y -> right == x) {
            z -> right = y -> left;
            z -> height = 1 + max(z -> right ? z -> right -> height : 0, z -> left ? z -> left -> height : 0);
            y -> left = z;
            y -> right = x;
            y -> height = 1 + max(x -> height, z -> height);
            return y;
        } else if (z -> right == y && y -> left == x) {
            z -> right = x -> left;
            z -> height = 1 + max(z -> right ? z -> right -> height : 0, z -> left ? z -> left -> height : 0);
            y -> left = x -> right; // I forgot this line!
            // I forgot this line!
            y -> height = 1 + max(y -> right ? y -> right -> height : 0, y -> left ? y -> left -> height : 0);
            x -> left = z;
            x -> right = y;
            x -> height = 1 + max(y -> height, z -> height);
            return x;
        } else {
            z -> left = x -> right;
            z -> height = 1 + max(z -> right ? z -> right -> height : 0, z -> left ? z -> left -> height : 0);
            y -> right = x -> left;  // I forgot this line!
            // I forgot this line!
            y -> height = 1 + max(y -> right ? y -> right -> height : 0, y -> left ? y -> left -> height : 0);
            x -> left = y;
            x -> right = z;
            x -> height = 1 + max(y -> height, z -> height);
            return x;
        }
    }

    // void is_balanced(Node* z, unordered_map<Node*, int>& heights, unordered_map<Node*, bool>& bal) {
    //     if (!z) {
    //         heights[z] = 0;
    //         bal[z] = true;
    //         return;
    //     }
    //     if (bal.find(z) != bal.end()) {
    //         return;
    //     }
    //     is_balanced(z -> left, heights, bal);
    //     is_balanced(z -> right, heights, bal);
    //     heights[z] = 1 + max(heights[z -> left], heights[z -> right]);
    //     bal[z] = bal[z -> left] && bal[z -> right] && abs(heights[z -> left] - heights[z -> right]) <= 1;
    // }

    // I forgot to change the heights!
    bool insert(stack<Node*>& s, Node* root, int data) {
        if (data == root -> data) {
            return true;
        } else if (data < root -> data) {
            if (root -> left == 0) {
                root -> left = new Node(data);
                s.push(root -> left);
                root -> height = max(root -> height, 2);
            } else {
                s.push(root -> left);
                bool duplicate = insert(s, root -> left, data);
                if (duplicate) {
                    return true;
                }
                if (root -> right) {
                    root -> height = 1 + max(root -> left -> height, root -> right -> height);
                } else {
                    root -> height = 1 + root -> left -> height;
                }
            }
        } else {
            if (root -> right == 0) {
                root -> right = new Node(data);
                s.push(root -> right);
                root -> height = max(root -> height, 2);
            } else {
                s.push(root -> right);
                bool duplicate = insert(s, root -> right, data);
                if (duplicate) {
                    return true;
                }
                if (root -> left) {
                    root -> height = 1 + max(root -> left -> height, root -> right -> height);
                } else {
                    root -> height = 1 + root -> right -> height;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main()
{
    int ip[MAXN];

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        for(int i=0; i<n; i++)
            cin>> ip[i];

        Node* root = NULL;
        Solution obj;
        for(int i=0; i<n; i++)
        {
            root = obj.insertToAVL( root, ip[i] );

            if ( ! isBalancedBST(root) )
                break;
        }

        printInorder(root);
        cout<< endl;
    }
    return 0;
}  // } Driver Code Ends
