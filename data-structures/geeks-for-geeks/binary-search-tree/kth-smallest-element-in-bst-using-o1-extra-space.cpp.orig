// https://www.geeksforgeeks.org/kth-smallest-element-in-bst-using-o1-extra-space/
// https://www.geeksforgeeks.org/find-k-th-smallest-element-in-bst-order-statistics-in-bst/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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
        if (i >= ip.size()) break;
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
/*Complete the function below

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // time: O(n), memory: O(1) (using Morris Traversal)
    int KthSmallestElement(Node *root, int K) {
        Node* curr = root;
        while(curr) {
            if (curr -> left == 0) {
                K--;
                if (K == 0) {
                    return curr -> data;
                }
                curr = curr -> right;
            } else {
                Node* r = curr -> left;
                while(r -> right != 0 && r -> right != curr) {
                    r = r -> right;
                }
                if (r -> right == 0) {
                    r -> right = curr;
                    curr = curr -> left;
                } else {
                    r -> right = 0;
                    K--;
                    if (K == 0) {
                        return curr -> data;
                    }
                    curr = curr -> right;
                }
            }
        }
        return -1;
    }
    // Return the Kth smallest element in the given BST
    int KthSmallestElement2(Node *root, int K) {
        int s;
        Node* res = KthSmallestElementRec(root, K, s);
        if (res) {
            return res -> data;
        }
        return -1;
    }
    // time: O(n), memory: O(n)
    Node* KthSmallestElementRec(Node *root, int K, int& size) {
        if (!root) {
            size = 0;
            return 0;
        }
        int s;
        Node* left = KthSmallestElementRec(root -> left, K, s);
        if (left) {
            return left;
        }
        if (s + 1 == K) {
            return root;
        }
        size = s + 1;
        Node* right = KthSmallestElementRec(root -> right, K - s - 1, s);
        if (right) {
            return right;
        }
        size += s;
        return 0;
    }
};

// { Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        getline(cin, s);
        int k = stoi(s);
        //  getline(cin, s);
        Solution obj;
        cout << obj.KthSmallestElement(root, k) << endl;
        // cout<<"~"<<endl;
    }
    return 0;
}  // } Driver Code Ends
