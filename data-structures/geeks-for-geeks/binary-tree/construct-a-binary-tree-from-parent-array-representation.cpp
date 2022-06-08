// https://www.geeksforgeeks.org/construct-a-binary-tree-from-parent-array-representation/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void sort_and_print(vector <int> &v)
{
    sort( v.begin(), v.end() );
    for( int i=0 ; i<v.size() ; i++ )
        cout<< v[i] << " ";
    v.clear();
}

void printLevelOrder(struct Node* root)
{
    vector <int> v;
    queue <Node*> q;

    q.push(root);

    Node* next_row = NULL;

    while(!q.empty())
    {
        Node* n = q.front();
        q.pop();

        if(n==next_row)
        {
            sort_and_print(v);
            next_row = NULL;
        }

        v.push_back(n->data);

        if(n->left)
        {
            q.push(n->left);
            if(next_row == NULL) next_row = n->left;
        }

        if(n->right)
        {
            q.push(n->right);
            if(next_row == NULL) next_row = n->right;
        }
    }
    sort_and_print(v);
}

Node *createTree(int parent[], int n);

/* Driver program to test above function*/


// } Driver Code Ends
/* node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
public:
    // time: O(n), memory: O(n)
    Node *createTree(int arr[], int n)
    {
        unordered_map<int, Node*> m;
        Node* v;
        Node* u;
        int i = 0, root_idx;
        while(i < n) {
            if (arr[i] == -1) {
                root_idx = i;
            }
            if (m.find(arr[i]) == m.end()) {
                v = new Node(arr[i]);
                m[arr[i]] = v;
            } else {
                v = m[arr[i]];
            }
            if (m.find(i) == m.end()) {
                u = new Node(i);
                m[i] = u;
            } else {
                u = m[i];
            }
            if (v -> left) {
                v -> right = u;
            } else {
                v -> left = u;
            }
            i++;
        }
        return m[root_idx];
    }

    // time: O(nlogn), memory: O(n)
    Node *createTree2(int arr[], int n)
    {
        multimap<int, int> m;
        int min_index = 0;

        for(int i = 0; i < n; i++) {
            if (arr[i] == -1) {
                min_index = i;
            }
            m.insert(pair<int, int> (arr[i], i));
        }

        Node* root = new Node(min_index);
        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            Node* f = q.front();
            q.pop();

            auto itr1 = m.lower_bound(f -> data);
            auto itr2 = m.upper_bound(f -> data);

            while (itr1 != itr2) {
                if (itr1 -> first == f -> data) {
                    Node* u = new Node(itr1 -> second);
                    q.push(u);
                    if (f -> left) {
                        f -> right = u;
                    } else {
                        f -> left = u;
                    }
                }
                itr1++;
            }
        }

        return root;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin>> n;
        int a[n];
        for( int i=0 ; i<n ; i++ )
            cin>> a[i];

        Solution ob;

        Node *res = ob.createTree(a,n);

        printLevelOrder(res);
        cout<<endl;
    }

    return 0;
}

// } Driver Code Ends
