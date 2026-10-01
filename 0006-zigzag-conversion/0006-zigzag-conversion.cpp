class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || numRows >= s.size()) {
            return s;
        }
        
        vector<string>Rowstr(numRows,"");
        int count=0,dir=1;

        for(int i=0;i<s.size();i++){
            Rowstr[count]+=s[i];
            if (count == 0) {
                dir = 1;
            } else if (count == numRows - 1) {
                dir = -1;
            }
            count+=dir;
        }

        string ans="";

        for(auto str: Rowstr){
            ans+=str;
        }

        return ans;
    }
};