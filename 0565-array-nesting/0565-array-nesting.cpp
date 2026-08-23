class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int max_length = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) continue; 
            
            int current_length = 0;
            int curr = i;
            
            while (nums[curr] >= 0) {
                int next_idx = nums[curr];
                
                nums[curr] = -1; 
                
                curr = next_idx;
                current_length++;
            }
            
            max_length = max(max_length, current_length);
        }
        
        return max_length;
    }
};
