/*
https://leetcode.com/problems/rotate-list/

Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
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
    ListNode* rotateRight(ListNode* head, int k) {

        ListNode* cursor{head};
        ListNode* new_head{head};

        // find size of linked list
        int n = 0;
        while(cursor != nullptr)
        {
            ++n;
            cursor = cursor->next;
        }

        if(n == 0)
            return nullptr;            

        k = k % n;

        if (k==0)
            return  head;
            
        cursor = head;
        int i{0};
        while(i<k && cursor->next != nullptr)
        {
            cursor = cursor->next;
            ++i;
            
        }

        while(cursor->next != nullptr)
        {
            cursor = cursor->next;
            new_head = new_head->next;            
        }

      
        ListNode* tmp = new_head;
        new_head = tmp->next;
        cursor->next = head;
        tmp->next = nullptr;

        return new_head;
    }
};
