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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto d = l1->val + l2->val;
        bool carry = false;
        if (d > 9)
        {
            carry = true;
            d -= 10;
        }
        ListNode *ans = new ListNode{d};
        ListNode *cur = ans;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 != nullptr || l2 != nullptr || carry)
        {
            d = 0;
            if (l1 != nullptr)
            {
                d += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                d += l2->val;
                l2 = l2->next;
            }
            if (carry)
            {
                d += 1;
                carry = false;
            }
            if (d > 9)
            {
                carry = true;
                d -= 10;
            }
            cur->next = new ListNode{d};
            cur = cur->next;
        }
         return ans;
    }
};