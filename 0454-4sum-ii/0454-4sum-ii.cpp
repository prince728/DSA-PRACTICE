class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {
        int n = nums1.size();
        int ans = 0;

        unordered_map<int,int> sum1;
        unordered_map<int,int> sum2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum = nums1[i] + nums2[j];
                sum1[sum]++;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum = nums3[i] + nums4[j];
                sum2[sum]++;
            }
        }

        for (auto [key, val] : sum1) {
            if (sum2[-key]!=0)
                ans+=val*sum2[-key];
        }

        return ans;
    }
};