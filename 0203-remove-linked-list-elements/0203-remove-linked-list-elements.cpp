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
    ListNode* removeElements(ListNode* head, int val) {

        while (head != nullptr && head->val == val) {
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
        }

        ListNode *temp = head, *prev = nullptr;
        while (temp) {
            if (temp->val == val) {
                prev->next = temp->next;
                ListNode* toDelete = temp;
                temp = temp->next;
                delete (toDelete);
            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};