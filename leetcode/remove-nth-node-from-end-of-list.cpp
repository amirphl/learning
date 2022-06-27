// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // time: O(n), memory: O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* u = head;
        ListNode* prv = 0;
        ListNode* temp;
 
        while(u) {
            temp = u -> next;
            u -> next = prv;
            prv = u;
            u = temp;
        }

        head = prv;
        u = head;

        if (n > 1) {
            n -= 2;
            while(0 < n) {
                u = u -> next;
                n--;
            }

            temp = u -> next -> next;
            delete(u -> next);
            u -> next = temp;
        } else { // n == 1
            temp = head -> next;
            delete(head);
            head = temp;
        }

        u = head;
        prv = 0;
        while(u) {
            temp = u -> next;
            u -> next = prv;
            prv = u;
            u = temp;
        }

        return prv;
    }
};

int main() {
    return 0;
}
