// https://www.geeksforgeeks.org/prefix-postfix-conversion/

#include<bits/stdc++.h>

using namespace std;

// time: O(n), memory: O(n)
int main() {
    // string prefix = "*+AB-CD";
    string prefix = "*-A/BC-/AKL";
    vector<char> postfix;
    stack<string> s;
    unordered_set<char> ch_set({'-', '+', '/', '*', '^'});
    int i = prefix.length() - 1;

    while(i >= 0) {
        if (ch_set.find(prefix[i]) == ch_set.end()) {
            string o1(1, prefix[i]);
            s.push(o1);
        } else {
            string o1 = s.top();
            s.pop();
            string o2 = s.top();
            s.pop();
            s.push(o1 + o2 + prefix[i]);
        }
        i--;
    }

    cout << s.top() << endl;
    return 0;
}
