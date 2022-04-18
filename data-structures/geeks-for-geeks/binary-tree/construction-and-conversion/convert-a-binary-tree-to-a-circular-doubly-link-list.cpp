// https://www.geeksforgeeks.org/convert-a-binary-tree-to-a-circular-doubly-link-list/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
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



void displayCList(Node *head)
{
    Node *itr = head;
    do
    {
        cout << itr->data <<" ";
        itr = itr->right;
    } while (head!=itr);
    cout <<endl;
    itr=itr->left;
    do{
        cout<<itr->data<<" ";
        itr=itr->left;
    }while(head!=itr);
    cout<<itr->data<<endl;
}

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
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

  struct A {
      struct Node* head;
      struct Node* tail;
  
      A() {
          head = tail = 0;
      }
  };


class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
    Node *bTreeToCList(Node *root) {
          A* a = recur(root);
          a -> tail -> right = a -> head;
          a -> head -> left = a -> tail;
          return a -> head;
    }
  
      // time: O(V), memory: O(1)
      A* recur(Node* root) {
          if (!root) {
              return new A();
          }
          Node* head = root;
          Node* tail = root;
  
          if (root -> left) {
              A* a = recur(root -> left);
              a -> tail -> right = root;
              root -> left = a -> tail;
              head = a -> head;
          }
          if (root -> right) {
              A* a = recur(root -> right);
              a -> head -> left = root;
              root -> right = a -> head;
              tail = a -> tail;
          }
  
          A* new_a = new A();
          new_a -> head = head;
          new_a -> tail = tail;
  
          return new_a;
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
        Solution obj;
        Node *head = obj.bTreeToCList(root);
        displayCList(head);
    }
    return 0;
}







  // } Driver Code Ends
