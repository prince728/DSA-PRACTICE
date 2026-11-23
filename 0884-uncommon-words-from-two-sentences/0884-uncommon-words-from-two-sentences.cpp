class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>mp;
        vector<string>ans;
        
        stringstream ss(s1);
        stringstream ss2(s2);
        string token;
        while(getline(ss,token,' ')){
            mp[token]++;
        }
        while(getline(ss2,token,' ')){
            mp[token]++;
        }


        for(auto& [key,val]:mp){
            if(val==1) ans.push_back(key);
        }

        return ans;
    }
};