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
    int lengthOfList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int n = 0;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            n += 2;
        }

        if (fast)
            n++;

        return n;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int n = lengthOfList(head);

        if (n < k)
            return nullptr;

        int reverseK = n - k + 1;
        ListNode* curr = head;
        ListNode* first = nullptr;
        ListNode* second = nullptr;

        for (int i = 1; i <= max(k, reverseK); i++) {
            if (i == k)
                first = curr;
            if (i == reverseK)
                second = curr;
            curr = curr->next;
        }

        int value = second->val;
        second->val = first->val;
        first->val = value;

        return head;
    }
};