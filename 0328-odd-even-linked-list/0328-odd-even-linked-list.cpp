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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *curr = head, *odd = new ListNode(1), *even =new ListNode(2);
        ListNode* evencurr=even;
        ListNode* oddcurr=odd;
        int count = 1;

        while (curr) {
            if (count % 2 == 0) {
                ListNode* temp=curr->next;
                evencurr->next =curr;
                curr->next=nullptr;
                evencurr= evencurr->next;
                curr=temp;
            }else{
                ListNode* temp=curr->next;
                oddcurr->next =curr;
                oddcurr =oddcurr->next;
                curr->next=nullptr;
                curr=temp;
            }
            count++;
        }
        ListNode* evenHead = even->next;
        delete even;
        oddcurr->next =evenHead;
        ListNode* newHead = odd->next;
        delete odd;
        return newHead;

    }
};