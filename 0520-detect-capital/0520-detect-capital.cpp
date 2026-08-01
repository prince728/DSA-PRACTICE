class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for (char c : word) {
            if (c >= 'A' && c <= 'Z') count++;
        }
        if (count == word.size() || count == 0) return true;
        if (count == 1 && (word[0] >= 'A' && word[0] <= 'Z')) return true;
        
        return false;
    }
};
