// https://www.geeksforgeeks.org/find-closest-element-binary-search-tree/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
    // time: O(n), memory: O(h)
    int minDiff(Node *root, int k)
    {
        stack<Node*> s;
        Node* u = root;
        int proc = 0;
        int res = root -> data;
        while(u && u -> data < k) {
            res = u -> data;
            u = u -> right;
        }
        while(u) {
            if (u -> left && !proc) {
                s.push(u);
                u = u -> left;
            } else if(u -> right) {
                if (abs(k - u -> data) < abs(k - res)) {
                    res = u -> data;
                }
                proc = 0;
                u = u -> right;
            } else {
                if (abs(k - u -> data) < abs(k - res)) {
                    res = u -> data;
                }
                u = 0;
                if (!s.empty()) {
                    u = s.top();
                    proc = 1;
                    s.pop();
                }
            }
        }
        return abs(res - k);
    }
};


// { Driver Code Starts.

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



int main() {
   
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       int k = stoi(s);
       // getline(cin, s);

        Solution ob;
       cout << ob.minDiff(root1, k);
        cout << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}
  // } Driver Code Ends
