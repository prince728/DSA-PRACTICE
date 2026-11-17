class Solution {
public:
    string findReplaceString(string s, vector<int>& indices,
                             vector<string>& sources, vector<string>& targets) {
        string ans = "";
        unordered_map<int, pair<int, string>> mp;

        for (int i = 0; i < indices.size(); i++) {
            int indx= indices[i];
            if(s.substr(indx,sources[i].size())==sources[i]){
                mp[indx]={sources[i].size(),targets[i]};
            }
        }

        for(int i=0;i<s.size();i++){
            if(mp.count(i)){
                ans+=mp[i].second;
                i+=mp[i].first-1;
            }
            else ans+=s[i];
        }

        return ans;
    }
};