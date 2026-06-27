class Solution {
public:
    vector<int> compare(vector<int>&big,vector<int>&small){
        vector<int>ans;
        unordered_map<int,int>count;
        for(int i=0;i<small.size();i++){
            count[small[i]]++;
        }
        for(int i=0;i<big.size();i++){
            if(count.contains(big[i])&&count[big[i]]!=0){  
            ans.push_back(big[i]);
            count[big[i]]--;
            } 
        }
        return ans;
    }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<nums2.size()) return compare(nums2,nums1);
        else return compare(nums1,nums2);
    }
};