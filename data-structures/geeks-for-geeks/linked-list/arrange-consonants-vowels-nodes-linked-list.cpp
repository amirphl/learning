// https://www.geeksforgeeks.org/arrange-consonants-vowels-nodes-linked-list/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }

};

void printlist(Node *head)
{
    if (head==NULL)return;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node** headRef, char data)
{
    struct Node* new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL)
    {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

// task is to complete this function
struct Node* arrange(Node *head);

int main()
{
    int T;
    cin>>T;
    while(T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--) {
            cin>>tmp;
            append(&head, tmp);
        }
        head = arrange(head);
        printlist(head);
    }
    return 0;
}


// } Driver Code Ends


/*
Structure of the node of the linked list is as
struct Node
{
	char data;
	struct Node *next;

	Node(int x){
	    data = x;
	    next = NULL;
	}

};
*/
// task is to complete this function
// function should return head to the list after making
// necessary arrangements
// time: O(n), memory: O(1)
struct Node* arrange(Node *head)
{
    struct Node* c = 0;
    struct Node* v = 0;
    struct Node* c_tail = 0;
    struct Node* v_tail = 0;
    while(head) {
        struct Node* t = head -> next;
        head -> next = 0;
        if (head -> data == 'a' || head -> data == 'e' || head -> data == 'o' || head -> data == 'u' || head -> data == 'i') {
            if (v) {
                v_tail -> next = head;
                v_tail = head;
            } else {
                v = v_tail = head;
            }
        } else {
            if (c) {
                c_tail -> next = head;
                c_tail = head;
            } else {
                c = c_tail = head;
            }
        }
        head = t;
    }
    if (v) {
        if (c) {
            v_tail -> next = c;
            return v;
        } else {
            return v;
        }
    } else {
        return c;
    }
}

