// https://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/
// https://www.geeksforgeeks.org/iterative-postorder-traversal/

// other approches:
// 1- 
// 2- 

#include<bits/stdc++.h>
#include<iostream>

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        bool processed;

        Node(int d) {
            data = d;
            left = right = 0;
            processed = false;
        }
};

// time: O(V), memory: O(V)
void postorder(Node* root) {
    std::stack<Node*> s;
    Node* curr = root;

    while(curr) {
        // std::cout << "-  " << curr -> data << std::endl;
        if (curr -> processed) {
            // std::cout << curr -> data << std::endl;
            std::cout << curr -> data << " ";

            if (!s.empty()) {
                curr = s.top();
                s.pop();
            } else {
                curr = 0;
            }
            continue;
        }

        curr -> processed = true;
        s.push(curr);

        Node* temp = curr;

        if (curr -> right) {
            s.push(curr -> right);
            temp = curr -> right;
        }
        if (curr -> left) {
            temp = curr -> left;
        }

        if (temp != curr) {
            curr = temp;
        } else {
            s.pop();
        }
    }
}


int main() {
    Node * n1 = new Node(1);
    Node * n2 = new Node(2);
    Node * n3 = new Node(3);
    Node * n4 = new Node(4);
    Node * n5 = new Node(5);
    Node * n6 = new Node(6);
    Node * n7 = new Node(7);
    Node * n8 = new Node(8);
    Node * n9 = new Node(9);
    Node * n10 = new Node(10);
    Node * n11 = new Node(11);
    Node * n12 = new Node(12);
    Node * n13 = new Node(13);
    Node * n14 = new Node(14);
    Node * n15 = new Node(15);

    n1 -> left  = n2;
    n1 -> right = n3;
    n2 -> left  = n4;
    n2 -> right = n5;
    n3 -> left  = n6;
    n3 -> right = n7;
    n4 -> left  = n8;
    n4 -> right = n9;
    n5 -> left  = n10;
    n5 -> right = n11;
    n6 -> left  = n12;
    n6 -> right = n13;
    n7 -> left  = n14;
    n7 -> right = n15;

    postorder(n1);

    return 0;
}
