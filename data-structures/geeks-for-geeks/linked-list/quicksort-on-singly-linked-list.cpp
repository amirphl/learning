// https://www.geeksforgeeks.org/quicksort-on-singly-linked-list/

// { Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}// } Driver Code Ends


 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

struct meta {
    struct node* head;
    struct node* prv_pivot;
    struct node* tail;
};

struct meta* partition(struct node *head, struct node *end) {
    struct node* pivot = head;
    struct node* prv_pivot = (struct node*)malloc(sizeof(struct node));

    struct node* t = prv_pivot;
    prv_pivot -> next = pivot;
    prv_pivot -> data = -2147483647 - 1;

    struct node* prv = head;
    struct node* curr = head -> next;

    while(curr != end) {
        if (curr -> data < pivot -> data) {
            prv -> next = curr -> next;
            prv_pivot -> next = curr;
            curr -> next = pivot;
            prv_pivot = curr;
            curr = prv -> next;
        } else {
            prv = curr;
            curr = curr -> next;
        }
    }

    struct meta* m = (struct meta*)malloc(sizeof(struct meta));
    m -> head = t -> next;
    m -> prv_pivot = prv_pivot;
    m -> tail = prv;
    return m;
}

struct meta* quickSort(struct node *head, struct node *end) {
    struct meta* m;
    struct meta* k;
    if (head -> next == end) {
        m = (struct meta*)malloc(sizeof(struct meta));
        m -> head = head;
        m -> tail = head;
        return m;
    }

    /*
    struct node* o = head;
    std::cout<< "before partition: ";
    while(o) {
        std::cout << o -> data << " ";
        o = o -> next;
    }
    std::cout << std::endl;
    */
    m = partition(head, end);
    /*
    o = m -> head;
    std::cout<< "after partition: ";
    while(o) {
        std::cout << o -> data << " ";
        o = o -> next;
    }
    std::cout << std::endl;
    std::cout << "head:" << m -> head -> data << " - prv_pivot: " << m -> prv_pivot -> data << " - tail: " << m -> tail -> data;
    std::cout << std::endl;
    if (end)
        std::cout << "end: " << end -> data;
    else
        std::cout << "end: " << end;
    std::cout << std::endl;
    */

    if (m -> prv_pivot -> next == m -> head) {
        k = quickSort(m -> head -> next, m -> tail -> next);
        m -> head -> next = k -> head;
        m -> tail = k -> tail;
        return m;
    } else if (m -> prv_pivot -> next == m -> tail) {
        k = quickSort(m -> head, m -> tail);
        k -> tail -> next = m -> tail;
        k -> tail = m -> tail;
        return k;
    } else {
        // ************** This was also one of my mistakes:
        // `m -> prv_pivot -> next` is going to be changed after the first quick sort (quick sort on left half).
        struct node* temp = m -> prv_pivot -> next;
        struct meta* u = quickSort(m -> head, m -> prv_pivot -> next);
        struct meta* v = quickSort(temp, m -> tail -> next);
        // this line was my mistake!
        // struct meta* v = quickSort(m -> prv_pivot -> next -> next, m -> tail -> next);
        u -> tail -> next = v -> head;
        u -> tail = v -> tail;
        return u;
    }
}

// time: O(nlogn) || O(n*n), memory: O(1)
void quickSort(struct node **headRef) {
    struct meta* m = quickSort(*headRef, NULL);
    struct node* head = m ->head;
    (*headRef) = head;

    /*
    while(head) {
        std::cout << head -> data << "-";
        head = head -> next;
    }
    std::cout << std::endl;
    */
}
