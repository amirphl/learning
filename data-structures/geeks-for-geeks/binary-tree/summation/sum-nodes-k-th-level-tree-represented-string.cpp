// https://www.geeksforgeeks.org/sum-nodes-k-th-level-tree-represented-string/

#include<bits/stdc++.h>

using namespace std;

// time: O(V), memory: O(V)
void calc(string in, int k) {
    int i = 0, level = 0;
    stack<char> s;

    while (i < in.length()) {
        if (in[i] == '(') {
            s.push(in[i]);
        } else if (in[i] == ')') {
            if (s.top() != '(') {
                level--;
                s.pop();
            }

            s.pop();
        } else {
            s.push(in[i]);
            level++;

            if (level == k) {
                cout << in[i] << " ";
            }
        }
        i++;
    }
}

int main() {
    string in("(0(5(6()())(4(3(4()(9))())(9()())))(7(1()())(3()())))");
    int k = 3;
    cin >> k;

    calc(in, k);

	return 0;
}
