// https://www.geeksforgeeks.org/calculate-depth-full-binary-tree-preorder/

#include<bits/stdc++.h>

using namespace std;

// time: O(n), memory: O(n)
int main() {
    // string pre = "nlnnlll";
    string pre = "nlnnllnnnlnllnnlnll";
    int n = pre.length();
    stack<int> s;
    s.push(1);
    int d = 0, i = 0;
    while(!s.empty() && i < n) {
        int depth = s.top();
        d = max(d, depth);
        // cout << i << " " << pre[i] << " " << depth << endl;
        s.pop();
        if (pre[i] == 'n') {
            s.push(depth + 1);
            s.push(depth + 1);
        }
        i++;
    }
    cout << d << endl;
    return 0;
}
