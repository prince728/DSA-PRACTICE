/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *Next = node->next;
        while (Next->next) {
            int data = Next->val;
            node->val = data;
            node=node->next;
            Next =Next->next;
            
        }
        node->val=Next->val;
        node->next = nullptr;
        return;
    }
};