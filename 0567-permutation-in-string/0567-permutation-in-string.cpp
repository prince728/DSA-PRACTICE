class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return 0;
        unordered_map<char, int> mp;

        for (int i = 0; i < s1.size(); i++) {
            mp[s1[i]]++;
        }

        int unique = mp.size();

        int right = 0;

        for (right = 0; right < s1.size(); right++) {
            mp[s2[right]]--;
            if (mp[s2[right]] == 0)
                unique--;
        }

        if (unique == 0)
            return 1;

        int left = 0;
        while (right < s2.size()) {
            mp[s2[right]]--;
            if (mp[s2[right]] == 0)
                unique--;
            mp[s2[left]]++;
            if (mp[s2[left]] ==1)
                unique++;

            if (unique == 0)
                return 1;

            right++;
            left++;
        }

        return 0;
    }
};