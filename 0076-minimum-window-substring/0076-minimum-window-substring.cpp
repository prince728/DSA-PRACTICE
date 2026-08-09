class Solution {
public:
    string minWindow(string s, string t) {

        if(s.size()<t.size()) return "";

        unordered_map<char, int> mp;

        for (int i = 0; i < t.size(); i++)
            mp[t[i]]++;

        int len = INT_MAX;
        int total = t.size();
        int start = 0, end = 0;
        int begin = 0;

        while (end < s.size()) {
            mp[s[end]]--;
            if (mp[s[end]] >= 0)
                total--;

            while (total == 0 && start <= end) {
                if (len > end - start + 1){
                    len = end - start + 1;
                    begin=start;
                }
                mp[s[start]]++;
                if(mp[s[start]]>0) total++;

                start++;

            }
            end++;
        }

        return (len == INT_MAX) ? "" : s.substr(begin, len);
    }
};