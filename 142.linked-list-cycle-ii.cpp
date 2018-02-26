/*
 * [142] Linked List Cycle II
 *
 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (30.71%)
 * Total Accepted:    139.4K
 * Total Submissions: 454K
 * Testcase Example:  '[]\nno cycle'
 *
 * 
 * Given a linked list, return the node where the cycle begins. If there is no
 * cycle, return null.
 * 
 * 
 * 
 * Note: Do not modify the linked list.
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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode *p1{head}, *p2{head};
        while (true)
        {
            if (p2 && p2->next)
            {
                p1 = p1->next;
                p2 = p2->next->next;
            }
            else
            {
                return nullptr;
            }
            if (p1 == p2)
            {
                break;
            }
        }
        p1 = head;
        while (p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};
