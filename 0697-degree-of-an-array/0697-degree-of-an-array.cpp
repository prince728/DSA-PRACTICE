class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count;
        unordered_map<int, int> first_seen;
        int max_degree = 0;
        int min_len = 0;

        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            
            if (!first_seen.count(val)) {
                first_seen[val] = i;
            }
            
            count[val]++;

            if (count[val] > max_degree) {
                max_degree = count[val];
                min_len = i - first_seen[val] + 1;
            } 
            else if (count[val] == max_degree) {
                min_len = min(min_len, i - first_seen[val] + 1);
            }
        }

        return min_len;
    }
};
