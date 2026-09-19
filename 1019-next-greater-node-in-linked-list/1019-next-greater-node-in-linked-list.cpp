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
void createArray(ListNode*head,vector<int>&nums){
    while(head!=nullptr){
        nums.push_back(head->val);
        head=head->next;
    }
}
    vector<int> nextLargerNodes(ListNode* head) {
        if(!head) return vector<int>{};

        vector<int>nums;
        createArray(head,nums);

        stack<int>s;
        vector<int>ans(nums.size(),0);

        for(int i=0;i<nums.size();i++){
            while(!s.empty() && nums[s.top()]<nums[i]) {
                ans[s.top()]=nums[i];
                s.pop();
            }
            s.push(i);
        }

        return ans;

    }
};