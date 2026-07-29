class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";
        int i=0;
        while(s[i]==' ') i++;
        while(i < s.size()) {
            if (s[i] == ' ') {
                ans = temp + " " + ans;
                temp = "";
                while (i < s.size() && s[i] == ' ')
                    i++;
            }
            temp += s[i];
            i++;
        }
        if (s[s.size()-1]!=' ')
            ans = temp + " " + ans;
        ans.erase(ans.size() - 1);
        return ans;
    }
};