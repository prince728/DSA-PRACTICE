class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n= candyType.size();

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++)
            mp[candyType[i]]++;
        
        int unique_candy =mp.size();

        return min(unique_candy,n/2);
    }
};