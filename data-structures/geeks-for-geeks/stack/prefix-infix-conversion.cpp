// https://www.geeksforgeeks.org/prefix-infix-conversion/

#include<bits/stdc++.h>

using namespace std;

// time: O(n), memory: O(n)
void convert(string& prefix, int& i, vector<char>& infix, unordered_map<char, int>& m) {
    if (i >= prefix.length()) {
        return;
    }

    char ch = prefix[i];
    i++;
    if (m.find(ch) == m.end()) {
        infix.push_back(ch);
    } else {
        infix.push_back('(');
        convert(prefix, i, infix, m);
        infix.push_back(ch);
        convert(prefix, i, infix, m);
        infix.push_back(')');
    }
}

int main() {
    // string prefix = "*+AB-CD";
    string prefix = "*-A/BC-/AKL";
    vector<char> infix;
    unordered_map<char, int> m;
    m['-'] = 1;
    m['+'] = 1;
    m['/'] = 2;
    m['*'] = 2;
    m['^'] = 3;

    int i = 0;
    convert(prefix, i, infix, m);
    for(auto& it: infix) {
        cout << it;
    }
    cout << endl;
    return 0;
}
