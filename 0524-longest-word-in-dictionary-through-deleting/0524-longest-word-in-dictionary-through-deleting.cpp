class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end());
        string ans = "";
        int n = s.size();
        for(auto it : d){
            int n1 = it.size();
            int  l = 0, r = 0;
            while(r < n){
                if(it[l] == s[r]){
                    l++;
                    if(l == n1){
                        if(ans.size() < l) ans = it;
                        break;
                    }
                }
                r++;
            }
        }
        return ans;
    }
};