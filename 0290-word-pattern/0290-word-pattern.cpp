class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        string token;
        istringstream ss(s);
        int index = 0;

        while (getline(ss, token, ' ')) {
            if ((mp1.count(pattern[index]) && mp1[pattern[index]] != token) ||
                (mp2.count(token) && mp2[token] != pattern[index]))
                return 0;

            else {
                mp1[pattern[index]] = token;
                mp2[token] = pattern[index];
            }
            index++;
        }

        return index==pattern.size();
    }
};