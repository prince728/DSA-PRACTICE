class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<string ,int>mp;
        vector<string> code = {".-",   "-...", "-.-.", "-..",  ".",    "..-.",
                               "--.",  "....", "..",   ".---", "-.-",  ".-..",
                               "--",   "-.",   "---",  ".--.", "--.-", ".-.",
                               "...",  "-",    "..-",  "...-", ".--",  "-..-",
                               "-.--", "--.."};

        for (auto word : words) {
            string MorseCode = "";
            for (int i = 0; i < word.size(); i++) {
                MorseCode+=code[word[i]-'a'];
            }
            mp[MorseCode]++;
        }

        return mp.size();
    }
};