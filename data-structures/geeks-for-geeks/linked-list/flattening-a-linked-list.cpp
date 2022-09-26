// https://www.geeksforgeeks.org/flattening-a-linked-list/

//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node {
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }

};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

    int t;
    cin>>t;
    while(t--) {
        int n,m,flag=1,flag1=1;
        struct Node * temp=NULL;
        struct Node * head=NULL;
        struct Node * pre=NULL;
        struct Node * tempB=NULL;
        struct Node * preB=NULL;
        cin>>n;
        int work[n];
        for(int i=0; i<n; i++)
            cin>>work[i];
        for(int i=0; i<n; i++) {
            m=work[i];
            --m;
            int data;
            scanf("%d",&data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;

            if(flag) {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else {
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for(int j=0; j<m; j++) {

                int temp_data;
                scanf("%d",&temp_data);
                tempB = new Node(temp_data);

                if(flag1) {
                    temp->bottom=tempB;
                    preB=tempB;
                    flag1=0;
                }
                else {
                    preB->bottom=tempB;
                    preB=tempB;
                }
            }
        }
        Node *fun = head;
        Node *fun2=head;

        Node* root = flatten(head);
        printList(root);
        cout<<endl;

    }
    return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;

	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}

};
*/

Node* insert(Node* head, Node* v) {
    if (v -> data <= head -> data) {
        v -> next = head;
        return v;
    }
    Node* u = head;
    while(u -> next) {
        if (u -> data <= v -> data && v -> data <= u -> next -> data) {
            Node* t = u -> next;
            u -> next = v;
            v -> next = t;
            return head;
        } else {
            u = u -> next;
        }
    }
    u -> next = v;
    v -> next = 0;
    return head;
}

Node* merge(Node* u, Node* v)
{
    Node* head = 0;
    Node* tail = 0;
    if (v -> data < u -> data) {
        head = tail = v;
        v = v -> next;
    } else {
        head = tail = u;
        u = u -> next;
    }
    while(u || v) {
        if (u && v) {
            if (u -> data < v -> data) {
                tail -> next = u;
                u = u -> next;
            } else {
                tail -> next = v;
                v = v -> next;
            }
            tail = tail -> next;
            tail -> next = 0;
        } else if (u) {
            tail -> next = u;
            break;
        } else if (v) {
            tail -> next = v;
            break;
        }
    }
    return head;
}

Node* flatten_rec(Node* root)
{
    Node* res = 0;
    if (root -> next && root -> bottom) {
        Node* nxt = flatten_rec(root -> next);
        Node* btm = flatten_rec(root -> bottom);
        Node* mrg = merge(nxt, btm);
        res = insert(mrg, root);
    } else if (root -> next) {
        Node* nxt = flatten_rec(root -> next);
        res = insert(nxt, root);
    } else if (root -> bottom) {
        Node* btm = flatten_rec(root -> bottom);
        res = insert(btm, root);
    } else {
        res = root;
    }
    // cout << root -> data << ": ";
    // Node* t = res;
    // while(t) {
    //     cout << t -> data << " ";
    //     t = t -> next;
    // }
    // cout << endl;
    return res;
}

Node* flatten(Node* root) {
    root = flatten_rec(root);
    Node* u = root;
    while(u) {
        u -> bottom = u -> next;
        u = u -> next;
    }
    return root;
}

