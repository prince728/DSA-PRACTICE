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
    int getDecimalValue(ListNode* head) {
        vector<int>nums;
        ListNode* curr= head;
        while(curr){
            nums.push_back(curr->val);
            curr=curr->next;
        }

        int ans=0, mul=1;

        for(int i=nums.size()-1;i>=0;i--){
            ans+=nums[i]*mul;
            mul*=2;
        }

        return ans;
    }
};