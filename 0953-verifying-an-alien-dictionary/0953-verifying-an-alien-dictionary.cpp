class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        for (int i = 0; i < order.size(); i++)
            mp[order[i]] = i + 1;

        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            int index = 0;

            while (index < word1.size() && index < word2.size()) {
                if (mp[word1[index]] == mp[word2[index]]) {
                    index++;
                    continue;
                } else if (mp[word1[index]] < mp[word2[index]])
                    break;
                else
                    return 0;
            }
            if (index == word2.size() && word1.size() > word2.size())
                return false;
        }

        return 1;
    }
};