class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int i=1;i<n;i++){
           string sub = s.substr(0,i);
           string compare ="";
           for(int i=0;i<n/sub.size();i++){
             compare +=sub;
           }
           if(compare==s) return 1;
        }
        return 0;
    }
};