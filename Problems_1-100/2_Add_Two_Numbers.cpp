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
        ListNode* dummy = new ListNode();
        ListNode* p = dummy;
        int flag = 0;
        while (l1 || l2) {
            int val = 0;
            if (l1) {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                val += l2->val;
                l2 = l2->next;
            }
            val = val + flag;
            flag = val / 10;
            val = val % 10;
            p->next = new ListNode(val);
            p = p->next;
        }
        if (flag) {
            p->next = new ListNode(1);
            p = p->next;
        }
        return dummy->next;
    }
};