// https://www.geeksforgeeks.org/find-pair-given-sum-bst/
// https://www.geeksforgeeks.org/find-a-pair-with-given-sum-in-bst/

// method 1: use unordered_set: time: O(n), memory: O(n)
// method 2: store inorder in auxiliary array: time: O(n), memory: O(n)
// method 3: convert BST to doubly linked list (in-place): time: O(n), memory: O(h)

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000
#define MAX_SIZE 100000

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
/*Complete the function below
Node is as follows
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

class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    // time: O(n), memory: O(h)
    int isPairPresent(struct Node *root, int target)
    {
        stack<Node*> u_s;
        stack<Node*> v_s;
        Node* u = root;
        Node* v = root;
        int u_proc = 0;
        int v_proc = 0;
        int left, right;
        left = next(u_s, u, u_proc, 1);
        right = next(v_s, v, v_proc, 0);
        while(u && v) {
            if (left + right < target) {
                left = next(u_s, u, u_proc, 1);
            } else if (left + right == target) {
                return 1;
            } else {
                right = next(v_s, v, v_proc, 0);
            }
        }
        return 0;
    }
    int next(stack<Node*>& s, Node*& u, int& proc, int dire) {
        int res;
        Node* v;
        Node* w;
        while(u) {
            if (dire) {
                v = u -> left;
                w = u -> right;
            } else {
                v = u -> right;
                w = u -> left;
            }
            if (v && !proc) {
                s.push(u);
                u = v;
                proc = 0;
            } else if (w) {
                res = u -> data;
                u = w;
                proc = 0;
                return res;
            } else {
                res = u -> data;
                u = 0;
                if (!s.empty()) {
                    u = s.top();
                    s.pop();
                    proc = 1;
                }
                return res;
            }
        }
        return INT_MIN;
    }
};

// { Driver Code Starts.
int main() {
    
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

       getline(cin, s);
       int k = stoi(s);
        //getline(cin, s);
       Solution obj;    
       cout << obj.isPairPresent(root, k) << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}
  // } Driver Code Ends
