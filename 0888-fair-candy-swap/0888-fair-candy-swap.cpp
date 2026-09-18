class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int alice = 0, bob = 0;
        unordered_map<int,int>mp;
        for (int i = 0; i < aliceSizes.size(); i++)
            alice += aliceSizes[i];
        for (int i = 0; i < bobSizes.size(); i++){
            bob += bobSizes[i];
            mp[bobSizes[i]]++;
        }

        int diff= (alice-bob)/2;

       for (int i = 0; i < aliceSizes.size(); i++){
        int b = aliceSizes[i]-diff;
        if(mp.count(b)) return vector<int>{aliceSizes[i],b};
       }
       return vector<int>{-1,-1};
        
    }
};