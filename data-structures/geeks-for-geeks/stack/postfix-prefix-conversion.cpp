// https://www.geeksforgeeks.org/postfix-prefix-conversion/

#include<bits/stdc++.h>

using namespace std;

// time: O(n), memory: O(n)
int main() {
    // string postfix = "AB+CD-*";
    string postfix = "ABC/-AK/L-*";
    vector<char> prefix;
    stack<string> s;
    unordered_set<char> ch_set({'-', '+', '/', '*', '^'});
    int i = 0, n = postfix.length();

    while(i < n) {
        if (ch_set.find(postfix[i]) == ch_set.end()) {
            string o1(1, postfix[i]);
            s.push(o1);
        } else {
            string o1 = s.top();
            s.pop();
            string o2 = s.top();
            s.pop();
            s.push(postfix[i] + o2 + o1);
        }
        i++;
    }

    cout << s.top() << endl;
    return 0;
}
