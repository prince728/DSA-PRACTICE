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
    void skipNode(ListNode *&big,int n){
        for(int i=0;i<n;i++){
            big=big->next;
        }
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr1=headA;
        ListNode* curr2=headB;
        int num1=0,num2=0;

        while(curr1){
            num1++;
            curr1=curr1->next;
        }
        while(curr2){
            num2++;
            curr2=curr2->next;
        }

        if(num1>=num2) skipNode(headA,num1-num2);
        else skipNode(headB,num2-num1);

        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;


    }
};