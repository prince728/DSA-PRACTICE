class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;

        unordered_map<char,int>charCount;

        for(int i=0;i<s.size();i++){
            if(!charCount.contains(s[i]))  charCount[s[i]]=1;
            else charCount[s[i]]++;
        }

        for(int j=0;j<t.size();j++){
            if(!charCount.contains(t[j])) return false;
            else{
                if(charCount[t[j]]==0) return false;
                else charCount[t[j]]--;
            }
        }

        return true;
    }
};