// https://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/
// https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/
// https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/
// https://www.geeksforgeeks.org/create-customized-data-structure-evaluates-functions-o1/

// other idea: e * DUMMY_VALUE + MIN_SO_FAR
// e / DUMMY_VALUE
// e % DUMMY_VALUE
// push, pop, getMin: time: O(1)

// other idea: 2 * e - MIN_SO_FAR: push, pop, getMin: time: O(1)

// other idea: pair<e, MIN_SO_FAR>: push, pop, getMin: time: O(1)

// other idea: use two stacks: one for storing the actual elements and the othe one to store the MIN_SO_FAR. push, pop, getMin : time: O(1)

// { Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,a;
        cin>>n;
        while(!isEmpty(s)) {
            pop(s);
        }
        while(!isFull(s,n)) {
            cin>>a;
            push(s,a);
        }
        cout<<getMin(s)<<endl;
    }
}// } Driver Code Ends

int m = -1;

/////
// Every operation is O(1) (both time and memory) in this solution.
/////


void push(stack<int>& s, int a) {
    if (s.empty()) {
        s.push(a);
        m = a;
    } else {
        if (a < m) {
            s.push(-1 * m);
            m = a;
        } else {
            s.push(a - m);
        }
    }
}

bool isFull(stack<int>& s,int n) {
    return s.size() == n;
}

bool isEmpty(stack<int>& s) {
    return s.empty();
}

int pop(stack<int>& s) {
    if (s.empty()) {
        return -1;
    }
    int t = s.top();
    s.pop();
    if (s.size() == 0) {
        return t;
    }
    if (t >= 0)
        return t + m;
    int temp = m;
    m = -1 * t;
    // std::cout << "-> " << m << std::endl;
    return temp;
}

int getMin(stack<int>& s) {
    if (s.empty())
        return -1;
    return m;
}
