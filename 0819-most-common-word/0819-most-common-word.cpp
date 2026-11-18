class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for (char& c : paragraph) {
            if (isalpha(c)) {
                c = tolower(c);
            } else {
                c = ' ';
            }
        }
        unordered_map<string, int> mp;
        unordered_set<string> ban(banned.begin(), banned.end());
        stringstream ss(paragraph);
        string token;

        while (ss >> token) {
            mp[token]++;
        }

        string ans = "";
        int maxFreq = 0;

        for (const auto& [key, val] : mp) {
            if (!ban.count(key)&&val > maxFreq) {
                maxFreq = val;
                ans = key;
            }
        }

        return ans;
    }
};