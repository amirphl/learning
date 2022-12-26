// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return 0;
        }

        queue<Node*> q;
        q.push(root);
        q.push(0);
        Node* prev = 0;

        while(q.size() > 1) {
            Node* curr = q.front();
            q.pop();

            if (prev) {
                prev -> next = curr;
            }
            prev = curr;

            if (!curr) {
                q.push(0);
                continue;
            }

            if (curr -> left)
                q.push(curr -> left);
            if (curr -> right)
                q.push(curr -> right);
        }

        return root;
    }
};
