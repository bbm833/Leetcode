/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list
and return its head.

*/
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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *first{head};
    ListNode *second{head};

    for (int i = 0; i < n && first != nullptr; ++i) {
      first = first->next;
    }

    if (first == nullptr) {
      auto temp = second;
      second = second->next;

      delete temp;
      return second;
    }

    while (first->next != nullptr) {
      first = first->next;

      second = second->next;
    }

    auto temp = second->next;
    second->next = second->next == nullptr ? nullptr : second->next->next;
    delete temp;

    return head;
  }
};
