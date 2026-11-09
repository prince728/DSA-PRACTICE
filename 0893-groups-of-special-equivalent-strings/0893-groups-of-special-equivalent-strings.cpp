class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> groups;

        for (const string& word : words) {
            string even, odd;
            for (int i = 0; i < word.size(); ++i) {
                (i % 2 == 0 ? even : odd).push_back(word[i]);
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            groups.insert(even + "#" + odd);
        }

        return groups.size();
    }
};