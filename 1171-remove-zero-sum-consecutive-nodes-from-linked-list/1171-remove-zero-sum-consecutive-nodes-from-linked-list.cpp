class Solution {
public:
    void createArray(ListNode* head, vector<int>& nums) {
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
    }

    ListNode* createList(vector<int> nums) {
        if (nums.size() == 0) return nullptr;
        ListNode *head = new ListNode(0), *curr = head;
        for (int i = 0; i < nums.size(); i++) {
            curr->next = new ListNode(nums[i]);
            curr = curr->next;
        }
        return head->next;
    }

    ListNode* removeZeroSumSublists(ListNode* head) {
        if (!head) return head;
        
        vector<int> nums;
        createArray(head, nums);
        
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1; 
        
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            
            if (mp.count(sum)) {
                int startIdx = mp[sum];
                
                int currSum = sum;
                for (int i = startIdx + 1; i < right; i++) {
                    currSum += nums[i];
                    mp.erase(currSum);
                }

                nums.erase(nums.begin() + startIdx + 1, nums.begin() + right + 1);
                
                right = startIdx;
            } else {
                mp[sum] = right;
            }
        }
        
        return createList(nums);
    }
};
