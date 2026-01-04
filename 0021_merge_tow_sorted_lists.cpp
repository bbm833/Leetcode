/**
https://leetcode.com/problems/merge-two-sorted-lists/description/

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing
together the nodes of the first two lists.

Return the head of the merged linked list.

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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *new_head{nullptr};
    ListNode *current{nullptr};
    while (list1 != nullptr || list2 != nullptr) {
      ListNode *new_node{nullptr};
      if (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
          new_node = list1;
          list1 = list1->next;
        } else {
          new_node = list2;
          list2 = list2->next;
        }
      } else if (list1 != nullptr) {
        new_node = list1;
        list1 = list1->next;
      } else {
        new_node = list2;
        list2 = list2->next;
      }

      new_node->next = nullptr;
      if (new_head == nullptr) {
        new_head = new_node;
        current = new_head;
      } else {
        current->next = new_node;
        current = current->next;
      }
    }

    return new_head;
  }
};
