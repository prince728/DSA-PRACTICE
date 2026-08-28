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
    int getSize(ListNode*head){
        ListNode*curr = head;
        int size=0;
        while(curr){
            curr=curr->next;
            size++;
        }
        return size;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int N = getSize(head);
        int sizeOfList = N / k;
        int greaterSize = N % k;
        
        vector<ListNode*> ans(k, nullptr);
        ListNode* curr = head;
        
        for (int i = 0; i < k; ++i) {
            if (!curr) break;
            
            ans[i] = curr;
            int currentPartSize = sizeOfList + (i < greaterSize ? 1 : 0);
            
            for (int j = 1; j < currentPartSize; ++j) {
                curr = curr->next;
            }
            
            ListNode* nextPartHead = curr->next;
            curr->next = nullptr;
            curr = nextPartHead;
        }
        
        return ans;

    }
};