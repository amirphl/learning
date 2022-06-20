// https://www.geeksforgeeks.org/postfix-to-infix/

#include<bits/stdc++.h>

using namespace std;

// time: O(n), memory: O(n)
int main() {
    string postfix;
    cin >> postfix;
    stack<string> s;
    unordered_map<char, int> m;
    m['-'] = 1;
    m['+'] = 1;
    m['/'] = 2;
    m['*'] = 2;
    m['^'] = 3;
    int i = 0, n = postfix.length();
    while(i < n) {
        char ch = postfix[i];
        if (m.find(ch) == m.end()) {
            s.push(string(1, ch));
        } else {
            string o1 = s.top();
            s.pop();
            string o2 = s.top();
            s.pop();
            s.push("(" + o2 + ch + o1 + ")");
        }
        i++;
    }
    cout << s.top();
    cout << endl;
    return 0;
}
