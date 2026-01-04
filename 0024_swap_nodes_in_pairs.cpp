/**
https://leetcode.com/problems/swap-nodes-in-pairs/description/

Given a linked list, swap every two adjacent nodes and return its head. You must
solve the problem without modifying the values in the list's nodes (i.e., only
nodes themselves may be changed.)

Input: head = [1,2,3,4]

Output: [2,1,4,3]

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
  ListNode *swapPairs(ListNode *head) {

    if (head == nullptr)
      return head;

    auto first = head;
    auto second = first->next;
    ListNode *third = nullptr;

    std::once_flag head_swap;
    while (second != nullptr) {
      auto tmp = second->next;
      second->next = first;
      first->next = tmp;
      if (third != nullptr) {
        third->next = second;
      }
      call_once(head_swap, [&]() { head = second; });

      third = first;
      first = first->next;
      if (first == nullptr || first->next == nullptr)
        break;
      second = first->next;
    }

    return head;
  }
};
