class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans(candies.size(),0);
        int largest=0;
        for(int i=0;i<candies.size();i++){
            largest = max(largest,candies[i]);
        }

        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=largest)
            ans[i]=1;
        }


        return ans;
    }
};