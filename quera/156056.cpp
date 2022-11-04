// https://quera.org/contest/assignments/45359/problems/156056

#include<bits/stdc++.h>

using namespace std;

int x_offset = 2e5;
int y_offset = 1e5;
vector<uint64_t> v(100000);
unordered_map<uint64_t, int> m;

void process_neighbor(queue<vector<int>> &q, int x, int y, int lvl, int &unique) {
    uint64_t neighbor = x;
    neighbor = neighbor << 32;
    neighbor += y;

    if (m.find(neighbor) != m.end()) {
        int val = m[neighbor];
        if (val == -1) {
            m[neighbor] = lvl;
            q.push({x, y, lvl});
            unique--;
        }
    } else {
        m[neighbor] = lvl;
        q.push({x, y, lvl});
    }
}

int main() {
    int i = 0, t, x, y;
    cin >> t;
    while(i < t) {
        x = y = 0;
        string s;
        cin >> s;
        for (auto& ch: s) {
            switch(ch) {
            case 'A':
                x++;
                x++;
                break;
            case 'B':
                x++;
                y++;
                break;
            case 'C':
                x--;
                y++;
                break;
            case 'D':
                x--;
                x--;
                break;
            case 'E':
                x--;
                y--;
                break;
            case 'F':
                x++;
                y--;
                break;
            default:
                cout << "panic\n";
                break;
            }
        }
        uint64_t loc = x + x_offset;
        loc = loc << 32;
        loc += (y + y_offset);
        m[loc] = -1;
        v[i] = loc;
        // cout << s << "  x: " << x << "  y: " << y << "  i: " << i << endl;
        i++;
    }

    int unique = m.size();
    queue<vector<int>> q;
    q.push({x_offset, y_offset, 0});
    uint64_t root = x_offset;
    root = root << 32;
    root += y_offset;

    if (m.find(root) != m.end()) {
        unique--;
    }
    m[root] = 0;

    while(!q.empty() && unique > 0) {
        x = q.front()[0];
        y = q.front()[1];
        int lvl = q.front()[2];

        // cout << x << " " << y << " " << lvl << endl;
        q.pop();

        process_neighbor(q, x + 2, y + 0, lvl + 1, unique);
        process_neighbor(q, x + 1, y + 1, lvl + 1, unique);
        process_neighbor(q, x - 1, y + 1, lvl + 1, unique);
        process_neighbor(q, x - 2, y + 0, lvl + 1, unique);
        process_neighbor(q, x - 1, y - 1, lvl + 1, unique);
        process_neighbor(q, x + 1, y - 1, lvl + 1, unique);
    }

    i = 0;
    while(i < t) {
        cout << m[v[i]] << "\n";
        i++;
    }

    return 0;
}
