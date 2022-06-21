// https://www.geeksforgeeks.org/check-if-stack-elements-are-pairwise-consecutive/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

bool pairWiseConsecutive(stack<int> s);

// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        stack<int> s;
        int n, tmp;
        cin>>n;
        while(n--) {
            cin>>tmp;
            s.push(tmp);
        }
        if (pairWiseConsecutive(s))cout << "Yes" << endl;
        else cout << "No" << endl;
        /*while (s.empty() == false)
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout<<endl;*/
    }
    return 0;
}
// } Driver Code Ends


//User function Template for C++

// your task is to complete the function
// function should return true/false or 1/0
// time: O(n), memory: O(1)
bool pairWiseConsecutive(stack<int> s)
{
    if (s.size() % 2 == 1) {
        s.pop();
    }
    while(!s.empty()) {
        int x = s.top();
        s.pop();
        int y = s.top();
        s.pop();
        if (abs(x - y) != 1) {
            return false;
        }
    }
    return true;
}
