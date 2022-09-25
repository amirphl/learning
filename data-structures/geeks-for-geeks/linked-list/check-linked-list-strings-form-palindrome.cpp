// https://www.geeksforgeeks.org/check-linked-list-strings-form-palindrome/

//{ Driver Code Starts
//Code by Shubham Joshi
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string data;
    Node* next;

    Node(string x) {
        data = x;
        next = NULL;
    }
};

Node *newNode(string str)
{
    Node *new_node = new Node(str);
    new_node->next = NULL;
    return new_node;
}

bool compute(struct Node* root);

void print(Node *root)
{
    Node *temp = root;

    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

int main() {
    // your code goes here
    int T;
    cin>>T;
    while(T--)
    {
        int K;
        cin>>K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for(int i=0; i<K; i++) {
            string str="";
            cin>>str;
            if(head==NULL)
                head=temp=new Node(str);
            else
            {
                temp->next = new Node(str);
                temp=temp->next;
            }
        }
        if(compute(head))
            cout<<"True"<<endl;
        else
            cout<<"False"<<endl;
    }
    return 0;
}
// } Driver Code Ends


/*
The structure of linked list is the following
struct Node
{
    string data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
// time: O(n), memory: O(n)
bool compute(Node* root)
{
    int n = 0;
    stack<Node*> s;
    Node* u = root;
    while(u) {
        n += (u -> data).length();
        s.push(u);
        u = u -> next;
    }
    u = root;
    Node* v = s.top();
    s.pop();
    int i = 0, j = (v -> data).length() - 1, p = 0;
    while(p < n / 2) {
        if (i == (u -> data).length()) {
            u = u -> next;
            i = 0;
        }
        if (j == -1) {
            v = s.top();
            s.pop();
            j = (v -> data).length() - 1;
        }
        char frst = (u -> data)[i];
        char scnd = (v -> data)[j];
        // cout << frst << " _ " << scnd << " ";
        if (frst != scnd) {
            return false;
        }
        i++;
        j--;
        p++;
    }
    // cout << endl;
    return true;
}

