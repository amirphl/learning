// https://www.geeksforgeeks.org/kth-largest-element-bst-using-constant-extra-space/
// https://www.geeksforgeeks.org/kth-largest-element-in-bst-when-modification-to-bst-is-not-allowed/

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
    Node* root = new Node(stoi(ip[0]));

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


// } Driver Code Ends
/*The Node structure is defined as
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

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
public:
    int kthLargest(Node *root, int K)
    {
        if (K <= 0) {
            return -1;
        }
        Node* head;
        Node* tail;
        convert_doubly_linked_list(root, head, tail);
        while(tail && K - 1 > 0) {
            // cout << tail -> data << " ";
            tail = tail -> left;
            K--;
        }
        if (tail)
            return tail -> data;
        return -1;
    }
    void convert_doubly_linked_list(Node* root, Node*& head, Node*& tail) {
        if (!root) {
            head = 0;
            tail = 0;
            return;
        }
        Node* h;
        Node* t;
        convert_doubly_linked_list(root -> left, h, t);
        if (h) {
            head = h;
            t -> right = root;
            root -> left = t;
            tail = root;
        } else {
            head = root;
            // root -> left = 0;
            tail = root;
        }
        convert_doubly_linked_list(root -> right, h, t);
        if (h) {
            tail -> right = h;
            h -> left = tail;
            tail = t;
        }
        tail -> right - 0;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();

    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);

        int k;
        cin>>k;
        getchar();

        Solution ob;
        cout << ob.kthLargest( head, k ) << endl;
    }
    return 1;
}  // } Driver Code Ends
