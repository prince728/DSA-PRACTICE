class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string word = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                ans += word;
                ans+=" ";
                word = "";
            } else {
                word = s[i] + word;
            }
        }

        ans+=word;

        return ans;
    }
};