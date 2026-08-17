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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());

        int ans = 0;
        ListNode* curr=head;
        while (curr) {
            if (set.count(curr->val)) {
                while (curr && set.count(curr->val)) {
                    curr = curr->next;
                }
                ans++;
            } else
                curr = curr->next;
        }

        return ans;
    }
};