// https://www.geeksforgeeks.org/reverse-tree-path/
// https://www.geeksforgeeks.org/reverse-path-bst-using-queue/

// This is a very important question.
// TODO(amirphl) Implement for graph.

#include<bits/stdc++.h>
#include<iostream>

// DFS. time: O(V + E), memory: O(V)
bool get_path(std::vector<std::vector<int>> &adj, std::deque<int> &path, int src, int dst) {
    // std::cout << "src: " << src << std::endl;
    path.push_front(src);
    if (src == dst)
        return true;
    for(int i = 0; i < adj[src].size(); i++)
        if(get_path(adj, path, adj[src][i], dst))
            return true;
    path.pop_front();
    return false;
}

int main() {
    int n = 28;
    int arr[n][n];
    std::memset(arr, 0, sizeof(arr));
    arr[0][1] = 1;
    arr[0][2] = 1;
    arr[0][3] = 1;
    arr[1][4] = 1;
    arr[1][5] = 1;
    arr[1][6] = 1;
    arr[1][7] = 1;
    arr[2][8] = 1;
    arr[2][9] = 1;
    arr[3][10] = 1;
    arr[4][11] = 1;
    arr[4][12] = 1;
    arr[7][13] = 1;
    arr[7][14] = 1;
    arr[9][15] = 1;
    arr[9][16] = 1;
    arr[14][17] = 1;
    arr[17][18] = 1;
    arr[18][19] = 1;
    arr[18][20] = 1;
    arr[20][21] = 1;
    arr[20][22] = 1;
    arr[20][23] = 1;
    arr[22][24] = 1;
    arr[24][25] = 1;
    arr[25][26] = 1;
    arr[25][27] = 1;

    std::vector<std::vector<int>> adj;

    for(int i = 0; i < n; i++) {
        std::vector<int> r;
        for(int j = 0; j < n; j++)
            if (arr[i][j] == 1)
                r.push_back(j);
        adj.push_back(r);
    }

    std::deque<int> path;
    int dst = 25;
    // source can be any node, not just the root.
    get_path(adj, path, 0, dst);

    if (path.empty()) {
        std::cout << "path not found" << std::endl;
        return 0;
    }

    // print path:
    std::cout << "path:" << std::endl;
    std::vector<int> t;
    while(!path.empty()) {
        std::cout << path.back() << " ";
        t.push_back(path.back());
        path.pop_back();
    }
    std::cout << std::endl;

    // reverse the path. time: O(V), memory: O(1)
    int i = 0, j = t.size() - 1;
    while(i < j) {
        int rear = t[i];
        int front = t[j];
        std::vector<int> v1 = adj[rear];
        std::vector<int> v2 = adj[front];
        adj[rear] = v2;
        adj[front] = v1;

        for(int k = 0; i > 0 && k < adj[t[i - 1]].size(); k++) {
            if (adj[t[i - 1]][k] == rear) {
                adj[t[i - 1]][k] = front;
                break;
            }
        }
        for(int k = 0; k < adj[t[j - 1]].size(); k++) {
            if (adj[t[j - 1]][k] == front) {
                adj[t[j - 1]][k] = rear;
                break;
            }
        }
        for(int k = 0; k < adj[front].size(); k++) {
            if (adj[front][k] == front) {
                adj[front][k] = rear;
                break;
            }
        }

        t[i] = front;
        t[j] = rear;

        i++;
        j--;
    }

    // print tree
    std::cout << "tree: " << std::endl;
    for(int i = 0; i < adj.size(); i++) {
        std::cout << i << ": ";
        for(int j = 0; j < adj[i].size(); j++)
            std::cout << adj[i][j] << " ";
        std::cout<< std::endl;
    }

    return 0;
}
