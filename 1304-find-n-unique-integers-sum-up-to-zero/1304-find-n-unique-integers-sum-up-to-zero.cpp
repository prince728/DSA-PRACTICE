class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        int elem = 1;
        if(n%2==1){
            ans.push_back(0);
            n--;
        }

        for(int i=0;i<n;i+=2){
           ans.push_back(elem); 
           ans.push_back(-elem); 
           elem++;
        }

        return ans;

    }
};