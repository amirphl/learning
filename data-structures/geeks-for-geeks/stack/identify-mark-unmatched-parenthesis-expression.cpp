// https://www.geeksforgeeks.org/identify-mark-unmatched-parenthesis-expression/

#include<bits/stdc++.h>

using namespace std;

// time: O(n), memory: O(n)
int main() {
    // string in = "(((abc))((d)))))";
    string in = "((a)";
    stack<pair<char, int>> s;
    int i = 0, n = in.length();
    while(i < n) {
        if (in[i] == '(') {
            s.push({'(', i});
        } else if (in[i] == ')') {
            if (s.empty()) {
                in[i] = '3';
            } else {
                int loc = s.top().second;
                s.pop();
                in[loc] = '0';
                in[i] = '1';
            }
        }
        i++;
    }
    while(!s.empty()) {
        in[s.top().second] = '2';
        s.pop();
    }
    cout << in << endl;

    return 0;
}
