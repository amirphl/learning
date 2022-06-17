// https://www.geeksforgeeks.org/reverse-sublist-linked-list/

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

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
public:
    // time: O(n), memory: O(1)
    Node* reverseBetween(Node* head, int m, int n)
    {
        if (n == m) {
            return head;
        }
        Node* dummy = new Node(-1);
        dummy -> next = head;
        Node* u = dummy;
        Node* prv = 0;
        Node* s = 0;
        Node* e = 0;
        int i = 0;
        while(i <= n) {
            if (i == m) {
                prv -> next = 0;
                s = u;
            }
            if (i == n) {
                e = u -> next;
                u -> next = 0;
                break;
            }
            if (i < m) {
                prv = u;
            }
            u = u -> next;
            i++;
        }
        Node* a = 0;
        Node* b = s;
        while(s) {
            Node* t = s -> next;
            s -> next = a;
            a = s;
            s = t;
        }
        prv -> next = a;
        b -> next = e;
        return dummy -> next;
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
        int N, m, n;
        cin >> N>>m>>n;

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

        Node* newhead = ob.reverseBetween(head, m, n);
        printList(newhead);

        cout << "\n";



    }
    return 0;
}
// } Driver Code Ends
