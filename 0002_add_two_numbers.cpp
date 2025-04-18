/*
https://leetcode.com/problems/add-two-numbers/description/

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result_root{nullptr};
        ListNode *current_node{nullptr};

        auto current_l1 = l1;
        auto current_l2 = l2;
        int carry{0};
        while(current_l1  || current_l2 )
        {
            int sum {carry};
            if(current_l1)
            {
                sum += current_l1->val;
                current_l1 = current_l1->next;
            }
            if(current_l2)
            {
                sum += current_l2->val;
                current_l2 = current_l2->next;
            }
            carry = 0;
            if(sum > 9)
            {
                sum = sum - 10;
                carry = 1;
            }
            ListNode* node = new ListNode{sum};
            if(current_node == nullptr)
            {
                result_root = current_node = node;
            }
            else
            {
                current_node->next = node;
                current_node = current_node->next;
            }
        }

        if(carry > 0)
        {
            ListNode* node = new ListNode{1};
            current_node->next = node;

        }
        return result_root;
    }
};
