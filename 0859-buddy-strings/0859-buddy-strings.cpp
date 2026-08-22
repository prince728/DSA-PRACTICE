class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size())
            return 0;
        int n = s.size();

        if (s == goal) {
            vector<int> count(26, 0);
            for (char ch : s) {
                if (++count[ch - 'a'] > 1)
                    return true;
            }
            return false;
        }

        vector<int> diffIndices;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                diffIndices.push_back(i);
            }
        }

        return diffIndices.size() == 2 &&
               s[diffIndices[0]] == goal[diffIndices[1]] &&
               s[diffIndices[1]] == goal[diffIndices[0]];
    }
};