// https://www.geeksforgeeks.org/check-binary-tree-subtree-another-binary-tree-set-2/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
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
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
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


// } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class A {
public:
    int data;
    A* next;
    A(int d) {
        data = d;
        next = 0;
    }
};

class Solution
{
public:
    // This doesn't work.
    bool isSubTree_2(Node* T, Node* S)
    {
        A* temp;
        A* in_t = inorder(T, temp);
        A* in_s = inorder(S, temp);
        // while(in_t) {
        //     std::cout << in_t -> data << " ";
        //     in_t = in_t -> next;
        // }
        // std:;cout << std::endl;
        // while(in_s) {
        //     std::cout << in_s -> data << " ";
        //     in_s = in_s -> next;
        // }
        // std::cout << std::endl;

        while(in_t && in_s) {
            if (in_t -> data == in_s -> data) {
                while(in_t && in_s && in_t -> data == in_s -> data) {
                    in_t = in_t -> next;
                    in_s = in_s -> next;
                }
                break;
            }
            in_t = in_t -> next;
        }

        return in_s == 0;
    }

    A* inorder(Node* root, A*& ret_tail) {
        if (root) {
            A* a = new A(root -> data);
            A* t;
            A* h;
            A* ret_h;
            h = inorder(root -> left, t);

            if (t) {
                ret_h = h;
                t -> next = a;
            } else {
                ret_h = a;
            }

            h = inorder(root -> right, t);

            if (t) {
                ret_tail = t;
                a -> next = h;
            } else {
                ret_tail = a;
            }

            return ret_h;
        } else {
            ret_tail = 0;
            return 0;
        }
    }

    // time: O(n), memory: O(n)
    void find(Node* T, int data, set<Node*> &s) {
        if (!T) {
            return;
        }
        if (T -> data == data) {
            s.insert(T);
        }
        find(T -> left, data, s);
        find(T -> right, data, s);
    }

    // time: O(n), memory: O(n)
    bool check(Node* T, Node* S) {
        if (S && T) {
            if (T -> data != S -> data) {
                return false;
            }
            return check(T -> left, S -> left) && check(T -> right, S -> right);
        } else if (T) {
            return false;
        } else if (S) {
            return false;
        } else {
            return true;
        }
    }

    // time: O(n*n), memory: O(n)
    bool isSubTree3(Node* T, Node* S) {
        set<Node*> s;
        find(T, S -> data, s);

        for(auto it = s.begin(); it != s.end(); it++) {
            Node* start = *it;
            if (check(start -> left, S -> left) && check(start -> right, S -> right)) {
                return true;
            }
        }

        return false;
    }

    void fill_inorder(Node* root, vector<int>& v) {
        if (!root) {
            v.push_back(-1);
            return;
        }
        fill_inorder(root -> left, v);
        v.push_back(root -> data);
        fill_inorder(root -> right, v);
    }

    void fill_preorder(Node* root, vector<int>& v) {
        if (!root) {
            v.push_back(-1);
            return;
        }
        v.push_back(root -> data);
        fill_preorder(root -> left, v);
        fill_preorder(root -> right, v);
    }

    bool is_subarray(vector<int> v1, vector<int> v2) {
        int n = v1.size();
        int m = v2.size();
        int i = 0, j, prv;
        while(i < n) {
            j = 0;
            prv = i;
            while(i < n && j < m && v1[i] == v2[j]) {
                i++;
                j++;
            }
            if (j == m) {
                return true;
            } else {
                i = prv;
            }
            i++;
        }
        return false;
    }

    bool isSubTree(Node* T, Node* S) {
        vector<int> v1;
        vector<int> v2;
        fill_inorder(T, v1);
        fill_inorder(S, v2);
        if (!is_subarray(v1, v2)) {
            return false;
        }
        v1.clear();
        v2.clear();
        fill_preorder(T, v1);
        fill_preorder(S, v2);
        // for(auto& it: v1)
        // cout << it << " ";
        // cout << endl << endl;
        // for(auto& it: v2)
        // cout << it << " ";
        // cout << endl;
        return is_subarray(v1, v2);
        // return includes(v1.begin(), v1.end(), v2.begin(), v2.end());
    }
};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string strT, strS;
        getline(cin, strT);
        Node *rootT = buildTree(strT);
        getline(cin, strS);
        Solution obj;
        Node *rootS = buildTree(strS);
        cout << obj.isSubTree(rootT, rootS) << "\n";

    }
    return 0;
}  // } Driver Code Ends
