class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size())
            return vector<int>{};
        if (s == p)
            return vector<int>{0};

        vector<int> ans;
        vector<int> count(26, 0);

        int wordSize = p.size();
        int  size = 0;

        for (int i = 0; i < wordSize; i++) {
            count[p[i] - 'a']++;
        }

        int left=0,right=0;
        int targetMatches = p.size();

        while(right<s.size()){
            if(count[s[right]-'a']>0) targetMatches--;

            count[s[right]-'a']--;
            right++;

            if(targetMatches==0) ans.push_back(left);

            if (right - left == p.size()) {
                if (count[s[left] - 'a'] >= 0) {
                    targetMatches++;
                }
                count[s[left] - 'a']++;
                left++;
            }
        }
        return ans;
    }
};