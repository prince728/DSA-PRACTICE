class Solution {
public:
    string maskPII(string s) {
        string ans = "";
        if (isalpha(s[0])) {
            int i = 0;
            ans += tolower(s[i]);
            ans += "*****";
            while (s[i + 1] != '@') {
                i++;
            }
            while (i < s.size()) {
                ans += tolower(s[i]);
                i++;
            }

        } else {
            int group = 0;
            for (int i = s.size() - 1; i >= 0; i--) {
                if (s[i] == '(' || s[i] == ')' || s[i] == ' ' || s[i] == '-')
                    continue;

                if (ans.size() < 4)
                    ans += s[i];
                else {
                    if (group == 0) {
                        group = 3;
                        ans += '-';
                    }
                    if (isdigit(s[i]))
                        ans += '*';
                    group--;
                    
                }
            }
            if(ans[ans.size()-1]=='-') ans.pop_back();
            if(ans.size()>12)ans+='+';
            reverse(ans.begin(), ans.end());
        }

        return ans;
    }
};