class Solution {
public:
    string largestEven(string s) {
        int lastIndex = -1;

        for (int i=0;i<s.size();i++){
            if(s[i]-'0'== 2) lastIndex=i;
        }

        if(lastIndex==-1) return "";
        return s.substr(0,lastIndex+1);
    }
};