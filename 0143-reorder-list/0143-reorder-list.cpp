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
    void reorderList(ListNode* head) {
        vector<int> nums;
        ListNode* curr = head;
        while (curr) {
            nums.push_back(curr->val);
            curr = curr->next;
        }

        int first = 0, second = nums.size() - 1;
        curr = head;
        while (first <= second) {
            curr->val = nums[first];
            if (first != second)
                curr->next->val = nums[second];
            if (nums.size() % 2 != 0 && second == nums.size() / 2)
                curr = curr->next;
            else
                curr = curr->next->next;

            first++;
            second--;
        }
    }
};