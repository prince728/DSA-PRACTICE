class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int>ans;
        int sq =sqrt(area);

        int L=sq,W=sq;

        while(L>=W){
            if(L*W==area) {
                ans={L,W};
                return ans;
            }
            if(L*W<area)L++;
            else W--;
        }

        return {-1,-1};
    }
};