// https://www.geeksforgeeks.org/partitioning-a-linked-list-around-a-given-value-and-keeping-the-original-order/

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}

// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

// time: O(n), memory: O(1)
struct Node* partition(struct Node* head, int x) {
    struct Node* m_less = 0;
    struct Node* m_less_tail = 0;
    struct Node* m_equal = 0;
    struct Node* m_equal_tail = 0;
    struct Node* m_greater = 0;
    struct Node* m_greater_tail = 0;
    struct Node* u = head;
    while(u) {
        struct Node* t =  u -> next;
        u -> next = 0;
        if (u -> data < x) {
            if (m_less) {
                m_less_tail -> next = u;
                m_less_tail = u;
            } else {
                m_less = m_less_tail = u;
            }
        }  else if (u -> data == x) {
            if (m_equal) {
                m_equal_tail -> next = u;
                m_equal_tail = u;
            } else {
                m_equal = m_equal_tail = u;
            }
        } else {
            if (m_greater) {
                m_greater_tail -> next = u;
                m_greater_tail = u;
            } else {
                m_greater = m_greater_tail = u;
            }
        }
        u = t;
    }
    if (m_less) {
        if (m_equal) {
            m_less_tail -> next = m_equal;
            m_equal_tail -> next = m_greater;
        } else {
            m_less_tail -> next = m_greater;
        }
        return m_less;
    } else {
        if (m_equal) {
            m_equal_tail -> next = m_greater;
            return m_equal;
        } else {
            return m_greater;
        }
    }
}
