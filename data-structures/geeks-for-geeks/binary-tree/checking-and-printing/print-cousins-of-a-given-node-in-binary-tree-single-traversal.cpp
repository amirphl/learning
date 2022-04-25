// https://www.geeksforgeeks.org/print-cousins-of-a-given-node-in-binary-tree-single-traversal/
// https://www.geeksforgeeks.org/print-cousins-of-a-given-node-in-binary-tree/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
	int data;
	Node* left;
	Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

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
	Node* root = newNode(stoi(ip[0]));

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
			currNode->left = newNode(stoi(currVal));

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
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}

Node* pointer(Node* root, int n)
{
	if (root == NULL)
		return NULL;

	if (root->data == n)
		return root;

	Node* l = pointer(root->left, n);
	if (l != NULL && l->data == n)
		return l;

	Node* r = pointer(root->right, n);
	return r;

}


 // } Driver Code Ends
//User function Template for C++

/*
// A Binary Tree Node
struct Node
{
	int data;
	Node* left;
	Node* right;
};*/

class Solution
{
    public:
    // time: O(V), memory: O(V)
    vector<int> printCousins(Node* root, Node* node_to_find)
    {
        vector<int> vec;
        if (root == node_to_find) {
            vec.push_back(-1);
            return vec;
        }
        queue<Node*> q;
        q.push(root);
        q.push(0);
        int find = 0;
        Node* parent = 0;

        while(q.size() > 1) {
            Node* u = q.front();
            q.pop();
            if (u == 0) {
                q.push(0);
                if (find) {
                    break;
                } else {
                    vec.clear();
                }
                continue;
            }
            if (u == node_to_find) {
                find = 1;
            }
            if (parent) {
                if (parent -> left != u && parent -> right != u) {
                    vec.push_back(u -> data);
                }
            } else {
                vec.push_back(u -> data);
            }
            if (u -> left) {
                q.push(u -> left);
                if (u -> left == node_to_find) {
                    parent = u;
                }
            }
            if (u -> right) {
                q.push(u -> right);
                if (u -> right == node_to_find) {
                    parent = u;
                }
            }
        }
        if (vec.empty()) {
            vec.push_back(-1);
        }
        return vec;
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
		int n;
		cin >> n;
		getchar();

		string inp;
		getline(cin, inp);
		
		struct Node* root = buildTree(inp);

		Node* p = pointer(root, n);

        Solution ob;
		vector<int> ans = ob.printCousins(root, p);

		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";

		cout << "\n";


	}

	return 0;
}

  // } Driver Code Ends
