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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode *prev = head, *cur = head->next;

        while (cur && prev->val <= cur->val) {
            prev = cur;
            cur = cur->next;
        }

        while (cur) {
            if (prev->val <= cur->val) {
                prev = cur;
                cur = cur->next;
                continue;
            }

            ListNode* p = dummy;
            while (p->next->val <= cur->val) {
                p = p->next;
            }
            prev->next = cur->next;
            cur->next = p->next;
            p->next = cur;
            cur = prev->next;
        }
        ListNode* sortedHead = dummy->next;
        delete dummy;
        return sortedHead;
    }
};