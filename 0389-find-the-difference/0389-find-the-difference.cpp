class Solution {
public:
    char findTheDifference(string s, string t) {
       
        unordered_map<char,int>mp;
        
        for (char c : s) {
            mp[c-'a']++;
        }
        
     
        for (char c : t) {
           mp[c-'a']--;
           if(mp[c-'a']<0) return c;
        }
        
        return ' ';
    }
};
