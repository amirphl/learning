// https://www.geeksforgeeks.org/find-largest-subtree-having-identical-left-and-right-subtrees/

#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    int data;
    Node(int d) {
        data = d;
        left = 0;
        right = 0;
    }
};

struct hashFunction
{
    size_t operator()(const vector<int>
                      &myVector) const
    {
        std::hash<int> hasher;
        size_t answer = 0;

        for (int i : myVector)
        {
            answer ^= hasher(i) + 0x9e3779b9 +
                      (answer << 6) + (answer >> 2);
        }
        return answer;
    }
};

void find(Node* root, unordered_set<vector<int>, hashFunction>& trees, vector<int>& largest, vector<int>& pre) {
    if (!root) {
        pre.push_back(-1);
        return;
    }
    vector<int> left_lar, right_lar, left_pre, right_pre;
    find(root -> left, trees, left_lar, left_pre);
    find(root -> right, trees, right_lar, right_pre);
    pre.push_back(root -> data);
    pre.insert(pre.end(), left_pre.begin(), left_pre.end());
    pre.insert(pre.end(), right_pre.begin(), right_pre.end());
    if (trees.find(pre) != trees.end()) {
        cout << "--- " << pre[0] << endl;
        largest = largest.size() > pre.size() ? largest : pre;
        for(auto& it: largest) {
            cout << it << " ";
        }
        cout << endl << "___" << endl;
    } else {
        trees.insert(pre);
        largest = left_lar.size() > right_lar.size() ? left_lar : right_lar;
    }
}

int main() {
    Node *root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);
    root -> left -> left -> left = new Node(8);
    root -> left -> left -> right = new Node(9);
    root -> left -> left -> right -> left = new Node(16);
    root -> left -> left -> right -> left -> left = new Node(10);
    root -> left -> left -> right -> left -> right = new Node(21);
    root -> left -> right -> left = new Node(9); // prv: 13

    // newly added
    root -> left -> right -> left -> left = new Node(16); // new
    root -> left -> right -> left -> left -> left = new Node(10); // new
    root -> left -> right -> left -> left -> right = new Node(21); // new

    root -> left -> right -> right = new Node(11);
    root -> left -> right -> right -> left = new Node(17);
    root -> left -> right -> right -> left -> right = new Node(0);
    root -> left -> right -> right -> right = new Node(18);
    root -> left -> right -> right -> right -> left = new Node(12);
    root -> right -> left -> left = new Node(14);
    root -> right -> left -> right = new Node(15);
    root -> right -> left -> right -> right = new Node(19);
    root -> right -> left -> right -> right -> right = new Node(20);
    root -> right -> right -> left = new Node(22);
    root -> right -> right -> right = new Node(23);

    unordered_set<vector<int>, hashFunction> trees;
    vector<int> largest, pre;
    find(root, trees, largest, pre);
    cout << "trees:" << endl;
    for(auto tr: trees) {
        for(auto elem: tr) {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << "___" << endl << "largest:" << endl;
    for(auto& elem: largest) {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}
