// https://leetcode.com/problems/reverse-linked-list-ii/

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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) {
            return head;
        }

        ListNode* fake = 0;
        if (left == 1) {
            fake = new ListNode(0);
            fake -> next = head;
            left++;
            right++;
            head = fake;
        }

        right -= left;
        ListNode* u = head;
        while(left > 2) {
            left--;
            u = u -> next;
        }

        ListNode* v = u -> next;
        ListNode* backup_v = v;
        ListNode* prv = 0;
        ListNode* next;

        while(right >= 0) {
            next = v -> next;
            v -> next = prv;
            prv = v;
            v = next;
            right--;
        }

        backup_v -> next = v;
        u -> next = prv;

        if (fake) {
            return fake -> next;
        }
        return head;
    }
};
