/*
 * [141] Linked List Cycle
 *
 * https://leetcode.com/problems/linked-list-cycle/description/
 *
 * algorithms
 * Easy (35.15%)
 * Total Accepted:    234.3K
 * Total Submissions: 666.7K
 * Testcase Example:  '[]\nno cycle'
 *
 * 
 * Given a linked list, determine if it has a cycle in it.
 * 
 * 
 * 
 * Follow up:
 * Can you solve it without using extra space?
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode;
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr)
        {
            return false;
        }
        ListNode *p1{head}, *p2{head};
        while (true)
        {
            if (p2->next != nullptr)
            {
                p2 = p2->next;
            }
            else
            {
                return false;
            }
            if (p2->next != nullptr)
            {
                p2 = p2->next;
            }
            else
            {
                return false;
            }
            p1 = p1->next;
            if (p2 == p1)
            {
                return true;
            }
        }
    }
};
