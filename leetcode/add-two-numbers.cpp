// https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = l1;
        ListNode* prev = 0;

        if (l1 == 0) {
            return l2;
        }

        while(l1 || l2) {
            if (l1 && l2) {
                int sum = l1 -> val + l2 -> val + carry;
                if (sum > 9) {
                    carry = 1;
                    l1 -> val = sum - 10;
                } else {
                    l1 -> val = sum;
                    carry = 0;
                }
                prev = l1;
                l1 = l1 -> next;
                l2 = l2 -> next;
            } else if (l1) {
                int sum = l1 -> val + carry;
                if (sum > 9) {
                    carry = 1;
                    l1 -> val = sum - 10;
                } else {
                    l1 -> val = sum;
                    carry = 0;
                }
                prev = l1;
                l1 = l1 -> next;
            } else if (l2) {
                prev -> next = l2;
                l1 = l2;
                l2 = 0;
            } else {

            }
        }

        if (carry != 0) {
            ListNode* for_carry = new ListNode();
            for_carry -> val = carry;
            prev -> next = for_carry;
        }

        return head;
    }
};
