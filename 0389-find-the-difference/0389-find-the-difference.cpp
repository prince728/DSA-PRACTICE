class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans = 0;
        
        for (char c : t) {
            ans+=c;
        }
        
     
        for (char c : s) {
            ans -= c;
        }
        
        return (char)ans;
    }
};
