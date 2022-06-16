// https://practice.geeksforgeeks.org/problems/implement-stack-using-linked-list/1/?page=1&difficulty[]=-1&status[]=unsolved&category[]=Linked%20List&category[]=doubly-linked-list&category[]=circular-linked-list&category[]=circular%20linked%20list&sortBy=submissions

// { Driver Code Starts
//Initial Template for C
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}


// } Driver Code Ends
//User function Template for C

// // A structure to represent a stack
// struct Stack {
//     int top;
//     unsigned capacity;
//     int* array;
// };
// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, int item) {
    if (!isFull(stack)) {
        (stack -> array)[stack -> top + 1] = item;
        (stack -> top)++;
    }
}


// Function to remove an item from stack.  It decreases top by 1
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    (stack -> top)--;
    return (stack -> array)[stack -> top + 1];
}

// { Driver Code Starts.

// Function to return the top from stack without removing it
int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

// Driver program to test above functions
int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        struct Stack* stack = createStack(1000);

        int Q;
        scanf("%d",&Q);
        while (Q--) {
            int QueryType = 0;
            scanf("%d",&QueryType);
            if (QueryType == 1) {
                int a;
                scanf("%d",&a);
                push(stack, a);
            } else if (QueryType == 2) {
                printf("%d ", pop(stack));
            }
        }
        printf("\n");
    }
    return 0;
}
// } Driver Code Ends
