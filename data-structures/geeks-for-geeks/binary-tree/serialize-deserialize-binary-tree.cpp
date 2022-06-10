// https://www.geeksforgeeks.org/serialize-deserialize-binary-tree/

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

        // Get the current Node's value from the string
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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Data {
public:
    int in_low;
    int in_high;
    int pre_low;
    int pre_high;
    Node* par;
    bool is_left;
    Data(int in_l, int in_h, int pre_l, int pre_h, Node* p, bool is_l) {
        in_low = in_l;
        in_high = in_h;
        pre_low = pre_l;
        pre_high = pre_h;
        par = p;
        is_left = is_l;
    }
};

class Solution
{
public:
    // first approach:
    // store both inorder and preorder

    // time: O(n), memory: O(1)
    vector<int> serialize2(Node *root) {
        vector<int> v;
        Node* curr = root;
        // inorder
        while(curr) {
            if (curr -> left) {
                Node* r = curr -> left;
                while(r -> right && r -> right != curr) {
                    r = r -> right;
                }
                if (r -> right) {
                    r -> right = 0;
                    v.push_back(curr -> data);
                    curr = curr -> right;
                } else {
                    r -> right = curr;
                    curr = curr -> left;
                }
            } else {
                v.push_back(curr -> data);
                curr = curr -> right;
            }
        }
        v.push_back(INT_MAX);
        curr = root;
        // preorder
        while(curr) {
            if (curr -> left) {
                Node* r = curr -> left;
                while(r -> right && r -> right != curr) {
                    r = r -> right;
                }
                if (r -> right) {
                    r -> right = 0;
                    curr = curr -> right;
                } else {
                    r -> right = curr;
                    v.push_back(curr -> data);
                    curr = curr -> left;
                }
            } else {
                v.push_back(curr -> data);
                curr = curr -> right;
            }
        }
        // for(auto it: v) {
        //     cout << it << " ";
        // }
        // cout << endl;
        return v;
    }

    //Function to deserialize a list and construct the tree.
    // time: O(n), memory: O(logh)
    Node * deSerialize2(vector<int>& A) {
        unordered_map<int, int> m;
        int i = 0;
        while(i < A.size() && A[i] != INT_MAX) {
            m[A[i]] = i;
            i++;
        }
        stack<Data*> s;
        Node* fake = new Node(INT_MAX);
        Data* root_data = new Data(0, i - 1, i + 1, A.size() - 1, fake, true);
        s.push(root_data);
        while(!s.empty()) {
            Data* u = s.top();
            s.pop();
            if (u -> pre_low > u -> pre_high) {
                continue;
            }
            Node* child = new Node(A[u -> pre_low]);
            if (u -> is_left) {
                u -> par -> left = child;
            } else {
                u -> par -> right = child;
            }
            if (u -> pre_low == u -> pre_high) {
                continue;
            }
            int root_idx = m[A[u -> pre_low]];
            int mid = u -> pre_low + root_idx - u -> in_low;
            Data* left_data = new Data(u -> in_low, root_idx - 1, u -> pre_low + 1, mid, child, true);
            s.push(left_data);
            Data* right_data = new Data(root_idx + 1, u -> in_high, mid + 1, u -> pre_high, child, false);
            s.push(right_data);
        }
        return fake -> left;
    }

    // second approach:
    // preorder + store NULL as INT_MAX

    // time: O(n), memory: O(h)
    vector<int> serialize(Node *root) {
        vector<int> v;
        vector<Node*> s;
        Node* curr = root;
        while(curr) {
            v.push_back(curr -> data);
            s.push_back(curr -> right);
            curr = curr -> left;
            if (curr == 0) {
                v.push_back(INT_MAX);
                // cout << " - " << curr -> data <<  " " << s.back() << " "  << endl;
                while(!s.empty() && s.back() == 0) {
                    v.push_back(INT_MAX);
                    s.pop_back();
                }
                if (s.empty()) {
                    break;
                }
                curr = s.back();
                s.pop_back();
            }
        }
        // for(auto it: v) {
        //     cout << it << " ";
        // }
        // cout << endl;
        return v;
    }

    // time: O(n), memory: O(n)
    Node * deSerialize(vector<int>& A) {
        int i = 1;
        stack<pair<Node*, bool>> s;
        Node* root = new Node(A[0]);
        s.push(pair<Node*, bool> (root, false));
        s.push(pair<Node*, bool> (root, true));
        while(i < A.size()) {
            Node* par = s.top().first;
            bool left = s.top().second;
            s.pop();
            if (A[i] != INT_MAX) {
                Node* new_node = new Node(A[i]);
                if (left) {
                    par -> left = new_node;
                } else {
                    par -> right = new_node;
                }
                s.push(pair<Node*, bool> (new_node, false));
                s.push(pair<Node*, bool> (new_node, true));
            }
            i++;
        }
        return root;
    }
};

// { Driver Code Starts.

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void _deleteTree(Node* node)
{
    if (node == NULL) return;

    /* first delete both subtrees */
    _deleteTree(node->left);
    _deleteTree(node->right);

    /* then delete the node */
    //cout << "Deleting node: " << node->data << endl;
    delete node;
}

/* Deletes a tree and sets the root as NULL */
void deleteTree(Node** node_ref)
{
    _deleteTree(*node_ref);
    *node_ref = NULL;
}

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);

        Solution serial, deserial;
        vector<int> A = serial.serialize(root);
        deleteTree(&root);
        Node *getRoot = deserial.deSerialize(A);
        inorder(getRoot);
        cout << "\n";

    }


    return 0;
}  // } Driver Code Ends
