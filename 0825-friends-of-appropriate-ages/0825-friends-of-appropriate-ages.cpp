class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> count(121, 0);
        int ans=0;

        for (int i = 0; i < ages.size(); i++) {
            count[ages[i]]++;
        }

        for (int i = 1; i < 121; i++) {
            if (count[i] == 0)
                continue;

            for (int j = 1; j < 121; j++) {
                if(count[j]==0) continue;
                if (j <= 0.5 * i + 7 ||j > i) continue;

                if(i==j) ans+=count[i]*(count[i]-1);
                else ans+= count[i]*count[j];
            }
        }

        return ans;
    }
};