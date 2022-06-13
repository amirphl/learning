// https://www.geeksforgeeks.org/custom-tree-problem/

#include<bits/stdc++.h>

using namespace std;

// time: O(n), memory: O(n)
int main() {
    vector<vector<int>> tree = {
        {'a', 'b'},
        {'a', 'g'},
        {'b', 'c'},
        {'c', 'd'},
        {'d', 'e'},
        {'c', 'f'},
        {'z', 'y'},
        {'y', 'x'},
        {'x', 'w'}
    };
    unordered_map<int, vector<int>> m;
    unordered_set<int> u_set;
    int i = 0;
    while(i < tree.size())  {
        m[tree[i][0]].push_back(tree[i][1]);
        u_set.insert(tree[i][1]);
        i++;
    }
    for(auto& pa: m) {
        if (u_set.find(pa.first) != u_set.end()) {
            continue;
        }
        stack<vector<int>> s;
        s.push({pa.first, 0});
        while(!s.empty()) {
            int u = s.top()[0];
            int depth = s.top()[1];
            s.pop();
            int j = 0;
            while(j < depth) {
                if (depth % 3 == 2) {
                    cout << "|";
                } else {
                    cout << " ";
                }
                j++;
            }
            cout << "-->" << (char) u << endl;
            for(auto& child: m[u]) {
                s.push({child, depth + 3});
            }
        }
    }

    return 0;
}
