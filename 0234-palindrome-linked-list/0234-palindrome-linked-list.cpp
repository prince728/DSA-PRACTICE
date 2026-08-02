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
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        vector<int> pal;
        while (curr) {
            pal.push_back(curr->val);
            curr= curr->next;
        }

        int start = 0, end = pal.size() - 1;

        while (start < end) {
            if(pal[start]!= pal[end]) return 0;
            start++;
            end--;
        }

        return 1;
    }
};