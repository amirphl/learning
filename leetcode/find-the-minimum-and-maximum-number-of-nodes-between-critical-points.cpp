// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
#include "bits/stdc++.h"
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  vector<int> nodesBetweenCriticalPoints(ListNode *head) {
    if (!head) {
      return {-1, -1};
    }
    ListNode *prev_prev = head;
    head = head->next;
    if (!head) {
      return {-1, -1};
    }
    ListNode *prev = head;
    head = head->next;
    if (!head) {
      return {-1, -1};
    }
    int dist = 0;
    ListNode *first = 0;
    int dist_first = -1;
    ListNode *last = 0;
    int dist_last = -1;
    int con_dist = INT_MAX;
    while (head) {
      if ((prev_prev->val < prev->val && prev->val > head->val) ||
          (prev_prev->val > prev->val && prev->val < head->val)) {
        if (!first) {
          first = prev;
          dist_first = dist;
        }
        if (last) {
          con_dist = min(con_dist, dist - dist_last);
        }
        last = prev;
        dist_last = dist;
      }
      prev_prev = prev;
      prev = head;
      head = head->next;
      dist++;
    }
    if (first == last || first == 0 || last == 0) {
      return {-1, -1};
    }
    return {con_dist, dist_last - dist_first};
  }
};
