// https://www.geeksforgeeks.org/insertion-sort-for-singly-linked-list/

//{ Driver Code Starts
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
    // time: O(n*n), memory: O(1)
    Node* insertionSort(struct Node* head)
    {
        Node* h = head;
        Node* u = head;
        Node* v = head -> next;
        u -> next = 0;
        while(v) {
            Node* t = v -> next;
            v -> next = 0;
            if (v -> data <= h -> data) {
                v -> next = h;
                h = v;
            } else if (v -> data >= u -> data) {
                u -> next = v;
                u = v;
            } else {
                Node* w = h;
                do {
                    if (w -> data <= v -> data && v -> data <= w -> next -> data) {
                        v -> next = w -> next;
                        w -> next = v;
                        break;
                    }
                    w = w -> next;
                } while(w != u);
            }
            v = t;
        }
        return h;
    }

};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < n; i++) {
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

        head = ob.insertionSort(head);
        printList(head);

        cout << "\n";



    }
    return 0;
}
// } Driver Code Ends
