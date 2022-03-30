// https://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/

// other idea: e * DUMMY_VALUE + MIN_SO_FAR
// e / DUMMY_VALUE
// e % DUMMY_VALUE

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
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
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


void push(stack<int>& s, int a){
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

bool isFull(stack<int>& s,int n){
	return s.size() == n;
}

bool isEmpty(stack<int>& s){
	return s.empty();
}

int pop(stack<int>& s){
	int t;
	if (s.empty())
        return -1;
    t = s.top();
    s.pop();
	if (s.size() == 0) {
	    return t;
	}
	if (t > 0)
	    return t + m;
	int temp = m;
	m = -1 * m;
	return temp;
}

int getMin(stack<int>& s){
	return m;
}
