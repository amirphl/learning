// https://www.geeksforgeeks.org/remove-occurrences-duplicates-sorted-linked-list/

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// } Driver Code Ends
//User function Template for C++

/* Linked List node structure

struct Node {
	int data;
	struct Node *next;
};

*/

class Solution
{
public:
    // time: O(n), memory: O(1)
    Node* removeAllDuplicates(struct Node* head)
    {
        Node* fake = new Node(10001);
        fake -> next = head;
        Node* u = fake;
        Node* prv = 0;
        while(u) {
            Node* v = u -> next;
            if (v) {
                int b = 0;
                while(v && v -> data == u -> data) {
                    Node* t = v -> next;
                    delete(v);
                    v = t;
                    b = 1;
                }
                if (b == 1) {
                    prv -> next = v;
                    delete(u);
                    u = v;
                } else {
                    prv = u;
                    u = v;
                }
            } else {
                break;
            }
        }
        return fake -> next;
    }
};

// { Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}



// Driver program to test above functions
int main()
{
    int T;
    cin >> T;


    while (T--)
    {
        int N;

        cin >> N ;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";


    }
    return 0;
}
// } Driver Code Ends
