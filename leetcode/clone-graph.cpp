// https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        Node* visited[101];
        memset(visited, 0, sizeof(visited));

        return cloneRec(node, visited);
    }

    Node* cloneRec(Node* node, Node* visited[]) {
        if (node == 0) {
            return 0;
        }

        int idx = node -> val;

        if (visited[idx] != 0) {
            return visited[idx];
        }

        visited[idx] = new Node(idx);

        for(auto& m: node -> neighbors) {
            (visited[idx] -> neighbors).push_back(cloneRec(m, visited));
        }

        return visited[idx];
    }
};
